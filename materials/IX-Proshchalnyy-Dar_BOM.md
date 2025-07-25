# IX-Proshchalnyy-Dar – Bill of Materials (BOM)

> This file provides a complete part list for the construction of one IX-Proshchalnyy-Dar purification unit, focused on eliminating PFAS, PFOA, radioactive sediment, and microbial contaminants from severely polluted water.

---

## 🔩 Subsystem Key

| Code | Subsystem                   |
|------|-----------------------------|
| INL  | Inlet Pre-Filtration + Vortex |
| CAP  | Capture Reactor (Brush/Mesh) |
| FIDA | Field-Intelligent Discharge Array |
| UVK  | Submerged UV Kill Reactor     |
| ION  | Ion Exchange Trap             |
| GRV  | Gravity Separation Core       |
| PWR  | Power Core + Distribution     |
| CRYO | CryoCore Thermal Management   |
| CTL  | Control Logic & Sensors       |

---

## 📦 Component List

| Qty | Description | Specs / Notes | Subsystem | Source Suggestion |
|-----|-------------|----------------|-----------|--------------------|
| 1   | Stainless Vortex Intake Cone | 316L, mesh-capable | INL | McMaster-Carr / local fab |
| 3m² | Fractal Capture Mesh | Zeolite+microfiber hybrid, replaceable | CAP | Custom weave / high-temp fabric |
| 1   | Microbrush Velcro Matrix | Rotational spin-capable | CAP | 3D-printed insert + brush strip |
| 6   | FIDA Pulse Rods | Copper core, graphene coating, 22cm | FIDA | Custom or modded from ion emitters |
| 1   | Beam Driver Capacitor Bank | 2kV discharge, 200A burst | FIDA | Vishay, KEMET |
| 4   | UV-C Deep Submersible LEDs | 260-280nm, min 50mW/cm² output | UVK | Seoul Viosys, Nichia |
| 1   | Tesla-patterned UV Lens Grid | Quartz, Horus-geometry precision | UVK | Custom laser-cut quartz or ceramic |
| 2   | Ion Exchange Slabs | High-surface zeolite + electret mesh | ION | Purolite / lab-grade suppliers |
| 1   | Gravity Core Chamber | Conical bottom w/ sediment tap | GRV | Stainless / HDPE / PVC |
| 1   | Ambient Energy Interface (optional) | Piezo-solar hybrid module | PWR | SunCore / SparkFun |
| 1   | Primary DC PSU | 24V @ 10A with regulation | PWR | Meanwell / TDK Lambda |
| 1   | Control Logic Board | ESP32 or STM32 base | CTL | Adafruit / Waveshare |
| 5   | Temp + Current Sensors | 10k NTC, Hall Effect for current | CTL | Honeywell / Seeed |
| 1   | CryoCore Heat Plate | Tesla cryo-looped aluminum, active loopback | CRYO | Custom CNC milled |
| 1   | Microfluidic Heat Sink | Submerged copper-polymer | CRYO | Asetek / ModMyMods |
| 1   | Output Final Filter | 0.2µm ceramic + silver filter | GRV | Katadyn / Sawyer inline |
| 1   | System Frame + Housing | IP68 rated, polycarbonate or stainless | All | Locally fabricated or marine-grade kit |
| —   | Fasteners, Epoxy, Sealants | Marine-rated (Loctite Blue / 3M 5200) | All | McMaster, 3M |

---

## 🛒 Procurement Notes

- Parts are chosen for **civilian availability**, **global supply chain redundancy**, and **non-restricted sourcing**
- UV and FIDA modules may require **custom fabrication** or adaptation from existing water/air purifiers
- CryoCore plate uses **Tesla-loop phase heat pathing** — instructions in CryoCore subsystem file
- All components are **modular** — subsystems can be upgraded independently
- Pricing tiers:
  - **Budget Build:** <$300 USD (using basic meshes, plastic housing, no ambient energy)
  - **Full Build:** $600–$900 USD depending on beam bank and UV output quality
