//
//  Neuron.hpp
//  Back-Propagation
//
//  Created by Nabson Paiva on 02/08/18.
//  Copyright © 2018 Nabson Paiva. All rights reserved.
//

#ifndef Neuron_hpp
#define Neuron_hpp

#include <stdio.h>
#include <vector>
class Neuron{
    public:
        double bias, output;
        std::vector<double> weights;
        std::vector<double> inputs;
        Neuron(double bias);
        double calculate_output(std::vector<double> inputs);
        double squash(double total_net_input);
        double calculate_total_net_input();
        double calculate_error(double target_output);
        double calculate_pd_error_wrt_total_net_input(double target_output);
        double calculate_pd_error_wrt_output(double target_output);
        double calculate_pd_total_net_input_wrt_input();
        double calculate_pd_total_net_input_wrt_weight(int index);
};

#endif /* Neuron_hpp */
