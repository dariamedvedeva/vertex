import numpy as np
import sys
import subprocess

print "Prepearing data."
 
# gw_imag_00.dat rewrite in file to plot

f   = open("gw_imag00.dat", "r")
f2  = open("gw_imag00_for_plot.dat", "w")
lines = f.readlines()

for line in lines:
    params = line.split()
    for i in range(len(params)):
        if (i != 0):
            f2.write(params[i])
            f2.write(" ")
    f2.write("\n")
f.close()
f2.close()

# chi0000 write in one file
# and check double space as a separator
filenames = []

print "\nPlease, check that files of chi000 files are ranged by bosonic freq\n"

if len(sys.argv) >= 2 : 
    for i in range(len(sys.argv)):
        if (i != 0):
            filenames.append(sys.argv[i])
elif len(sys.argv) < 2:
    print 'Select at leat one file'
    sys.exit(1)

number_of_files = len(filenames)

print "Files: " 
for i in range(number_of_files):
    print filenames[i]
print "\n"

f   = open("chi0000.dat", "w")

for i in range(number_of_files):
    f2   = open(filenames[i], "r")
    lines = f2.readlines()
    
    for line in lines:
        params = line.split()
        for i in range(len(params)):
            f.write(params[i])
            f.write(" ")
        f.write("\n")
    f2.close()

f.close()

# chi_ch_imp.dat from Fortran code

f   = open("chi_ch_imp.dat", "r")
lines = f.readlines()
number_of_columns = len(lines[0].split())

if (number_of_columns == 4):
    f.close()    
else:
    f2  = open("chi_ch_imp2.dat", "w")
    for line in lines:
        params = line.split()
        f2.write("0.0000000000 ")    
        for i in range(len(params)):
            f2.write(params[i])
            f2.write(" ")
        f2.write("\n")
     
    f2.close()
    f.close()

    # -> change name, save initial file chi_ch_imp.dat
    subprocess.call(["mv", "chi_ch_imp.dat", "chi_ch_imp_initial.dat"])
    subprocess.call(["mv", "chi_ch_imp2.dat", "chi_ch_imp.dat"])

print "Done."
