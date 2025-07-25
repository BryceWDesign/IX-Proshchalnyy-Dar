# IX-Proshchalnyy-Dar – Full Build Guide  
> Version: Initial Humanitarian Deployment v1.0  
> Author: Bryce Wooster

---

## 🔧 Objective

This guide provides step-by-step instructions to physically construct the IX-Proshchalnyy-Dar water purification system using only real-world, available components.

All parts are listed in `/materials/IX-Proshchalnyy-Dar_BOM.md`.

---

## 🧱 Build Stage 1 – Chassis + Frame

1. **Frame Assembly**
   - Cut marine-grade polycarbonate or stainless panels to your frame dimensions (~60x30x40cm suggested).
   - Mount internal rails for module isolation and shock resistance.
   - Ensure all fasteners are stainless and sealed with 3M 5200 or equivalent marine epoxy.

2. **Power Core Install**
   - Mount DC PSU and capacitor bank at bottom-rear corner (thermally separated).
   - Wire internal power distribution nodes with 14AWG silicone wire.
   - Optional: Connect ambient energy module (solar or piezo) to auxiliary input.

---

## 🌪️ Build Stage 2 – Inlet & Capture System

3. **Inlet Cone & Vortex Inducer**
   - Mount stainless intake cone with coarse debris mesh.
   - Below it, angle guide vanes to induce a clockwise vortex flow into the chamber.

4. **Fractal Capture Matrix**
   - Affix replaceable capture mesh (zeolite/microfiber) around inlet pipe interior.
   - Add spinning Velcro-brush insert using brushless DC motor and low-RPM driver board.
   - Power via step-down module from DC PSU.

---

## 🔋 Build Stage 3 – Beam Discharge Unit (FIDA)

5. **Install FIDA Pulse Rods**
   - Align 6x rods in hexagonal configuration inside mid-chamber (non-conductive mount).
   - Each rod is copper-core, graphene-skin, connected to capacitor bank.

6. **Pulse Driver Setup**
   - Connect capacitor bank via SCR or high-voltage MOSFET array.
   - Use control board to regulate pulse width, power level, and frequency.

7. **Safety Interlock**
   - Install auto-disable if beam firing continues longer than 50ms per pulse window.

---

## 🌊 Build Stage 4 – UV Kill Reactor

8. **LED Array Placement**
   - Place UV-C emitters behind quartz Tesla-lens grid.
   - Seal inside an IP68 chamber submerged to ~0.5m waterline (or deeper per design).

9. **Power Regulation**
   - Use constant current drivers to keep UV-C output stable regardless of voltage fluctuation.

10. **Light Trap Design**
    - Paint surrounding internal walls matte black or install baffle fins to prevent beam leakage.

---

## ⚛️ Build Stage 5 – Ion Trap & Final Filter

11. **Ion Exchange Media**
    - Slide in zeolite + electret mesh slabs into channel holder below UV chamber.
    - Design as removable cartridge with silicone-sealed gasket.

12. **Output Filter**
    - At final stage, mount 0.2µm ceramic/silver core filter inline.
    - Ensure flow is laminar and vent backpressure via valve if needed.

---

## ❄️ Build Stage 6 – CryoCore Cooling

13. **Cryo Plate + Loop**
    - Attach CryoCore Tesla plate near UV + beam heat zones.
    - Route coolant to microfluidic copper sink near chassis base.
    - Circulation: Passive or DC pump loop. No external chiller required.

---

## 🧠 Build Stage 7 – Control Board & Telemetry

14. **Install ESP32 or STM32 Board**
    - Flash code to handle:
      - Pulse timing
      - UV drive duration
      - Overheat cutoff
      - Runtime diagnostics

15. **Sensor Placement**
    - Mount:
      - Temp sensors near UV and beam
      - Current sensors on power rails
      - Optional: Turbidity or ORP sensor at inlet/outlet

16. **Diagnostic LEDs**
    - Add LED indicators for each stage:
      - Power OK
      - Beam armed
      - UV active
      - Cooling loop
      - Fault

---

## 🔁 Final Calibration & Testing

1. Dry-run each subsystem without fluid to validate:
   - Pulse timing
   - Beam alignment
   - UV intensity
   - Sensor feedback

2. Test water flow with clean water and confirm:
   - No leaks
   - No short circuits
   - Cryo loop activates above 45°C internal temp

3. Optional: Loop output back to input and observe multi-pass cleaning curve.

---

## ⚠️ Maintenance Tips

- Mesh + brush assembly should be replaced weekly in severe contamination.
- Ion cartridge rated for ~200L before replacement (depends on PFAS load).
- UV emitters rated for 9,000–12,000 hours at full duty cycle.
