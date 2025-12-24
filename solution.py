import struct

TARGET_SUM = 11111111101111111110
TARGET_XOR = 10966994397930884516


def main():
    diff = TARGET_SUM - TARGET_XOR
    if diff < 0 or diff % 2 != 0:
        raise RuntimeError("Invalid constraints")

    and_val = diff // 2

    if and_val & TARGET_XOR:
        raise RuntimeError("No valid solution")

    a = TARGET_XOR + and_val
    b = and_val

    with open("key.bin", "wb") as f:
        f.write(struct.pack("<QQ", a, b))


if __name__ == "__main__":
    main()
