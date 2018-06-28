//
// Created by Cooper on 4/12/18.
//

#ifndef VERTEX_CHI_H
#define VERTEX_CHI_H

#include <vector>
#include <complex>

class Chi {
public:
    Chi(std::vector<std::vector<std::complex<double>>> func);

    std::vector <std::vector <std::complex <double>>> function;
public:

    std::complex <double> getValue(std::complex <double> mats1,
                                   std::complex <double> mats2,
                                   std::complex <double> mats3);

};


#endif //VERTEX_CHI_H
