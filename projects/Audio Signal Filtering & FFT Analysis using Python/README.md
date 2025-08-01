# 🎧 Audio Signal Filtering & FFT Analysis using Python

This project demonstrates core concepts in Digital Signal Processing (DSP) using Python. A real audio signal is filtered using FIR and IIR low-pass filters, with noise reduction, spectral analysis via FFT, and optional amplitude modulation. The project simulates a practical DSP application in audio cleaning and frequency-domain analysis.

## 🔧 Tools & Libraries Used
- Python 3
- NumPy
- SciPy (Signal Processing Toolbox)
- Matplotlib
- SoundFile (for reading/writing WAV files)
- Jupyter Notebook

---

## 📌 Project Features

### ✅ 1. Load & Process Audio
- Reads a real `.wav` file
- Converts stereo to mono
- Adds synthetic Gaussian noise

### ✅ 2. FIR & IIR Filtering
- FIR filter using `firwin` (linear phase)
- IIR Butterworth filter using `butter`
- Time-domain plots for comparison
- Group delay and frequency response visualization using `freqz` and `group_delay`

### ✅ 3. FFT Spectrum Analysis
- Custom FFT plotting function
- Compares frequency spectrum of:
  - Original signal
  - Noisy signal
  - FIR-filtered signal
  - IIR-filtered signal

## 📈 Output Plots
- Time-domain waveforms
- Frequency-domain (FFT) spectra
- FIR vs. IIR comparison
- Magnitude and group delay plots

---

## 🔊 Output Files
- `original_mono.wav`
- `noisy_signal.wav`
- `filtered_fir.wav`
- `filtered_iir.wav`

---

## 🎓 Skills Demonstrated
- FIR & IIR filter design
- Spectral analysis with FFT
- Time vs. frequency domain comparison
- Noise handling
- Real-world DSP intuition (filter selection, delay vs. efficiency trade-offs)

---

## 📌 How to Run
1. Clone the repository
2. Install dependencies
3. Run

