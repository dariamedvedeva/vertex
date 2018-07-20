//
// Created by Cooper on 4/12/18.
//

#include <complex>
#include <iostream>
#include "Vertex4.h"

Vertex4::Vertex4(Chi& Chi4, GF& GF13, GF& GF24,
                 GF& GF14, GF& GF23, double beta) :
        Chi4(Chi4), GF13(GF13), GF24(GF24), GF14(GF14), GF23(GF23), beta(beta){}
    // matsubata1 - bosonic \omega
    // matsubara2 - fermionic \nu
    // matsubara3 - fermionic \nu '
std::complex <double> Vertex4::value(std::complex<double> matsubara1, std::complex<double> matsubara2,
                                     std::complex<double> matsubara3) {

    std::complex <double> Value = Chi4.getValue(matsubara1, matsubara2, matsubara3);

    // \delta_{\omega}
    if(matsubara1 == std::complex <double> (0.0, 0.0)) {
       Value -= beta * GF13.getValue(matsubara2) * GF23.getValue(matsubara3);
    }

    // \delta_{ \nu \nu'}
    if(matsubara2 == matsubara3) {
        Value += beta * GF13.getValue(matsubara2 + matsubara1) * GF24.getValue(matsubara2);
    }

 //   Value = Value / (GF13.getValue(matsubara2 + matsubara1) * GF13.getValue(matsubara2)
 //            * GF13.getValue(matsubara3) * GF13.getValue(matsubara3 + matsubara1) );

    return Value;
}