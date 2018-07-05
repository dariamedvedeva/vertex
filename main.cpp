#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <complex>
#include <iomanip>

#include "GF.h"
#include "Chi.h"
#include "Vertex3.h"
#include "Vertex4.h"


std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems)
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim))
    {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> split(const std::string &s, char delim)
{
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

std::vector <std::vector <std::complex <double>>> read_function(std::string path){
    /*
     * This function can read all different files with columns of complex numbers
     */

    /*
     * Also it was realized the treatment  for calculation only positive values of fermionic frequencies,
     * but only for single-particle Green's function (4 columns) and General susceptibility (8 columns).
     * Just for tests.
     * This treatment should be removed later.
     */


    std::string s;
    std::ifstream file(path);
    bool print_function = false;
    std::vector <std::vector <std::complex <double>>> container;

    if (file.is_open()) {
        std::cout << std::endl << path << " is opened." << std::endl;
        while (getline(file, s)) {
            std::vector<std::string> sWords;
            sWords = split(s, ' ');

            std::complex < double > new_complex_number;
            std::vector < std::complex < double > > line;
            switch (sWords.size()){
                case 4:
                    for (int i = 0; i < sWords.size(); i += 2) {
                        new_complex_number = std::complex<double>(std::stod(sWords[i]), std::stod(sWords[i + 1]));
                        line.push_back(new_complex_number);
                    }
                    break;
                case 8:
                    if (((std::stod(sWords[3])) >= 0.0) and ((std::stod(sWords[5]) >= 0.0))) {
                        for (int i = 0; i < sWords.size(); i += 2) {
                            new_complex_number = std::complex<double>(std::stod(sWords[i]), std::stod(sWords[i + 1]));
                            line.push_back(new_complex_number);
                        }
                    } else {
                        continue;
                    }
                    break;
                default:
                    std::cout << "Problem: The program can\'t work with this data structure of file " << std::endl;
                    std::cout << path << std::endl;
                    goto stopAllCycles;
            }
            container.push_back(line);
        }

        stopAllCycles:
            std::cout << std::endl;

        file.close();
    } else {
        std::cout << "File is not open." << std::endl;
    }

    /* PRINT */
    if (print_function) {
        std::cout << "Function size = " << container.size() << std::endl;
        std::cout << "Container size = " << container[0].size() << std::endl;

        for (int i = 0; i < container.size(); i++) {
            for (int j = 0; j < container[i].size(); j++) {
                std::cout << container[i][j].real() << " " << container[i][j].imag() << '\t';
            }
            std::cout << std::endl;
        }
    }
    return container;
}

std::vector <std::complex <double>> get_bosonic_freq_from_Chi(
                            std::vector <std::vector < std::complex <double>>> chi){

    /*
     * Bosonic matsubara freguencies was readed from general susceptibility
     */

    std::vector <std::complex <double>>  boson_matsubara;
    int j = 0;
    for (int i = 0; i < chi.size(); i++){
        if ((j != 0) && (chi[i][0] != boson_matsubara[j - 1])) {
            boson_matsubara.push_back(chi[i][0]);
            j++;
        }
        else if (j == 0){
            boson_matsubara.push_back(chi[i][0]);
            j++;
        }
    }
    return boson_matsubara;
}

std::vector <std::complex <double>> get_fermionic_freq_from_GF(
                            std::vector <std::vector < std::complex <double>>> G){
    std::vector <std::complex <double>> ferm_matsubara;
    int j = 0;
    for (int i = 0; i < G.size(); i++){
        if ((j != 0) && (G[i][0] != ferm_matsubara[j - 1])) {
            ferm_matsubara.push_back(G[i][0]);
            j++;
        }
        else if (j == 0){
            ferm_matsubara.push_back(G[i][0]);
            j++;
        }
    }
    return ferm_matsubara;
}


int main() {
    double beta;
    beta = 100.0;

    bool calculate_4leg_vertex              = true;
    bool calculate_3leg_vertex              = true;
    bool calculate_3leg_vertex_from_square  = false;

    /*************/
    /* Functions */
    /*************/

    ////////////////////////////////         POMEROL                     /////////////////////

    std::cout << " POMEROL FUNCTIONS" << std::endl;
    std::vector<std::vector<std::complex<double>>> G;
    G = read_function("/Users/MacBookPro/Dropbox/Notes_vertices/Calculations/U_2_5_fermionic_orbs_in_bath/gw_imag00.dat");
    GF GF1(G);

   // GF1.print_function();

    std::cout << "Size of gw_imag00.dat = " << G.size() << std::endl;

    std::vector<std::vector<std::complex<double>>> X;
    X = read_function("/Users/MacBookPro/Dropbox/Notes_vertices/Calculations/U_2_5_fermionic_orbs_in_bath/chi0000.dat");
    Chi G4(X);

    std::cout << "Size of chi0000.dat = " << X.size() << std::endl;

    ////////////////////////////////         FREQUENCIES                /////////////////////

    std::cout << "FREQUENCIES" << std::endl;
    std::vector<std::complex<double>> bosonic_mats;
    std::vector<std::complex<double>> fermionic_mats;

            /*
            * Fermionic and bosonic frequencies should be reading
            * from the same program output!
            */

    fermionic_mats  = get_fermionic_freq_from_GF(G);
    bosonic_mats    = get_bosonic_freq_from_Chi(X);

    std::cout << "Number of fermionic frequencies " << fermionic_mats.size() << std::endl;
    std::cout << "ferm[0] = " << fermionic_mats[0] <<
              "; ferm[" << fermionic_mats.size() - 1 << "] = " << fermionic_mats[fermionic_mats.size() - 1] << std::endl;

    std::cout << "Number of bosonic frequencies " << bosonic_mats.size() << std::endl;
    std::cout << "bos[0] = " << bosonic_mats[0] <<
              "; ferm[" << bosonic_mats.size() - 1 << "] = " << bosonic_mats[bosonic_mats.size() - 1] << std::endl;



    ////////////////////////////////         EDLib                     /////////////////////

    std::vector<std::vector<std::complex<double>>> Chi_charge;
    Chi_charge = read_function("/Users/MacBookPro/Dropbox/Notes_vertices/Calculations/U_2_5_fermionic_orbs_in_bath/chi_ch_imp.dat");

    for(int n = 0; n < bosonic_mats.size(); n++){
        if(bosonic_mats[n] != Chi_charge[n][0]){
            Chi_charge[n][0] = bosonic_mats[n];
        }
    }
    GF GF_chi_ch(Chi_charge);

    /*
     * Change values of frequencies
     */


    /* 4-leg vertex */

    if (calculate_4leg_vertex) {
        std::cout << "4-leg vertex" << std::endl;
        Vertex4 vertex4(G4, GF1, GF1, GF1, GF1, beta);

        std::complex<double> l;

        std::ofstream fout;
        fout.open("../data/vertex4.dat");

        std::ofstream fout_zero_bos_mats;

        for (int n1 = 0; n1 < bosonic_mats.size(); ++n1) {
            if (n1 == 1) {
                //bool print_zero_bos_mats_separately = true;
             //   std::cout << n1 << std::endl;
            }
            for (int n2 = 0; n2 < fermionic_mats.size(); ++n2) {
                for (int n3 = 0; n3 < fermionic_mats.size(); ++n3) {
             //       std::cout << bosonic_mats[n1] << " " << fermionic_mats[n2] << " " << fermionic_mats[n3] << std::endl;
                    l = vertex4.value(bosonic_mats[n1], fermionic_mats[n2], fermionic_mats[n3]);

                    if (fout.is_open()) {
                        fout << std::scientific << std::setprecision(12) << bosonic_mats[n1].imag() << " "
                             << fermionic_mats[n2].imag() << " " << fermionic_mats[n3].imag() << " "
                             << l.real() << " " << l.imag() << std::endl;
                    }
                }
            }
        }

        fout.close();
    }

    if (calculate_3leg_vertex) {
        /*3-leg vertex*/

        std::cout << "3-leg vertex" << std::endl;

        std::vector<std::vector<std::complex<double>>> G_sum;

        std::ofstream fout3;
        fout3.open("../G_nu_omega.dat");

            /*
             * \sum_{v'} G(w, v, v')
            */

        std::complex<double> value(0.0, 0.0);
        for (int n1 = 0; n1 < bosonic_mats.size(); n1++) {
            for (int n2 = 0; n2 < fermionic_mats.size(); n2++) {
                std::vector<std::complex<double>> line;
                line.push_back(bosonic_mats[n1]);
                line.push_back(fermionic_mats[n2]);

                for (int n3 = 0; n3 < fermionic_mats.size(); ++n3) {
                    value += G4.getValue(bosonic_mats[n1], fermionic_mats[n2], fermionic_mats[n3]);
                }

                line.push_back(value);

                G_sum.push_back(line);

                if ((n1 == 0) and (n2 == 0)) {
                  //  std::cout << "G(n = 0, m = 0) = " << value << std::endl;
                }
                if (fout3.is_open()) {
                    fout3 << std::scientific << std::setprecision(12) << line[0].imag() << " "
                          << line[1].imag() << " " << line[2].real() << " " << line[2].imag()
                          << std::endl;
                }
                value = std::complex <double> (0.0, 0.0);
            }
        }

        fout3.close();


        std::complex<double> g_sum(0.0, 0.0);

        for (int n = 0; n < fermionic_mats.size(); n++) {
            g_sum += GF1.getValue(fermionic_mats[n]);
        }

        std::cout << "sum_nu g(nu) = " << g_sum << std::endl;

        Vertex3 vertex3(GF1, GF1, G_sum, GF_chi_ch, g_sum, beta);

        std::complex<double> m;
        std::ofstream fout2;
        fout2.open("../data/vertex3.dat");

        for (int n1 = 0; n1 < bosonic_mats.size(); n1++) {
            for (int n2 = 0; n2 < fermionic_mats.size(); n2++) {

                m = vertex3.value(bosonic_mats[n1], fermionic_mats[n2]);

                if (fout2.is_open()) {
                    fout2 << std::scientific << std::setprecision(12) << bosonic_mats[n1].imag() << " "
                          << fermionic_mats[n2].imag() << " " << " " << m.real() << " " << m.imag() << std::endl;
                }
            }
        }
        fout2.close();
    }

    if (calculate_3leg_vertex_from_square) {
        std::vector<std::vector<std::complex<double>>> lambda_from_square;

        for(int n1 = 0; n1 < bosonic_mats.size(); n1++){ // for every bosonic frequency
            for(int n2 = 0; n2 < fermionic_mats.size(); n2++){ //for every fermionic frequency

            }
        }
    }
    std::cout << "Finality!" << std::endl;

    return 0;
}
