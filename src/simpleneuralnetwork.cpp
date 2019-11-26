#include "simpleneuralnetwork.h"
#include "transition.h"
#include <cstdlib>

SimpleNeuralNetwork::SimpleNeuralNetwork(std::vector<InputNeuron *> inputNeurones,
										 Neuron *resultNeuron,
										 const double learningRate)
{
	m_inputNeurones = inputNeurones;
	m_resultNeuron = resultNeuron;
	m_learningRate = learningRate;
}

SimpleNeuralNetwork::SimpleNeuralNetwork(const NeuroneLinks &neuroneLinks,
										 const double learningRate)
	: SimpleNeuralNetwork(neuroneLinks.inputNeurones(),
						  neuroneLinks.resultNeuron(),
						  learningRate)
{ }

SimpleNeuralNetwork::~SimpleNeuralNetwork()
{
	delete m_resultNeuron;
}
#include <iostream>
void SimpleNeuralNetwork::execute(const InputValue &inputValues)
{
	if(inputValues.values().size() != m_inputNeurones.size())
		throw "Input values size != input neurones size";

	unsigned long long i = 0;
	for(InputNeuron *neuron : m_inputNeurones)
	{
		neuron->m_value = inputValues.values()[i++];

	}
	m_resultNeuron->executeValue();

}

void SimpleNeuralNetwork::learn(const InputValue &inputValues)
{
	if(logicResult() == inputValues.expected())
		return;
	m_error = m_resultNeuron->value() - inputValues.expected();

	double weightDelta = m_error * sigmoid_dx(m_resultNeuron->m_value);

	m_resultNeuron->learn(weightDelta, m_learningRate);
}

Neuron *SimpleNeuralNetwork::resultNeuron() const
{
	return m_resultNeuron;
}

double sigmoid(const double &x, const double &a)
{
	const double E = 2.7182818284590452353602874713527;
	double result = 1.0 / (1.0 + pow(E, -(a * x)));
	return result * 1;
}

double sigmoid_dx(const double &x)
{
	return x * (1 - x);
}
