#pragma once

#include <cmath>
#include "inputvalue.h"
#include "inputneuron.h"
#include "neuronelinks.h"

double sigmoid(const double& x, const double& a = 1);
double sigmoid_dx(const double& x);

class SimpleNeuralNetwork
{
public:
	SimpleNeuralNetwork(const SimpleNeuralNetwork&) = delete;

	SimpleNeuralNetwork(const NeuroneLinks &neuroneLinks, const double learningRate);
	SimpleNeuralNetwork(std::vector<InputNeuron *> inputNeurones,
						Neuron *resultNeuron,
						const double learningRate = 0.1);

	~SimpleNeuralNetwork();

	void execute(const InputValue &inputValues);
	void learn(const InputValue &inputValues);

	Neuron *resultNeuron() const;

	inline double result() const { return m_resultNeuron->value(); }
	inline bool logicResult(const double &bound = 0.5) const { return result() > bound; }

	inline double error() const { return m_error; }

private:
	double m_nonSigmoidResult;
	Neuron *m_resultNeuron;
	double m_learningRate;

	double m_error;

	std::vector<InputNeuron *> m_inputNeurones;
};
