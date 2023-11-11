#!/bin/python
import sys
import math
from mpmath import mp

if len(sys.argv) > 1 and sys.argv[1].isdigit():
    SAMPLES = int(sys.argv[1])
else:
    SAMPLES = 160

mp.dps = 20

file = open("trig_table.h", "w+")
file.write("#ifndef TRIG_TABLE_H\n#define TRIG_TABLE_H\n\n")
file.write(f"#define PI {mp.pi}\n\n")
file.write(f"#define TABLE_SIZE {SAMPLES}\n\n")

file.write("const number sin_table[] = {\n")

for i in range(0, SAMPLES):
    angle = i * math.pi / (2*(SAMPLES-1))
    sin_value = math.sin(angle)
    if i == SAMPLES:
        file.write(f"{sin_value} // sin({angle})\n")
    else:
        file.write(f"{sin_value}, // sin({angle})\n")

file.write("};\n")
file.write("#endif")
file.close()
