#include "neuron.h"
#include "transition.h"
#include "inputneuron.h"
#include "simpleneuralnetwork.h"
#include <iostream>
Neuron::Neuron()
{

}

Neuron::~Neuron()
{
	for(Transition *transition : m_backTransitions)
	{
		delete transition;
	}
}

Transition *Neuron::createTransition(Neuron *to, const double &value)
{
	Transition *transition = new Transition(this, to, value);
	return transition;
}

void Neuron::executeValue()
{
	if(m_backTransitions.size() == 0)
		return;
	m_nonSigmoidValue = 0;
	for(Transition *transition : m_backTransitions)
	{
		Neuron *neuron = transition->from();

		neuron->executeValue();

		m_nonSigmoidValue += neuron->value() * transition->value();
	}

	m_value = sigmoid(m_nonSigmoidValue);
}

void Neuron::learn(const double &error, const double &learningRate)
{
	double weightDelta = error * sigmoid_dx(m_value);
	for(Transition *transition : m_backTransitions)
	{
		Neuron *neuron = transition->from();
		double value = transition->m_value;

		value = value - neuron->value() * weightDelta * learningRate;
		transition->m_value = value;

		double t_error = value * weightDelta;

		neuron->learn(t_error, learningRate);
	}
}

double Neuron::value() const
{
	return m_value;
}

double Neuron::nonSigmoidValue() const
{
	return m_nonSigmoidValue;
}

std::vector<Transition *> &Neuron::forwardTransitions()
{
	return m_forwardTransitions;
}

std::vector<Transition *> &Neuron::backTransitions()
{
	return m_backTransitions;
}
