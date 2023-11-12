#!/bin/python
import sys
import math

if len(sys.argv) > 1 and sys.argv[1].isdigit():
    SAMPLES = int(sys.argv[1])
else:
    SAMPLES = 160


file = open("trig_table.h", "w+")
file.write("#ifndef TRIG_TABLE_H\n#define TRIG_TABLE_H\n\n")
file.write(f"#define TABLESIZE {SAMPLES}\n")

angle = math.pi / (2*(SAMPLES-1))
sin_value = math.sin(angle)
file.write(f"#define TABLESTEP {sin_value}\n\n")

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
