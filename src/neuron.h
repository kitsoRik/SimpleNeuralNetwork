#ifndef NEURON_H
#define NEURON_H

#include <vector>

class Transition;
class InputNeuron;

class Neuron
{
	friend class SimpleNeuralNetwork;
public:
	Neuron();
	~Neuron();

	Transition *createTransition(Neuron *to, const double &value);

	void executeValue();
	void learn(const double &weightDelta, const double &learningRate);

	double value() const;
	double nonSigmoidValue() const;

	std::vector<Transition *> &forwardTransitions();

	std::vector<Transition *> &backTransitions();

protected:
	double m_nonSigmoidValue;
	double m_value;
	std::vector<Transition *> m_forwardTransitions;
	std::vector<Transition *> m_backTransitions;
};

#endif // NEURON_H
