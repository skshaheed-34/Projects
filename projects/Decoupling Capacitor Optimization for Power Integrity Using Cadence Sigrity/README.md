# Decoupling Capacitor Optimization for Power Integrity Using Cadence Sigrity

This project investigates voltage noise suppression between power and ground planes in a 5-layer PCB by optimizing the location and RLC values of decoupling capacitors using Cadence Sigrity's PowerSI tool.

---

## 📌 Objective

To reduce power-ground noise in a multilayer PCB by:

- Designing a 5-layer stackup board with designated power (VDD) and ground (GND) planes.
- Identifying voltage noise hotspots through 2D and 3D visualization of spatial voltage distribution.
- Placing up to 5 optimized decoupling capacitors based on analysis.
- Simulating the power/ground impedance (Z11) with and without decoupling capacitors to quantify improvement.

---

## 🛠 Tools Used

- **Cadence Sigrity PowerSI** – frequency domain simulation using Method of Moments.
- **SPICE modeling** – for short-circuit VRM and decap modeling.
- **3D Layout Viewer** – for visualizing electromagnetic effects and capacitor impact.

---

## 🔧 Design Setup

- **Board Stackup**:
  - 5-layer PCB
  - 2nd layer: Ground net
  - 4th layer: Power net (VDD)

- **Default Via Stack**:
  - Via diameter: 0.4 mm
  - Pad diameter: 0.5 mm
  - Anti-pad diameter: 0.6 mm

- **Excitation Sources**:
  - Sink 1: AC=100mA
  - Sink 2: AC=75mA

- **VRM Representation**:
  - Modeled using a 0.01 mΩ resistor in SPICE

---

## 🔍 Key Steps

1. **Via definition and signal/power routing**
2. **Modeling sinks and connecting to layout (S1, S2)**
3. **Short circuit VRM modeling (T1)**
4. **Initial voltage noise analysis without decaps**
5. **Visualization of hotspots and capacitor placement**
6. **Decap modeling and integration into layout**
7. **Z11 impedance extraction and comparative analysis**

---

## 📈 Results & Validation

- **Before vs After Decoupling Analysis**
  - Notable reduction in voltage noise at sink locations
  - Lowered Z11 impedance with active decaps
  - Improved spatial uniformity in power delivery network

---

## 🎥 Deliverables

- Project Report (PDF)
- 3-minute screen-capture video showing key simulation steps

---

