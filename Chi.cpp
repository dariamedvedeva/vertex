//
// Created by Cooper on 4/12/18.
//

#include "Chi.h"
#include <iostream>

Chi::Chi( std::vector <std::vector <std::complex <double>>> func) {
    Chi::function = func;
}

std::complex<double> Chi::getValue(std::complex <double> mats1, std::complex <double> mats2, std::complex <double> mats3){
    std::complex<double> value(0.0, 0.0);

    for (int i = 0; i < Chi::function.size(); i++) {
        if ((mats1 == Chi::function[i][0]) && (mats2 == Chi::function[i][1]) && (mats3 == Chi::function[i][2])) {
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