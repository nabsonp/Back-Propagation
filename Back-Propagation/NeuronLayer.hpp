//
//  NeuronLayer.hpp
//  Back-Propagation
//
//  Created by Nabson Paiva on 02/08/18.
//  Copyright © 2018 Nabson Paiva. All rights reserved.
//

#ifndef NeuronLayer_hpp
#define NeuronLayer_hpp

#include <stdio.h>
#include <vector>
#include "Neuron.hpp"
class NeuronLayer {
    public:
        double bias;
        std::vector<Neuron> neurons;
        NeuronLayer(int num_neurons, double bias);
        void inspect();
        std::vector<double> feed_forward(std::vector<double> inputs);
        std::vector<double> get_outputs();
};

#endif /* NeuronLayer_hpp */
