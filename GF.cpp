//
// Created by Cooper on 4/11/18.
//

#include <iostream>
#include "GF.h"

GF::GF( std::vector <std::vector <std::complex <double>>> func) {
    GF::function = func;
}

void GF::print_function(){
    for(int i = 0; i < GF::function.size(); i++){
        std::cout << "Print function" << std::endl;
        std::cout << GF::function[i][0] << "\t" << GF::function[i][1] << std::endl;
    }
}

std::complex <double> GF::getValue(std::complex<double> mats1) {

    std::complex<double> value (0.0, 0.0);
    std::complex<double> last_matsubara_value(0.0, 0.0);
    last_matsubara_value = GF::function[GF::function.size() - 1][0];

    // a tail
    if(mats1.imag() > last_matsubara_value.imag()){
        std::complex<double> tail(0.0, 0.0);
        tail = std::complex<double>(1.0, 0.0) / mats1;
    //    std::cout << mats1 << " \t" << tail << std::endl;
        value = tail;
    }

    // not a tail
    for(int i = 0; i < GF::function.size(); i++){

        if (std::abs((mats1 - GF::function[i][0]).imag()) <= 0.000001){
            value = GF::function[i][1];
            break;
        } else {
          //  std::cout << "Panic" << std::endl;
            continue;
        }
    }
    return value;
}
