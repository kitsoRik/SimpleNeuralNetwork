#ifndef NEURONELINKS_H
#define NEURONELINKS_H

#include "inputneuron.h"

class NeuroneLinks
{
public:
	NeuroneLinks();

	void setInputValuesCount(const int &inputValuesCount);
	void setIntermediateCounts(const std::vector<int> &intermediateCounts);

	void createFillLinks();

	std::vector<InputNeuron *> inputNeurones() const { return m_inputNeurones; }
	Neuron * resultNeuron() const { return m_resultNeuron; }

private:
	int m_inputValuesCount;
	std::vector<int> m_intermediateCounts;

	std::vector<InputNeuron *> m_inputNeurones;
	Neuron * m_resultNeuron;


};

#endif // NEURONELINKS_H
