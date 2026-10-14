#include <stdio.h>
#include "alu.h"

void print_binary(uint8_t n) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
}

void run_test(uint8_t a, uint8_t b, alu_op_t op, const char* op_name) {
    alu_out_t out = alu_compute(a, b, op);

    printf("Operation: %s | A = %3d (0x%02X), B = %3d (0x%02X)\n", op_name, a, a, b, b);
    printf("  Result:  %3d (0x%02X) | Binary: ", out.result, out.result);
    print_binary(out.result);
    printf("\n  Flags  -> Z: %d | N: %d | C: %d | V: %d\n",
           out.zero, out.negative, out.carry, out.overflow);
    printf("--------------------------------------------------\n");
}

int main() {
    printf("=== Starting RISC-V 8-bit ALU Manual Tests ===\n\n");

    run_test(10, 20, ALU_ADD, "ADD");

    // 2's Complement Overflow Test (100 + 50)
    run_test(100, 50, ALU_ADD, "ADD (Overflow Case)");

    run_test(50, 20, ALU_SUB, "SUB");

    run_test(0xF0, 0xAA, ALU_AND, "AND");

    run_test(0xF0, 0x0F, ALU_OR, "OR");

    run_test(0x01, 3, ALU_SLL, "SLL");

    return 0;
}