# VLSI Fault Detection Using Machine Learning on RISC-V

This project demonstrates a complete flow of detecting faults in digital VLSI circuits using machine learning and deploying the classifier on a simulated RISC-V processor. It combines Verilog design, data collection, ML model training, and RISC-V integration.

## Project Overview

- Designed a 2-bit adder in Verilog with optional stuck-at fault injection
- Simulated all combinations of inputs with and without faults
- Generated labeled output data from the Verilog testbench
- Trained a decision tree classifier using Python and scikit-learn
- Exported the trained model to C using micromlgen
- Converted the model logic to RISC-V assembly and simulated it on Venus
- Verified output classification on embedded logic (no_fault / stuck_at)

- 
## Tools & Technologies

- Verilog (EDA Playground / Icarus Verilog)
- Python, pandas, scikit-learn, micromlgen
- Venus RISC-V Simulator (https://kvakil.github.io/venus/)
- Google Colab or local Python environment

## ML Classifier Behavior

The decision tree model uses features: `a`, `b`, `fault_en`, and `sum`.  
It predicts fault_type as:
- `no_fault` when `sum` matches expected or `fault_en == 0`
- `stuck_at` when `fault_en == 1` and sum deviates

Example exported model logic:
```c
if (x[2] <= 0.5) return 0;  // no_fault
else return 1;             // stuck_at

## Results
Achieved 100% classification accuracy on test data
Verilog logic and ML predictions align across simulation
Inference logic translated and verified in Venus (RISC-V simulator)
