#ifndef ALU_H
#define ALU_H

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    ALU_ADD = 0,
    ALU_SUB,
    ALU_AND,
    ALU_OR,
    ALU_XOR,
    ALU_SLL, // Shift Left Logical opr
    ALU_SRL  // Shift Right Logical opr
} alu_op_t;


typedef struct {
    uint8_t result; // 8bit result
    bool zero;      // Zero-flag (Z)
    bool negative;  // Neg-flag (N)
    bool carry;     // Carry-flag (C)
    bool overflow;  // 2's complement Overflow flag (V)
} alu_out_t;

//main ALU entry point
alu_out_t alu_compute(uint8_t a, uint8_t b, alu_op_t op);

#endif