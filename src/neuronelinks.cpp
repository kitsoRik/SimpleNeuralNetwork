#include "neuronelinks.h"

#include <cstdlib>

NeuroneLinks::NeuroneLinks()
{

}

void NeuroneLinks::setInputValuesCount(const int &inputValuesCount)
{
	m_inputValuesCount = inputValuesCount;
}

void NeuroneLinks::setIntermediateCounts(const std::vector<int> &intermediateCounts)
{
	m_intermediateCounts = intermediateCounts;
}

void NeuroneLinks::createFillLinks()
{
	std::vector<Neuron *> currentNeurones;

	for(int i = 0; i < m_inputValuesCount; i++)
	{
		InputNeuron *inputNeuron = new InputNeuron;

		m_inputNeurones.push_back(inputNeuron);
		currentNeurones.push_back(inputNeuron);
	}

	for(int count : m_intermediateCounts)
	{
		std::vector<Neuron *> t_currentNeurones;
		for(int i = 0; i < count; i++)
		{
			Neuron *neuron = new Neuron;

			for(Neuron *backNeuron : currentNeurones)
			{
				backNeuron->createTransition(neuron, std::rand() % 100 / 100.0);
			}

			t_currentNeurones.push_back(neuron);
		}

		currentNeurones = t_currentNeurones;
	}

	m_resultNeuron = new Neuron;

	for(Neuron *backNeuron : currentNeurones)
	{
		backNeuron->createTransition(m_resultNeuron, std::rand() % 100 / 100.0);
	}
}
