# IX-Proshchalnyy-Dar Control System Overview  
> Subsystem: Real-time telemetry coordination, failsafe triggers, and module synchronization

---

## 🧠 Purpose

This file outlines the **central command system** that governs the real-time behavior of all subsystems:
- Sensor fusion and status logic
- Telemetry uplink (local and optional remote)
- Failover state coordination
- Energy budget orchestration
- Module-to-module communications

This is the **centralized brain** of the IX-Proshchalnyy-Dar platform.

---

## 🖥️ Core Controller

**Microcontroller:** STM32H7 (preferred) or RP2040 (alternate, lower precision)

### Minimum Specs:
- Dual-core 480MHz processor  
- 2MB Flash / 1MB SRAM  
- 12 ADC channels (0–3.3V)  
- 4 UARTs  
- 2 I²C buses  
- 1 CAN bus for rugged modular ops  
- Real-time clock (RTC) with backup cell

---

## 🛰️ Communication Map

### Module Interlinks:

| Module                          | Protocol  | Poll Frequency | Timeout Action       |
|----------------------------------|-----------|----------------|----------------------|
| UV Kill Reactor                  | I²C       | 500ms          | Pulse shutoff        |
| Ion Exchange Matrix              | I²C       | 750ms          | Lock solenoid valve  |
| FIDA Beam Array                  | UART      | 250ms          | Beam divergence fail |
| Microfiber Brush Filter          | GPIO      | On rotation tick | Stall detect        |
| Plasma Vaporizer                | CAN       | 1s             | Cooldown trigger     |
| Clean Output Validation System   | UART      | 2s             | Auto divert output   |
| Ambient Power Subsystem         | I²C       | 1.5s           | Failover to battery  |

---

## 📟 Data Telemetry Uplink

- Local USB flash logging (CSV + binary)
- Optional LoRa uplink (433MHz / 868MHz)
- Wi-Fi module (ESP32) optional for urban deployments
- BLE for handheld maintenance readouts

> Data format standard: JSON+timestamp, encrypted if uplink enabled

---

## 🛑 Failsafe Engine

All subsystems can be interrupted mid-cycle if conditions are breached.

**Examples:**
- UV overheat → shuts down light module
- Turbidity sensor red zone → isolates water into bin
- Voltage drop under TEG/ambient→ reroutes beam usage
- Filter rotation fault → triggers beam pause + acoustic alert

All triggered conditions are recorded in `/logs/telemetry_events.log` with UTC timestamp and fail reason.

---

## 🧬 Interlink Ping Logic

Each module sends a “HEARTBEAT” ping:
- ✅ = module online and stable
- ⚠️ = warning flag (running within limit, but marginal)
- ❌ = critical fail or timeout, triggers global alert

The controller aggregates all responses every 4s into:
- Live status display (if screen present)
- Color LED ring (Green / Yellow / Red logic)

---

## 🧾 Example Status Output

```json
{
  "time": "2025-07-25T23:41:00Z",
  "uv_kill_reactor": "✅",
  "ion_exchange": "✅",
  "fida_beam_array": "⚠️",
  "brush_filter": "✅",
  "plasma_vaporizer": "✅",
  "output_validation": "✅",
  "power_system": "✅"
}
```

---

## 🔐 Maintenance Override Logic

- Manual override via 5-digit code from secure NFC tag
- Diagnostic port allows selective module reboots
- “SAFE MODE” disables all beam or UV components for human intervention

---

## 🔋 Energy Budget Coordination

Based on available ambient harvest:
- Priority goes to output water validation, UV kill loop, and ion lattice
- FIDA beam pulses only allowed when all other modules are stable
- CryoCore thermal dump uses reclaimed heat mapped via temp sensors

> The controller intelligently balances limited energy to sustain mission-critical modules.

---

## 💡 Expandability

- Additional sensors can be added via I²C chain  
- Modular software allows adding external pump, alarm horn, GSM beacon, or cloud sync  
- GPIO pins exposed for experimental subsystems (ex: AI smell sensor, sonar scan)

---

## Final Notes

This telemetry brain:
- Never guesses  
- Never trusts default readings  
- Always reroutes to safety if water quality or radiation thresholds are exceeded

> This is not just logging — it’s full system control built on hard logic.  
> No PR compliance. Just facts and instant action.
