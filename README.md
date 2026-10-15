# 8-bit RISC-V ALU in C

An 8-bit Arithmetic Logic Unit (ALU) implemented in C with an automated Python verification test code. 

* **Project Motivation & Testing:**
    * I wanted to understand how all computes happen at a hardware level, so I implemented an 8-bit RISC-V ALU in C. It supports standard arithmetic, bitwise logic, and logical shifting while computing hardware status flags like Zero, Negative, Carry, and Overflow. 
    * To ensure proper testing and verification, I created a Python verification program that goes through over 1,000 randomized and edge-case tests. I focused heavily on 2's complement overflow boundaries where sign-extension errors may happen.

---

## Features

- **Custom C Implementation:** Written entirely in C (`alu.c` and `alu.h`), supporting standard arithmetic, bitwise logic, and shift operations.
- **Hardware Status Flags:** Computes essential processor flags (`Z` for Zero, `N` for Negative, `C` for Carry, and `V` for Overflow) on every operation.
- **Automated Python Verification:** Includes a Python golden reference testbench (`verify_alu.py`) that cross-checks the C implementation against edge cases and randomized stress tests.

---

## Supported Operations

| Opcode / Type | Operation Name | Description |
| :--- | :--- | :--- |
| `ADD` | Addition | Adds two 8-bit integers with carry & overflow detection |
| `SUB` | Subtraction | Subtracts operand B from A with borrow & overflow detection |
| `AND` | Bitwise AND | Bitwise conjunction |
| `OR` | Bitwise OR | Bitwise disjunction |
| `XOR` | Bitwise XOR | Bitwise exclusive OR |
| `SLL` | Shift Left Logical | Multiplies by powers of 2 (with safe 3-bit shift masking) |
| `SRL` | Shift Right Logical | Divides by powers of 2 |

---

## Demo

<img width="717" height="1017" alt="runEvidence" src="https://github.com/user-attachments/assets/4d719c40-d7d6-44db-9d75-366b7b66a67d" />

---

## Project Structure

```text
alu-risc-v-8bit/
├── alu.c             # Core ALU implementation
├── alu.h             # Function declarations and opcodes
├── main.c            # Manual test cases and console execution
├── verify_alu.py     # Automated Python verification testbench
└── README.md         # Project documentation
