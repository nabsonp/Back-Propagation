//
//  rede-neural.cpp
//  rede-neural-simples-cpp
//
//  Created by Fernanda Serra on 02/08/18.
//  Copyright © 2018 Fernanda Serra. All rights reserved.
//
using namespace std;
#include "NeuralNetwork.hpp"
#include "NeuronLayer.hpp"
#include "Neuron.hpp"
#include <stdio.h>
NeuralNetwork::NeuralNetwork(int num_inputs,
                               int num_hidden,
                               int num_outputs,
                               std::vector<double> hidden_layer_weights,
                               double hidden_layer_bias,
                               std::vector<double> output_layer_weights,
                               double output_layer_bias)
{
    this->num_inputs = num_inputs;
    this->hidden_layer = NeuronLayer(num_hidden, hidden_layer_bias);
    this->output_layer = NeuronLayer(num_hidden, hidden_layer_bias);
    this->init_weights_from_inputs_to_hidden_layer_neurons(hidden_layer_weights);
    this->init_weights_from_hidden_layer_neurons_to_output_layer_neurons(output_layer_weights);
}

void NeuralNetwork::init_weights_from_inputs_to_hidden_layer_neurons(vector<double> hidden_layer_weights)
{
    double weight_num = 0;
    for(int i = 0; i <= (hidden_layer.neurons).size();i++)
    {
        for(int j = 0; j <= num_inputs; j++)
        {
            if(hidden_layer_weights.empty())
            {
                //hidden_layer.neurons[i].weights.[
            }
        }
    }
}
void NeuralNetwork::inspect()
{
    printf("------");
    printf("* Inputs: {}".format(num_inputs));
    printf("------");
    printf("Hidden Layer");
    hidden_layer.inspect();
    printf("------");
    printf("* Output Layer");
    output_layer.inspect();
    printf("------");
}
double NeuralNetwork::feed_forward(vector<double>inputs)
{
    hidden_layer_outputs = this->hidden_layer.feed_forward(inputs);
    return output_layer.feed_forward(hidden_layer_outputs);
}
void NeuralNetwork::train()
{
    feed_forward(training_inputs);
    pd_errors_wrt_output_neuron_total_net_input = [0] * (output_layer.neurons).size();
    for(int i = 0 ; i <= output_layer.neurons.size(); i++)
    {
        pd_errors_wrt_output_neuron_total_net_input[o] = output_layer.neurons[i].calculate_pd_error_wrt_total_net_input(training_outputs[i]);
        pd_errors_wrt_hidden_neuron_total_net_input = [0] * (hidden_layer.neurons).size();
    }
    for(int i = 0; i <= (hidden_layer.neurons).size(); i++)
    {
        double d_error_wrt_hidden_neuron_output = 0;
        for(int j = 0; j <= output_layer.neurons; j++)
        {
            d_error_wrt_hidden_neuron_output += pd_errors_wrt_output_neuron_total_net_input[i] * output_layer.neurons[i].weights[j];
        }
        pd_errors_wrt_hidden_neuron_total_net_input[i] = d_error_wrt_hidden_neuron_output * hidden_layer.neurons[i].calculate_pd_total_net_input_wrt_input();
    }
    for(int i = 0; i <= (output_layer.neurons).size(); i++)
    {
        for(int j = 0; j <= (output_layer.neurons[i].weights).size(); j++)
        {
            pd_error_wrt_weight = pd_errors_wrt_output_neuron_total_net_input[i] * output_layer.neurons[i].calculate_pd_total_net_input_wrt_weight(j);
            self.output_layer.neurons[i].weights[j] -= LEARNING_RATE * pd_error_wrt_weight;
            
        }
    }
    for(int i = 0; i<= (hidden_layer.neurons).size(); i++)
    {
        for(int j = 0; j <= (hidden_layer.neurons[i].weights); j++)
        {
            
            pd_error_wrt_weight = pd_errors_wrt_hidden_neuron_total_net_input[i] * self.hidden_layer.neurons[i].calculate_pd_total_net_input_wrt_weight(j);
            
            self.hidden_layer.neurons[i].weights[j] -= self.LEARNING_RATE * pd_error_wrt_weight;
        }
    }
}

double NeuralNetwork::calculate_total_error(std::vector<std::vector<std::vector<double>>> training_sets)
{
    total_error = 0;
    for(int i = 0; i <= (training_sets).size(); i++)
    {
        training_inputs = training_outputs = training_sets[i];
        feed_forward(training_inputs);
        for(int j = 0; j <= (training_outputs).size(); j++)
        {
            total_error += output_layer.neurons[j].calculate_error(training_outputs[j]);
        }
    }
    return total_error;
}
