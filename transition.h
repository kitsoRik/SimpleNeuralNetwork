#ifndef TRANSITION_H
#define TRANSITION_H

#include <vector>

class Neuron;

class Transition
{

	friend class SimpleNeuralNetwork;
	friend class Neuron;
public:
	Transition(Neuron *from,
			   Neuron *to,
			   const double &value);
	~Transition();

	Neuron *from() const;

	Neuron *to() const;

	double value() const;

private:
	Neuron *m_from;
	Neuron *m_to;
	double m_value;
};

#endif // TRANSITION_H
