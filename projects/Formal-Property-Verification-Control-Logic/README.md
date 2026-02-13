Formal Property Verification of Control Logic

This project applies formal verification techniques to validate the correctness of control logic using SystemVerilog Assertions (SVA).

The objective was to verify finite state machine (FSM) behavior, protocol compliance, and corner-case conditions without relying solely on simulation-based testing.

📌 Objective

To improve robustness of control logic by:

Writing SystemVerilog Assertions (SVA) for protocol correctness

Verifying FSM state transitions

Detecting unreachable or illegal states

Validating clock-gating and control signal stability

Strengthening design reliability through property checking

🛠 Tools Used

SystemVerilog

Assertion-Based Verification (SVA)

Formal verification concepts

Simulation tools (Questa / ModelSim)

🔧 Design Under Verification

The control logic includes:

Finite State Machine (FSM)

State transition logic

Control signal generation

Reset handling

The FSM supports:

Defined state transitions

Controlled output behavior

Reset-safe operation

🔍 Verification Approach

SystemVerilog Assertions were written to verify:

Legal state transitions

Absence of invalid state entry

Stability of handshake/control signals

Proper reset behavior

No unintended latching conditions

Properties were developed incrementally and refined after observing assertion failures during simulation.

📊 Validation Strategy

Assertions were embedded in the testbench

Directed tests triggered edge-case transitions

Assertion failures were analyzed through waveform inspection

State transition coverage was reviewed to ensure complete verification

🎯 Key Outcomes

Strengthened understanding of assertion-based verification

Improved FSM robustness

Identified and corrected unsafe transitions

Gained practical experience writing meaningful SVA properties
