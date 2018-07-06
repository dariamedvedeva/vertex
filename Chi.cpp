//
// Created by Cooper on 4/12/18.
//

#include "Chi.h"
#include <iostream>

Chi::Chi( std::vector <std::vector <std::complex <double>>> func) {
    Chi::function = func;
}

std::complex<double> Chi::getValue(std::complex <double> mats1, std::complex <double> mats2, std::complex <double> mats3){
    std::complex<double> value(0, 0);
    double tiny = 0.000001;

    for (int i = 0; i < Chi::function.size(); i++) {
        double first = abs(mats1.imag() - Chi::function[i][0].imag());
        double second = abs(mats2.imag() - Chi::function[i][1].imag());
        double third = abs(mats3.imag() - Chi::function[i][2].imag());
        if (( first < tiny ) && (second < tiny) && ( third < tiny) ){
            value = Chi::function[i][3];
        } else {
            continue;
        }
    }

//    if(value == std::complex <double> (0.0, 0.0)) {
//        std::cout << "There is no value for these parameters." << std::endl;
//    }

    return value;
}