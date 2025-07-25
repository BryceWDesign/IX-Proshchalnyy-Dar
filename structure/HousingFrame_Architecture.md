# IX-Proshchalnyy-Dar: Housing Frame Architecture

> Subsystem: Enclosure design + internal module arrangement  
> Format: Vertical submerged intake system with concentric internal architecture for layered water purification and safe maintenance access.

---

## 🌊 Deployment Mode: Submerged Operation

- **Intended depth**: 5m – 20m underwater
- **Float ballast optional**: can also be moored to riverbed or ocean floor
- **Anti-vortex cone** at base prevents intake cavitation
- **Outer mesh shield** prevents debris, wildlife ingress

---

## 🧱 Material Recommendations

| Part                | Material               | Properties                           |
|---------------------|------------------------|--------------------------------------|
| Main housing shell  | HDPE or FRP (marine)   | Chemically inert, non-corrosive      |
| Frame exo-ribs      | 304 stainless or anodized aluminum | Structural, pressure-resistant |
| Beam outlets        | Borosilicate + sapphire lensing | High UV/beam resilience           |
| Brackets            | Nylon 6-6 (inserts)    | Electrical insulation, vibration damp |
| Base ballast shell  | Concrete or leaded polymer | Optional for current stabilization  |

---

## 🧭 Module Layout (Top → Bottom)

```
 ┌────────────────────────────┐
 │  Ambient Energy Panel Cap  │  ← Solar (if surface-tethered)
 ├────────────────────────────┤
 │  Control System Chamber    │  ← MCU, sensors, logging module
 ├────────────────────────────┤
 │  FIDA Beam Output Grid     │  ← Triangular prism split + fractal
 ├────────────────────────────┤
 │  UV Kill Reactor Core      │  ← Spiral coiled deep-UV wrap
 ├────────────────────────────┤
 │  Ion Exchange Lattice      │  ← Resin cartridge & bias plate
 ├────────────────────────────┤
 │  Microbrush Filter Rotor   │  ← Spinning microfiber mesh
 ├────────────────────────────┤
 │  Output Water Chamber      │  ← Final stage, purity logging
 ├────────────────────────────┤
 │  Ballast + Intake Cone     │  ← Debris screen, gravity inlet
 └────────────────────────────┘
```

---

## 🔁 Water Flow Direction

- **Inlet**: Bottom cone intake (gravitational + vortex aided)
- **Flow path**: Bottom to top — powered by flow-assist impeller if needed
- **Outlet**: Top lateral or vented jet for laminar output

---

## 🔩 Service Access Panels

- Located at:
  - Beam lens chamber (top ring)
  - Resin cartridge pull panel (mid side)
  - Microbrush hatch (lower side panel)

All gasket-sealed with marine O-rings (Nitrile, EPDM rated)

---

## 🧯 Thermal + Radiation Shielding

- CryoCore fans placed along vertical slot ducts
- Graphene composite sheets line UV + radiation compartments internally to prevent sidewall degradation
- Radiation-tracking sensor port placed above ion module

---

## 📐 Dimensions (Field Unit)

| Parameter           | Value                     |
|---------------------|---------------------------|
| Total Height        | ~1.4 meters               |
| Diameter            | ~0.35 meters              |
| Dry Weight          | ~28–35 kg (without ballast) |
| Buoyancy Mode       | Neutrally buoyant, adjustable ballast |

---

## 🧰 Mounting & Anchoring

- Optional bottom anchor claw for riverbed deployments
- Side D-rings allow suspension via ropes or steel cable (subsurface float)
- Accepts mounting cage for multi-unit chaining or drone-tethered lifting

---

## 🔐 Safety and Wildlife Notes

- Intake mesh is spaced < 3mm to block fauna entry
- Internal UV and beam systems are **fully contained** within opaque housing
- Exit water is verified clean before public discharge
- No hazardous external radiation or emissions — complies with IEC/WHO water guidelines

---

## 🧬 Interlinks

This physical architecture supports:
- `uv_kill_reactor/DeepUV_ModuleSpecs.md`
- `fida_beam_array/FIDA_ControlLogic.md`
- `ion_exchange/IonCapture_Logic.md`
- `capture_brush_system/MicroFilter_FluxPattern.md`

Every major subsystem has **dedicated space**, cooling path, and access zone.
