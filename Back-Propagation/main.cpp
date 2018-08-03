//
//  main.cpp
//  Back-Propagation
//
//  Created by Nabson Paiva on 02/08/18.
//  Copyright © 2018 Nabson Paiva. All rights reserved.
//

#include <iostream>
#include "NeuralNetwork.hpp"
int main(int argc, const char * argv[]) {
    NeuralNetwork nn = NeuralNetwork(2, 2, 2, {0.15, 0.2, 0.25, 0.3},0.35, {0.4, 0.45, 0.5, 0.55}, 0.6);
    for (int i = 0; i < 10000; i++) {
        nn.train({0.05, 0.1}, {0.01, 0.99});
        std::cout.precision(9);
        std::cout.setf(std::ios::fixed);
        std::cout << i << "  " << nn.calculate_total_error({{{0.05, 0.1}, {0.01, 0.99}}});
    }
    return 0;
}
