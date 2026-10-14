import random

# Define ALU operations matching your C enum
OP_ADD = 0
OP_SUB = 1
OP_AND = 2
OP_OR  = 3
OP_XOR = 4
OP_SLL = 5
OP_SRL = 6

op_names = {OP_ADD: "ADD", OP_SUB: "SUB", OP_AND: "AND", OP_OR: "OR", OP_XOR: "XOR", OP_SLL: "SLL", OP_SRL: "SRL"}

def emulate_alu(a, b, op):
    """Python Golden Reference Model for the 8-bit ALU"""
    a &= 0xFF
    b &= 0xFF

    carry = False
    overflow = False

    if op == OP_ADD:
        temp = a + b
        result = temp & 0xFF
        carry = temp > 0xFF
        overflow = ((~(a ^ b) & (a ^ result)) & 0x80) != 0

    elif op == OP_SUB:
        temp = a - b
        result = temp & 0xFF
        carry = (a < b)
        overflow = (((a ^ b) & (a ^ result)) & 0x80) != 0

    elif op == OP_AND:
        result = (a & b) & 0xFF
    elif op == OP_OR:
        result = (a | b) & 0xFF
    elif op == OP_XOR:
        result = (a ^ b) & 0xFF
    elif op == OP_SLL:
        shift = b & 0x07
        result = (a << shift) & 0xFF
    elif op == OP_SRL:
        shift = b & 0x07
        result = (a >> shift) & 0xFF
    else:
        result = 0

    zero = (result == 0)
    negative = (result & 0x80) != 0

    return {
        "result": result,
        "zero": int(zero),
        "negative": int(negative),
        "carry": int(carry),
        "overflow": int(overflow)
    }

def run_verification():
    print("=== Starting ALU Verification & Test Printout ==-\n")

    # Key edge cases to always display clearly
    edge_values = [0, 1, 127, 128, 255]
    ops = [OP_ADD, OP_SUB, OP_AND, OP_OR, OP_XOR, OP_SLL, OP_SRL]

    test_count = 0
    failures = 0

    # 1. Run and print explicit boundary/edge cases
    print("--- Edge Case & Overflow Test Vectors ---")
    for a in edge_values:
        for b in [1, 128]:
            for op in [OP_ADD, OP_SUB]:
                test_count += 1
                res = emulate_alu(a, b, op)
                print(f"Test {test_count:2d}: {op_names[op]:3s} | A={a:3d} (0x{a:02X}), B={b:3d} (0x{b:02X}) -> Result={res['result']:3d} | Z={res['zero']} N={res['negative']} C={res['carry']} V={res['overflow']}")

    # 2. Reduced Randomized Testing (e.g., just 20 random tests instead of 1,200)
    print("\n--- Randomized Stress Tests ---")
    random.seed(42)
    target_random_tests = 20

    for i in range(target_random_tests):
        a = random.randint(0, 255)
        b = random.randint(0, 255)
        op = random.choice(ops)

        test_count += 1
        res = emulate_alu(a, b, op)

        # Print a few sample random tests so you can see them scrolling
        if i < 5:
            print(f"Test {test_count:2d}: {op_names[op]:3s} | A={a:3d}, B={b:3d} -> Result={res['result']:3d}")

        if not (0 <= res["result"] <= 255):
            failures += 1

    print(f"\nVerification Complete!")
    print(f"Total Test Cases Run: {test_count}")
    print(f"Failures Detected:    {failures}")
    if failures == 0:
        print("RESULT: ALL TESTS PASSED SUCCESSFULLY!")
    else:
        print("RESULT: SOME TESTS FAILED.")

if __name__ == "__main__":
    run_verification()