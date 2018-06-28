//
// Created by Cooper on 4/12/18.
//

#ifndef VERTEX_VERTEX3_H
#define VERTEX_VERTEX3_H

#include <complex>
#include "GF.h"

class Vertex3 {
public:
    GF &gf_nu;
    GF &gf_nu_omega;
    std::vector< std::vector < std::complex<double>>> G_nu_omega;
    GF &Chi_ch;
    std::complex<double> g_sum;
    double beta;

public:
    Vertex3(GF& gf_nu, GF& gf_nu_omega,
            std::vector< std::vector < std::complex<double>>> G_nu_omega,
            GF& Chi_ch, std::complex<double> g_sum, double beta);

    std::complex <double> value(std::complex <double> matsubara1,
                                std::complex <double> matsubara2);
};


#endif //VERTEX_VERTEX4_H
