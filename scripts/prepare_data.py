import numpy as np

# vertex 3d

f   = open("vertex3.dat", "r")
f2 = open("vertex3_omega_0_nu.dat", "w")
f3 = open("vertex3_omega_5_nu.dat", "w")
lines = f.readlines()

for line in lines:
    params = line.split()
    if (float(params[0]) == 0.0):
        f2.write(line)
    if (abs(float(params[0]) - 0.314159265359) < 0.000001):
        f3.write(line)
f.close()
f2.close()
f3.close()

# vertex 4d

f   = open("vertex4.dat", "r")
f2 = open("vertex4_omega_0_nu.dat", "w")
f3 = open("vertex4_omega_5_nu.dat", "w")
lines = f.readlines()

for line in lines:
    params = line.split()
    if (float(params[0]) == 0.0):
        f2.write(line)
    if (abs(float(params[0]) - 0.314159265359) < 0.000001):
        f3.write(line)
f.close()
f2.close()
f3.close()
