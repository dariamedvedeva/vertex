import numpy as np
import subprocess

# vertex 4d

beta = 100.

def write_G_in_file(file_name, file_name_chi0000, params):
    additional_file = False
    if (int(params[0]) == int(0)):
        f = open("chi0000_W.dat", "a")
        additional_file = True
    if  (int(params[0]) == int(5)):
        f = open("chi0000_W5.dat", "a")
        additional_file = True

    for i in range(len(params) - 2):
        if(i == 0):
            file_name_chi0000.write(str(0.0))
            file_name_chi0000.write(' ')
            matsubara_bos = 2 * int(params[i]) * np.pi / beta
            file_name_chi0000.write(str(matsubara_bos))
            if additional_file == True:
                f.write(str(0.0))
                f.write(' ')
                f.write(str(matsubara_bos))
    
        if (i == 1 or i == 2):
            file_name_chi0000.write(str(0.0))
            file_name_chi0000.write(' ')
            matsubara_ferm = 2 * (int(params[i]) + 1) * np.pi / beta
            file_name.write(str(matsubara_ferm))
            file_name_chi0000.write(str(matsubara_ferm))
            if additional_file == True:
                f.write(str(0.0))
                f.write(' ')
                f.write(str(matsubara_ferm))
        else:
            if (i != 0):
                file_name.write(params[i])
            file_name_chi0000.write(params[i])
            if additional_file == True:
                f.write(params[i])
        if(i != 0):
            file_name.write(' ')
        file_name_chi0000.write(' ')

        if additional_file == True:
            f.write(' ')
                
    file_name.write('\n')
    file_name_chi0000.write('\n')
    if additional_file == True:
        f.write('\n')

    if (additional_file == True):
        f.close()

def write_Gamma_in_file(file_name, params):
    for i in range(len(params)):
        if (i == 0):
            continue
        if (i == 1 or i == 2):
            matsubara = 2 * (int(params[i]) + 1) * np.pi / beta
            file_name.write(str(matsubara))
        else:
            file_name.write(params[i])
        file_name.write(' ')
    file_name.write('\n')

def rewrite_Gamma():
    f  = open("Gamma4.out", "r")
    f0 = open("Gamma_4_0.dat", "w")
    f1 = open("Gamma_4_1.dat", "w")
    f2 = open("Gamma_4_2.dat", "w")
    f3 = open("Gamma_4_3.dat", "w")
    f4 = open("Gamma_4_4.dat", "w")
    f5 = open("Gamma_4_5.dat", "w")
    lines = f.readlines()

    for line in lines:
        params = line.split()
        if(int(params[0]) == int(0)):
            write_Gamma_in_file(f0, params)
        
        if(int(params[0]) == int(1)):
            write_Gamma_in_file(f1, params)
        
        if(int(params[0]) == int(2)):
            write_Gamma_in_file(f2, params)
        
        if(int(params[0]) == int(3)):
            write_Gamma_in_file(f3, params)
        
        if(int(params[0]) == int(4)):
            write_Gamma_in_file(f4, params)
        
        if(int(params[0]) == int(5)):
            write_Gamma_in_file(f5, params)

    f.close()
    f0.close()
    f1.close()
    f2.close()
    f3.close()
    f4.close()
    f5.close()

def rewrite_G():
    f  = open("G4.out", "r")
    f0 = open("G4_0.dat", "w")
    f1 = open("G4_1.dat", "w")
    f2 = open("G4_2.dat", "w")
    f3 = open("G4_3.dat", "w")
    f4 = open("G4_4.dat", "w")
    f5 = open("G4_5.dat", "w")
    f6 = open("chi0000.dat", "w")
    lines = f.readlines()

    for line in lines:
        params = line.split()
        if(int(params[0]) == int(0)):
            write_G_in_file(f0, f6, params)
        
        if(int(params[0]) == int(1)):
            write_G_in_file(f1, f6, params)
        
        if(int(params[0]) == int(2)):
            write_G_in_file(f2, f6, params)
        
        if(int(params[0]) == int(3)):
            write_G_in_file(f3, f6, params)
        
        if(int(params[0]) == int(4)):
            write_G_in_file(f4, f6, params)

        if(int(params[0]) == int(5)):
            write_G_in_file(f5, f6, params)


    f.close()
    f0.close()
    f1.close()
    f2.close()
    f3.close()
    f4.close()
    f5.close()
    f6.close()

def plot():
    subprocess.call(['./plot_vertex4_3D_00_1.script'])
    subprocess.call(['./plot_vertex4_3D_05_1.script'])
    subprocess.call(['./plot_vertex4_3D_00_2.script'])
    subprocess.call(['./plot_vertex4_3D_05_2.script'])

    subprocess.call(['./plot_G4_3D_00_1.script'])
    subprocess.call(['./plot_G4_3D_05_1.script'])
    subprocess.call(['./plot_G4_3D_00_2.script'])
    subprocess.call(['./plot_G4_3D_05_2.script'])

    print "rm *.pdf"
    subprocess.call("rm *.pdf", shell = True)

    print "Convert from eps to pdf"
    subprocess.call("epstopdf Gamma_4_0_1.eps Gamma_4_0_1.pdf", shell = True)
    subprocess.call("epstopdf Gamma_4_0_2.eps Gamma_4_0_2.pdf", shell = True)
    subprocess.call("epstopdf Gamma_4_5_1.eps Gamma_4_5_1.pdf", shell = True)
    subprocess.call("epstopdf Gamma_4_5_2.eps Gamma_4_5_2.pdf", shell = True)

    subprocess.call("epstopdf G4_0_1.eps G4_0_1.pdf", shell = True)
    subprocess.call("epstopdf G4_0_2.eps G4_0_2.pdf", shell = True)
    subprocess.call("epstopdf G4_5_1.eps G4_5_1.pdf", shell = True)
    subprocess.call("epstopdf G4_5_2.eps G4_5_2.pdf", shell = True)

    print "rm *.eps"
    subprocess.call("rm *.eps", shell = True)

rewrite_Gamma()
rewrite_G()
plot()
