# 🔁 Phase-Locked Loop (PLL) Design & Simulation in LTspice

This project demonstrates the design and simulation of a Phase-Locked Loop (PLL) system using LTspice. The project includes building blocks such as a ring oscillator (VCO), phase-frequency detector (PFD), charge pump, and a second-order loop filter. This work is intended for educational use in analog/mixed-signal VLSI design.

---

## 🧩 Project Structure

### Components Simulated:
- ✅ **Ring Oscillator (VCO)** – frequency controlled by analog voltage
- ✅ **XOR-based PFD** – simple phase detector using behavioral modeling
- ✅ **Flip-Flop-style PFD with Charge Pump** – realistic PFD driving a dual-path current pump
- ✅ **Second-Order Loop Filter** – passive RC low-pass filter to smooth the control voltage
- ✅ **Full PLL Loop** (optional by Week 5) – closed-loop behavior with REF and feedback

---

## 📁 File Organization

| File | Description |
|------|-------------|
| `vco_ring.asc` | CMOS ring oscillator schematic |
| `pfd_xor.asc` | XOR-based phase detector |
| `pfd_chargepump.asc` | Flip-flop-style PFD + charge pump |
| `loop_filter.asc` | Second-order passive RC filter |
| `pll_closedloop.asc` | Integrated PLL block |
| `waveforms/` | Screenshots of simulated outputs |
| `notes/` | Design notes, tuning values, calculation reference |
| `README.md` | This file |

---

## 🧠 Key Concepts

- PLL is used to synchronize the output of a VCO to a reference frequency
- The PFD detects phase differences between REF and feedback
- The Charge Pump translates digital PFD signals into analog current
- The Loop Filter smooths the signal to avoid jitter
- The VCO adjusts frequency based on this filtered control voltage

---

## 📊 Tools Used

- **LTspice XVII / 24.1.9** – Simulation platform
- **MATLAB/Excel**  – For waveform analysis and FFT
- **GitHub** – Version control and documentation

---

## 📈 Example Output

![vctrl waveform](waveforms/vctrl_response.png)
> Control voltage `vctrl` ramping in response to PFD and charge pump output.

---

## 🚀 How to Run

1. Open any `.asc` file in LTspice
2. Run simulation (press Run or use `.tran`)
3. Probe relevant nodes: `vctrl`, VCO output, REF, UP/DOWN
4. Modify component values to tune performance

---

## 📚 References

- [TI Application Note SCBA017 – PLL Design](https://www.ti.com/lit/an/scba017/scba017.pdf)
- [Analog Devices MT-086 – PLL Fundamentals](https://www.analog.com/media/en/training-seminars/tutorials/MT-086.pdf)
- [All About Circuits – PLL Basics](https://www.allaboutcircuits.com/technical-articles/introduction-to-phase-locked-loops-plls/)

---

## ✍️ Author

**Shaik Shaheed**  
San Diego State University  
MS Computer Engineering – VLSI Track  
📧 skshaheed34@gmail.com  
🔗 [LinkedIn](https://www.linkedin.com/in/shaheed-basha-shaik/)

---

## 📌 License

MIT License — feel free to use, modify, or cite for academic purposes.

