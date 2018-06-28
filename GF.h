//
// Created by Cooper on 4/11/18.
//

#include <vector>
#include <complex>

#ifndef VERTEX_GF_H
#define VERTEX_GF_H

class GF {
public:
    std::vector <std::vector <std::complex <double>>> function;

public:
    GF(std::vector <std::vector <std::complex <double>>> func);

    std::complex <double> getValue(std::complex <double> mats1);

    void print_function();
};


#endif //VERTEX_GF_H
