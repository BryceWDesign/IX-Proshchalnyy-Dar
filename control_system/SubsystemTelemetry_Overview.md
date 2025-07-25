# Subsystem Telemetry & Alert Control System

> Subsystem: Central controller and alert logic  
> Role: Monitor all subsystems, alert for saturation, flow anomalies, and safety risks

---

## 🧠 MCU Role

A central **microcontroller** governs real-time status tracking for all system components:

- FIDA Beam Control
- UV Kill Reactor
- Ion Exchange Core
- Microbrush Capture System
- Flow Rate Monitoring
- Purity Output (TDS / Radiation Sensor)

**Recommended MCU:**  
- Arduino Nano 33 IoT (for wireless update potential and low power)
- STM32 Blue Pill (for robust IO-heavy configs)

---

## 🖥️ Data Inputs

| Sensor Type              | Signal Pin | Purpose                                 |
|--------------------------|------------|-----------------------------------------|
| Flow Rate Sensor         | A0         | Ensure stable throughput                |
| TDS / Conductivity       | A1         | Monitor purification quality            |
| Voltage Bias (Ion Layer) | A2         | Check for charge decay                  |
| Radiation Sensor         | A3         | Output zone radiation tracking          |
| Color Sensor (Brush)     | A4         | Detect fouling in microbrush mesh       |
| Internal Temp (CryoCore) | A5         | Prevent thermal breach warnings         |

---

## 🔔 Alert Outputs

| Alert Type                 | Trigger Threshold                            | Response                            |
|----------------------------|-----------------------------------------------|-------------------------------------|
| Low Flow                   | < 50 L/h for > 30 sec                         | Flash red LED, sound buzzer         |
| High TDS Output            | > 600 ppm                                    | Warning LED + display message       |
| Ion Bias Drop              | < 4.0V bias                                 | Recommend resin change              |
| Radiation Above Safe Zone  | > 0.3 µSv/h                                  | Full system shutdown (failsafe)     |
| Microbrush Saturated       | Color > 900 (white balance shift)            | Alert + mesh swap recommendation    |
| Overheat Detected          | Internal temp > 60°C (CryoCore breach)       | Trigger CryoCore fan loop           |

---

## 🧾 Sample Arduino Loop

```cpp
void loop() {
  int flow = analogRead(A0);
  int tds = analogRead(A1);
  float ion_bias = analogRead(A2);
  int radiation = analogRead(A3);
  int brush_color = analogRead(A4);
  float cryo_temp = analogRead(A5);

  if (flow < 50) { alert("LOW FLOW RATE"); }
  if (tds > 600) { alert("TDS HIGH – CHECK EXCHANGE RESINS"); }
  if (ion_bias < 4.0) { alert("RESIN BIAS LOW"); }
  if (radiation > 300) { alert("RADIATION ABOVE LIMIT – SHUTTING DOWN"); shutdown(); }
  if (brush_color > 900) { alert("BRUSH FOULING DETECTED"); }
  if (cryo_temp > 60) { activateCryoCoreCooling(); }

  delay(3000);
}
```

---

## 📟 Optional Display / Output

| Module            | Use                               |
|------------------|------------------------------------|
| I2C OLED (SSD1306) | Display purity, radiation, TDS     |
| RGB LED bar       | Visual status – green/orange/red |
| Passive buzzer    | Audible alert (critical faults)   |

---

## 🔋 Power Use

MCU + sensors consume < 250 mA at peak. Can run on:
- 5V via step-down from main solar/battery system
- Or independent Li-Ion pack for resilience

---

## 🧠 Future Extensions

- Wireless logging via MQTT
- Cloud push to environmental dashboard
- Remote reset / kill switch for edge operation

---

### Integration

This file integrates logic from:
- `uv_kill_reactor/DeepUV_ModuleSpecs.md`
- `ion_exchange/IonCapture_Logic.md`
- `capture_brush_system/MicroFilter_FluxPattern.md`

