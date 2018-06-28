//
// Created by Cooper on 4/12/18.
//

#ifndef VERTEX_VERTEX4_H
#define VERTEX_VERTEX4_H

#include <complex>
#include "Chi.h"
#include "GF.h"

class Vertex4 {
public:
    Chi Chi4;
    GF &GF13;
    GF &GF24;
    GF &GF14;
    GF &GF23;
    double beta;

public:
    Vertex4(Chi& Chi4, GF& GF13, GF& GF24, GF& GF14, GF& GF23, double beta);

    std::complex <double> value(std::complex <double> matsubara1,
                                std::complex <double> matsubara2,
                                std::complex <double> matsubara3);
};


#endif //VERTEX_VERTEX4_H
