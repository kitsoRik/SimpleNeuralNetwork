#include <iostream>
#include <vector>
#include <ctime>

#include "simpleneuralnetwork.h"

int main(int argc, char* argv[])
{
	const int EPOCHS = 100000, VALUES_SIZE = 6;

	InputNeuron *v1 = new InputNeuron;
	InputNeuron *v2 = new InputNeuron;
	InputNeuron *v3 = new InputNeuron;
	InputNeuron *v4 = new InputNeuron;


	std::vector<InputNeuron *> inputNeurones = {v1, v2, v3, v4};

	Neuron *h11 = new Neuron();
	Neuron *h12 = new Neuron();

	Neuron *h21 = new Neuron();
	Neuron *h22 = new Neuron();

	Neuron *resultNeuron = new Neuron();

	v1->createTransition(h11, 0.5);
	v2->createTransition(h11, 0.5);
	v3->createTransition(h11, 0.5);
	v4->createTransition(h11, 0.5);

	v1->createTransition(h12, 0.5);
	v2->createTransition(h12, 0.5);
	v3->createTransition(h12, 0.5);
	v4->createTransition(h12, 0.5);

	h11->createTransition(resultNeuron, 0.5);
	//h11->createTransition(h22, 0.5);
	h12->createTransition(resultNeuron, 0.5);
	//h12->createTransition(h22, 0.5);

	//h21->createTransition(resultNeuron, 0.5);
	//h22->createTransition(resultNeuron, 0.5);

	SimpleNeuralNetwork nn(inputNeurones, resultNeuron, 0.2);

	InputValue values[VALUES_SIZE] = {
		{ {1,1,1,1}, 1 },
		{ {0,0,1,1}, 1 },
		{ {1,1,0,0}, 1 },
		{ {1,0,0,1}, 0 },
		{ {1,0,0,0}, 0 },
		{ {0,1,0,0}, 0 }
	};

	for(int i = 0; i < EPOCHS; i++)
	{
		InputValue value = values[rand() % (VALUES_SIZE - 0)];
		nn.execute(value);
		nn.learn(value);
	}

	for(int i = 0; i < VALUES_SIZE; i++)
	{
		InputValue value = values[i];

		nn.execute(value);

		std::cout << '[';
		for(unsigned long long j = 0; j < value.values().size(); j++)
		{
			 std::cout << value.values()[j] << (j != value.values().size() - 1 ? ", " : "");
		}
		std::cout << "] - ";
		std::cout << "Expected: " << value.expected() <<
					 ", result: " << nn.logicResult() <<
					 ", error: " << nn.error() << std::endl;
	}
 	return 0;
}
