FPGA-Based 32-Bit ALU Design, Integration, and Verification

This project implements a 32-bit Arithmetic Logic Unit (ALU) in Verilog and validates its functionality through structured testbench verification and FPGA prototyping.

The objective was to design a synthesizable RTL module, verify functional correctness using simulation, and validate timing and hardware behavior through FPGA deployment.

📌 Objective

To design and validate a 32-bit ALU by:

Implementing arithmetic and logical operations in synthesizable Verilog

Developing a structured SystemVerilog testbench

Performing functional simulation and waveform analysis

Synthesizing and implementing the design on FPGA

Analyzing timing and resource utilization

🛠 Tools Used

Verilog / SystemVerilog

Vivado (synthesis and FPGA implementation)

ModelSim / Questa (functional simulation)

Waveform debugging tools

🔧 Design Implementation

The ALU supports:

Addition and subtraction

Bitwise AND, OR, XOR

Shift operations

Comparison operations

Design characteristics:

32-bit input operands

Operation select control input

Combinational logic implementation

Fully synthesizable RTL

The design was written with clear separation between control and datapath logic.

🔍 Verification Approach

Verification included:

Directed test cases for each operation

Randomized operand generation

Edge case validation (overflow, zero, negative results)

Waveform-based debug for incorrect outputs

Simulation logs were compared against expected software-calculated results.

📊 FPGA Implementation & Validation

The ALU was synthesized and implemented on a Xilinx FPGA.

Validation steps:

Bitstream generation

Resource utilization analysis (LUTs, registers)

Timing analysis for setup and hold constraints

Hardware-level validation of correct operation

Timing reports were reviewed to ensure no critical path violations.

🎯 Key Outcomes

Experience writing synthesizable RTL

Functional verification using simulation

Practical FPGA implementation workflow

Understanding of timing constraints and hardware validation

Structured debug methodology
