import numpy as np
import sys

if len (sys.argv) > 1:
    beta = float(sys.argv[1])
    num_bos_fr = int(sys.argv[2])
else:
    print ("arguments: 1 - python_script.py, 2 - beta, 3 - number of bosonic frequencies")

print '\n*** This script rewrites data from vertex4.dat and vertex3.dat into 2 different files:'
print '1th - for zero bosonic matsubara and 2nd - for the last bosonic matsubara which number'
print 'you have inputed as an argument for this script. *** \n'

bosonic_freq = 2.0 * np.pi * num_bos_fr / beta
print 'The last bosonic frequency is ' + str(bosonic_freq) + '\n'

# vertex 3d

f   = open("vertex3.dat", "r")
f2 = open("vertex3_omega_0_nu.dat", "w")
f3 = open("vertex3_omega_5_nu.dat", "w")
lines = f.readlines()

for line in lines:
    params = line.split()
    if (float(params[0]) == 0.0):
        f2.write(line)
    if (abs(float(params[0]) - bosonic_freq) < 0.000001):
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
    if (abs(float(params[0]) - bosonic_freq) < 0.000001):
        f3.write(line)
f.close()
f2.close()
f3.close()

print 'Have done.\n'
