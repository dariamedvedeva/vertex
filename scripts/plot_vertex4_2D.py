import subprocess
import numpy as np

#subprocess.call("./plot_vertex4_3D.script", shell = True)

xrange1 = []
yrange1 = []

xrange2 = []
yrange2 = []

f = open("vertex4_omega_0.txt", "r")
#f = open("vertex4_U_0.5_omega_5.txt", "r")
lines = f.readlines()

for line in lines:
    params = line.split()
    if (abs(float(params[1]) - 2.042035224) < 0.000001):
        xrange1.append(float(params[2]))
        yrange1.append(float(params[3]))
    if (abs(float(params[2]) - 2.042035224) < 0.000001):
        xrange2.append(float(params[1]))
        yrange2.append(float(params[3]))
f.close()

f = open("vertex4_U_0.5_omega_0_nu.txt", "w")
for i in range(xrange1.__len__() )
    f.write(str(xrange1[i]))
    f.write("\t")
    f.write(str(yrange1[i]))
    f.write("\n")
f.close()


f = open("vertex4_U_0.5_omega_0_nu_prime.txt", "w")
for i in range(xrange2.__len__() ):
    f.write(str(xrange2[i]))
    f.write("\t")
    f.write(str(yrange2[i]))
    f.write("\n")
f.close()
