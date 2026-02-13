SoC Subsystem Verification using SystemVerilog & UVM

This project implements a structured UVM-based verification environment for a simplified SoC subsystem containing memory-mapped control registers and bus interface logic.

The verification environment validates functional correctness, protocol behavior, and corner-case scenarios using constrained-random stimulus and coverage-driven methodology.

📌 Objective

To verify a SoC-level subsystem by:

Modeling transaction-level bus activity using SystemVerilog classes

Designing a layered UVM verification architecture

Implementing constrained-random stimulus generation

Adding assertion-based protocol checks (SVA)

Measuring and closing functional coverage

Debugging mismatches using waveform and scoreboard analysis

🛠 Tools Used

SystemVerilog

UVM (Universal Verification Methodology)

Questa / ModelSim (simulation and waveform debug)

Basic regression scripting

🔧 Design Under Test (DUT)

The subsystem includes:

Address decoding logic

Memory-mapped register block

Read/write control path

Valid/ready handshake protocol

Reset handling logic

The DUT supports:

32-bit read and write transactions

Consecutive back-to-back transfers

Randomized address access

Reset interaction during active traffic

🔍 Key Verification Steps

Development of transaction class to model bus activity

Implementation of driver to convert transactions into signal-level stimulus

Monitoring of DUT responses through passive monitor

Scoreboard comparison of expected vs observed behavior

Assertion-based checks for protocol stability and handshake timing

Coverage modeling for address range and transaction distribution

Iterative refinement of random constraints to close coverage gaps

📊 Results & Validation

Verification included both directed and constrained-random tests.

Validated scenarios:

Randomized read/write sequences

Back-to-back transaction behavior

Reset during active transfer

Invalid address handling

Functional coverage metrics were analyzed and improved through additional test sequences.

Waveform inspection and scoreboard mismatch detection were used to isolate and resolve RTL issues.

🎯 Key Outcomes

Structured UVM component design and reuse

Practical experience with constrained-random verification

Application of coverage-driven refinement

Assertion-based protocol validation

Strengthened debug methodology at SoC level
