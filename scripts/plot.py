import subprocess
import numpy as np
import sys

if len (sys.argv) > 1:
    beta = float(sys.argv[1])
    num_bos_fr = int(sys.argv[2])
else:
    print ("arguments: 1 - python_script.py, 2 - beta, 3 - number of bosonic frequencies")

print "This script is for preparation and plotting vertices\n"
subprocess.call("python prepare_data_for_plot.py " + str(beta) + " " + str(num_bos_fr), shell = True)

subprocess.call("./plot_vertex4_3D_0.script", shell = True)

subprocess.call("./plot_vertex4_3D_5.script", shell = True)

print "rm *.pdf"
subprocess.call("rm *.pdf", shell = True)

print "Convert from eps to pdf"
subprocess.call("epstopdf vertex4_omega_0_nu.eps vertex4_omega_0_nu.pdf", shell = True)
subprocess.call("epstopdf vertex4_omega_5_nu.eps vertex4_omega_5_nu.pdf", shell = True)

print "rm *.eps"
subprocess.call("rm *.eps", shell = True)
