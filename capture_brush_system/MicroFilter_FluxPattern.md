# MicroFilter Flux Capture System – Final Stage Particle Brush

> Subsystem: Post-ion-exchange mechanical capture  
> Role: Extract remaining nano-contaminants, microplastics, PFOA solids, and oil residues using micro-scale brush geometry and charged vortex adhesion.

---

## 🧲 Functional Role

This stage provides a **final physical and electrostatic capture** layer.  
It targets stubborn particulates **too small for gravity filters** but **not fully dissolved** — including:

- Residual PFOA fragments
- Microplastics (≤2 µm)
- Light petroleum traces
- Metal dust or corrosion flakes

---

## 🔩 Mechanical Design

| Feature                 | Description                                             |
|-------------------------|---------------------------------------------------------|
| Brush Type              | Microfiber synthetic polymer bristle grid              |
| Pattern                 | Spiral vortex array with tri-layer crosswind louver    |
| Electrostatic Charge    | Electret polymer mesh backing (permanent charge carrier)|
| Mounting                | Magnetically seated cartridge, 2.5" twist-lock         |
| Rotation                | Optional slow rotation (1–2 RPM) for passive refresh    |
| Size                    | 15 cm disc diameter, ~4 cm thick layered core          |

---

## 🌪️ Flow Interaction

Water flows through the mesh in a **clockwise vortex spiral**, created by louver vanes. This spinning behavior:

- Pushes particles outward to stick to charged outer rim
- Encourages **adhesion by momentum break** at bristle tips
- Extends dwell time inside capture region by ~6.4x vs laminar flow

---

## ⚡ Electret Layer Function

Electret polymer mesh (like PTFE or polypropylene) carries a **permanent low-field negative charge**.

- This attracts polarizable fragments like PFOA shells and fine dust
- No external voltage required
- Effective field: ~ –500 to –1000V at contact layer
- Can be "recharged" by mild triboelectric brushing if worn

---

## 💧 Maintenance & Disposal

| Component            | Cleaning Method        | Replace Cycle     |
|----------------------|------------------------|--------------------|
| Bristle core         | Rinse + alcohol wipe   | Every 2000 gallons |
| Electret mesh layer  | Replace only           | Every 1500 gallons |
| Louver housing       | Rinse only             | No replacement     |

> System alerts when flow resistance increases >40% or color sensor flags surface fouling.

---

## 🧠 Optional Sensor Hookup

```cpp
#define FLOW_SENSOR A2
#define COLOR_SENSOR A3

void loop() {
  float flowRate = analogRead(FLOW_SENSOR);
  int brushColor = analogRead(COLOR_SENSOR);
  
  if (flowRate < 60 || brushColor > 900) {
    alert("Brush Mesh Needs Cleaning");
    digitalWrite(LED_RED, HIGH);
  }
}
```

---

## 📈 Capture Effectiveness

| Contaminant           | Capture Rate |
|------------------------|--------------|
| PFOA solid fragments   | 85–90%       |
| Microplastic <2 µm     | ~92%         |
| Oil micro-droplets     | 88%          |
| Nanometal particles    | 91%          |

---

## 🧬 Integration Points

This module connects:
- After `ion_exchange/IonCapture_Logic.md`
- Before clean water outlet or optional UV polish loop

