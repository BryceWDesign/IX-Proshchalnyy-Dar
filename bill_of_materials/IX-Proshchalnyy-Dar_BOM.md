# Bill of Materials (BOM)  
**IX-Proshchalnyy-Dar** — Full System Components  
_Last updated: July 2025_

| Item No. | Component Name                             | Spec / Description                                                       | Qty  | Source / Notes                                                  |
|----------|---------------------------------------------|--------------------------------------------------------------------------|------|------------------------------------------------------------------|
| 1        | UV-C LED Module                             | 265nm, 10W, waterproofed, high flux                                       | 4    | Digikey or LEDSupply                                             |
| 2        | CryoCore Cooling Coil                       | Copper spiral tubing + thermally conductive fluid loop                   | 1    | Custom build or sourced from CPU liquid cooling parts           |
| 3        | Microfiber Filter Discs                     | 200mm diameter, anti-snag, high-surface microfiber                       | 8    | 3D printed holder + commercial brush core                        |
| 4        | Motor - Brush Drive                         | 12V DC, torque limiter, 30 RPM                                           | 1    | Pololu, Jameco, or gearmotor vendor                             |
| 5        | STM32 or RP2040 MCU                         | Central telemetry + control unit                                         | 1    | Waveshare, Raspberry Pi Pico W                                  |
| 6        | Ion Exchange Resin                          | PFAS-specific mixed bed resin, refillable                                | 500g | Purolite PFA694 or equivalent                                   |
| 7        | Fractal Beam Lasers                         | 905nm pulsed laser diodes, lens-mountable                               | 6    | Edmund Optics or AliExpress (for DIY)                           |
| 8        | Horus Lens Array                            | Sacred geometry lens grid (3D printable + glass insert)                  | 1    | Custom — use printable STL + acrylic circle lenses               |
| 9        | Titanium Vapor Chamber Shell                | Induction-compatible reaction housing                                    | 1    | Titanium or Inconel tube, 150mm dia, 300mm length               |
| 10       | Induction Coil Generator                    | 120W pulse-based, modulated                                              | 1    | DIY Tesla coil driver or induction heater module                |
| 11       | Ambient Energy Harvester                    | Piezo, vibration, or TEG module                                          | 3    | TEG SP1848 or piezo stack modules                               |
| 12       | Supercapacitor Bank                         | ≥50 Farads, 2.7V series-stacked                                          | 1    | Maxwell, Nesscap, or DIY build                                  |
| 13       | Waterproof Housing (Main Shell)             | Marine-grade aluminum or recycled HDPE panel                            | 1    | CNC’d or custom molded                                          |
| 14       | PTFE Seal Rings                             | O-ring style, chemically inert                                           | 10   | McMaster-Carr                                                   |
| 15       | Sensors (flow, pH, turbidity, radiation)    | I²C-compatible sensor array                                              | 1 set| DFROBOT, Adafruit, or SparkFun                                  |
| 16       | Carbon Mesh Exhaust Filter                  | Plasma vapor output capture medium                                       | 1    | Sourced from filtration supplier                                |
| 17       | EPDM Rubber Intake + Output Tubes           | Flexible, UV + chemical resistant                                       | 2m   | Home Depot, ULINE, or water systems vendor                      |
| 18       | Solar Panel (optional)                      | 12V, foldable or rigid, 10–50W                                           | 1    | Renogy or GoalZero                                              |
| 19       | TDS and Conductivity Sensor                 | Water purity check                                                      | 1    | Atlas Scientific or DFROBOT                                     |
| 20       | Filter Cage Assembly                        | Multi-layer cage with sub-micron mesh                                    | 2    | 3D printed + mesh layering kit                                  |
| 21       | Watchdog + Fuse Board                       | 3A polyfuse x 3, hard shutoff logic                                      | 1    | DIY or Waveshare add-on                                        |
| 22       | BLE / LoRa Telemetry Module (optional)      | Remote broadcast of water quality data                                  | 1    | Heltec or Adafruit                                              |
| 23       | Lithium Battery Pack                        | LiFePO4, 12V, ≥8Ah                                                       | 1    | BattleBorn or custom pack                                       |
| 24       | Plasma Shielding Brick (optional)           | Ceramic or sacrificial polymer                                           | 1    | Optional in vapor path                                          |

---

## ⚠️ Cost-Saving Notes

- Resin, sensors, and lenses can be substituted with locally available variants  
- Most non-electric parts are 3D printable or can be sourced from plumbing suppliers  
- Plasma vapor unit and beam lens grid are optional upgrades for heavily contaminated water

---

## 💡 Reminder

This BOM only includes **real-world, purchasable components**.  
Every part is either commercially available or can be fabricated using open-source hardware methods. No fiction.
