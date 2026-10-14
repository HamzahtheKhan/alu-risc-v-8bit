#include "alu.h"
//author Hamzah Khan

alu_out_t alu_compute(uint8_t a, uint8_t b, alu_op_t op) {
    alu_out_t out;
    uint16_t temp_result = 0;

    switch (op) {
        case ALU_ADD:
            temp_result = (uint16_t)a + (uint16_t)b;
            out.result = (uint8_t)(temp_result & 0xFF);
           //carry when exceeds 8 bits
            out.carry = (temp_result > 0xFF);
            // Imp comment 2's complement overflow (A_sign == B_sign) && (Result_sign != A_sign)
            out.overflow = ((~(a ^ b) & (a ^ out.result)) & 0x80) != 0;
            break;

        case ALU_SUB:
            temp_result = (uint16_t)a - (uint16_t)b;
            out.result = (uint8_t)(temp_result & 0xFF);

            out.carry = (a < b);
            // 2's complement overflow for subtraction
            out.overflow = (((a ^ b) & (a ^ out.result)) & 0x80) != 0;
            break;

        case ALU_AND:
            out.result = a & b;
            out.carry = false;
            out.overflow = false;
            break;

        case ALU_OR:
            out.result = a | b;
            out.carry = false;
            out.overflow = false;
            break;

        case ALU_XOR:
            out.result = a ^ b;
            out.carry = false;
            out.overflow = false;
            break;

        case ALU_SLL:
            out.result = a << (b & 0x07);
            out.carry = false;
            out.overflow = false;
            break;

        case ALU_SRL:
            out.result = a >> (b & 0x07);
            out.carry = false;
            out.overflow = false;
            break;

        default:
            out.result = 0;
            out.carry = false;
            out.overflow = false;
            break;
    }

    out.zero = (out.result == 0);

    out.negative = ((out.result & 0x80) != 0);

    return out;
}