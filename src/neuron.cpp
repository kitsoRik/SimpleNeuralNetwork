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

	for(Transition *transition : m_forwardTransitions)
	{
		transition->m_from = nullptr;
	}

	m_backTransitions.clear();
	m_forwardTransitions.clear();
}

Transition *Neuron::createTransition(Neuron *to, const double &value)
{
	Transition *transition = new Transition(this, to, value);
	return transition;
}
#include <iostream>
void Neuron::executeValue()
{
	if(m_backTransitions.size() == 0)
	{
		return;
	}
	m_nonSigmoidValue = 0;
	for(Transition *transition : m_backTransitions)
	{
		Neuron *neuron = transition->from();

		neuron->executeValue();

		m_nonSigmoidValue += neuron->value() * transition->value();
	}

	m_value = sigmoid(m_nonSigmoidValue);
}

void Neuron::learn(const double &weightDelta, const double &learningRate)
{
	for(Transition *transition : m_backTransitions)
	{
		Neuron *neuron = transition->from();
		double value = transition->m_value;

		value = value - neuron->value() * learningRate * weightDelta;
		transition->m_value = value;

		double t_error = value * weightDelta;

		neuron->learn(weightDelta, learningRate);
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
