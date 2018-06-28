//
// Created by Cooper on 4/12/18.
//

#include <complex>
#include <iostream>
#include "Vertex3.h"

Vertex3::Vertex3(GF& gf_nu, GF& gf_nu_omega,
                 std::vector< std::vector < std::complex<double>>> G_nu_omega,
                 GF& Chi_ch, std::complex<double> g_sum, double beta) :
        gf_nu(gf_nu), gf_nu_omega(gf_nu_omega), G_nu_omega(G_nu_omega), Chi_ch(Chi_ch), g_sum(g_sum), beta(beta){}
    /*
     * matsubata1 - bosonic \omega
     * matsubara2 - fermionic \nu
     */

std::complex <double> Vertex3::value(std::complex<double> matsubara1, std::complex<double> matsubara2) {


    std::complex <double> Value = std::complex<double> (0.0, 0.0);
    std::complex <double> G     = std::complex<double> (0.0, 0.0);

 //   std::cout << "Bos fr = " << matsubara1 << "; ferm freq = " << matsubara2 << std::endl;

        for (int i = 0; i < G_nu_omega.size(); i++) {
            if ((matsubara1 == G_nu_omega[i][0]) && (matsubara2 == G_nu_omega[i][1]) ) {
                G = G_nu_omega[i][2];
                G = (2.0 / beta) * G;
                break;
            }
        }

    //    std::cout << "G[][] = " << G << std::endl;
        Value = G;

//        std::cout << gf_nu.getValue(matsubara2) << " " << gf_nu_omega.getValue(matsubara2 + matsubara1)
//                  <<  " " << Chi_ch.getValue(matsubara1) <<std::endl;


    if (matsubara1 == std::complex<double> (0.0, 0.0)) {
        std::complex <double> delta_part(0.0, 0.0);
        delta_part = gf_nu.getValue(matsubara2);
        //sum_nu g(nu) = (5.06326e-14,-61.506)
        delta_part = delta_part * g_sum;
        delta_part = 2.0 * delta_part;
        Value -= delta_part;
    }

    Value = Value / (gf_nu.getValue(matsubara2) * gf_nu_omega.getValue(matsubara2 + matsubara1)
                     * Chi_ch.getValue(matsubara1));

    return Value;
}