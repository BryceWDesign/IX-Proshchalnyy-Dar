# Ambient Power Routing and Management Logic

> Subsystem: Primary energy input and self-powering logic  
> Role: Sustain system operations using local ambient energy sources — radiation, thermal gradient, solar, and residual decay fields.

---

## 🔌 Primary Input Sources

| Source Type          | Rated Input Range | Typical Output | Use Case Priority |
|----------------------|-------------------|----------------|-------------------|
| Radiation Harvesting | 0.2–2 µSv/h       | ~0.5–5W        | Contaminated air regions |
| Solar Panel (flex PV)| 5–18V @ 1–2A      | ~10–35W        | Sunlight zones / top-mounted |
| TEG (Thermo-Electric Generator) | ΔT > 40°C  | ~3–10W         | Near reactors, warm exhaust, sun-soil contrast |
| Backup LiFePO4 Pack  | 12V, 6Ah          | 72 Wh (6–8 hrs)| Failsafe operations only |

---

## 🔄 Routing Topology

Power inputs flow into an **MPPT-capable hybrid charge controller** and are prioritized based on availability and system demand:

```
           +------------------+
           | Radiation Harv.  |──────┐
           +------------------+     │
                                     ▼
           +------------------+    +------------------+
           | Solar PV Panel   |────► MPPT Charge Ctrl |───► Load Bus (5V / 12V rails)
           +------------------+    +------------------+
                                     ▲
           +------------------+     │
           | TEG Units (x2)   |─────┘
           +------------------+

                 │
                 ▼
           +------------------+
           | LiFePO4 12V Bank |
           +------------------+
```

---

## ⚡ Load Budget

| Subsystem               | Voltage | Max Draw | Avg Draw |
|-------------------------|---------|----------|----------|
| MCU + Sensors           | 5V      | 250 mA   | ~180 mA  |
| UV Kill Core            | 12V     | 2.5A     | ~1.8A    |
| FIDA Beam Actuation     | 12V     | 3.0A     | ~1.5A    |
| Ion Exchange Pulse Bias | 5V      | 500 mA   | ~300 mA  |
| Microbrush Motor        | 12V     | 1.2A     | ~800 mA  |
| CryoCore Fans (x2)      | 12V     | 1.6A     | ~1.0A    |

**Total Peak Load**: ~9A @ 12V = 108W  
**Typical Running Load**: ~65–70W

---

## 🔋 Charging Logic (Failsafe)

When ambient power drops below required minimums:

1. MCU enters **low-power telemetry-only mode**
2. All subsystems except radiation + flow sensors pause
3. CryoCore fans enter burst-cooldown loop (pulsed 10 sec/min)
4. Battery backup kicks in once PV and rad inputs fall below 4W sustained

---

## 🌐 Output Protection

- **Overvoltage Protection**: TVS diodes @ 14V max
- **Undervoltage Lockout**: System disconnects below 10.8V
- **Reverse Polarity Protection**: MOSFET-based bridge
- **Thermal Protection**: MPPT throttles above 70°C internal

---

## 🧠 Smart Load Shedding Order

If power depletes rapidly, loads shut off in this sequence:

1. FIDA Beam  
2. CryoCore  
3. UV Kill  
4. Brush Rotor  
5. Ion Bias  
6. MCU (last)

---

## 📦 Recommended MPPT Controller

| Model                   | Specs                       | Source |
|-------------------------|-----------------------------|--------|
| Victron SmartSolar 75/15| 75V input, 15A output       | [Victron](https://www.victronenergy.com/solar-charge-controllers) |
| EPEver Tracer 2210AN    | Dual PV + load management   | [EPEver](https://www.epsolarpv.com/) |

---

## 🧬 Integration Points

This file links directly to:
- `control_system/SubsystemTelemetry_Overview.md`
- `uv_kill_reactor/DeepUV_ModuleSpecs.md`
- `fida_beam_array/FIDA_ControlLogic.md`

Ambient power availability **also drives** logic routines in MCU for mode switching and safety.
