#include <iostream>
#include <vector>
#include <ctime>

#include "simpleneuralnetwork.h"

void example1();
void example2();

int main(int argc, char* argv[])
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	std::cout << "EXAMPLE 1" << std::endl;
	example1();
	std::cout << std::endl << std::endl;

	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::cout << "EXAMPLE 2" << std::endl;
	example2();
	std::cout << std::endl << std::endl;

 	return 0;
}

void example1()
{
	const int EPOCHS = 100000, VALUES_SIZE = 8;

	NeuroneLinks links;
	links.setInputValuesCount(3);
	links.setIntermediateCounts({2});
	links.createFillLinks();
	SimpleNeuralNetwork nn(links, 0.07);

	InputValue values[VALUES_SIZE] = {
		{ {0,0,0}, 0 },
		{ {1,0,0}, 0 },
		{ {0,1,0}, 0 },
		{ {0,0,1}, 1 },
		{ {1,1,0}, 0 },
		{ {0,1,1}, 1 },
		{ {1,0,1}, 1 },
		{ {1,1,1}, 1 }
	};

	for(int i = 0; i < EPOCHS; i++)
	{
		InputValue value = values[rand() % VALUES_SIZE];
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
}

void example2()
{
	const int EPOCHS = 100000, VALUES_SIZE = 8;

	InputNeuron *v1 = new InputNeuron;
	InputNeuron *v2 = new InputNeuron;
	InputNeuron *v3 = new InputNeuron;

	std::vector<InputNeuron *> inputNeurones = {v1, v2, v3};

	Neuron *m1 = new Neuron();
	Neuron *m2 = new Neuron();

	Neuron *resultNeuron = new Neuron();

	v1->createTransition(m1, std::rand() % 100 / 100.0);
	v2->createTransition(m1, std::rand() % 100 / 100.0);
	v3->createTransition(m1, std::rand() % 100 / 100.0);

	v1->createTransition(m2, std::rand() % 100 / 100.0);
	v2->createTransition(m2, std::rand() % 100 / 100.0);
	v3->createTransition(m2, std::rand() % 100 / 100.0);

	m1->createTransition(resultNeuron, std::rand() % 100 / 100.0);
	m2->createTransition(resultNeuron, std::rand() % 100 / 100.0);

	SimpleNeuralNetwork nn(inputNeurones, resultNeuron, 0.1);

	InputValue values[VALUES_SIZE] = {
		{ {0,0,0}, 0 },
		{ {1,0,0}, 0 },
		{ {0,1,0}, 0 },
		{ {0,0,1}, 1 },
		{ {1,1,0}, 0 },
		{ {0,1,1}, 1 },
		{ {1,0,1}, 1 },
		{ {1,1,1}, 1 }
	};

	for(int i = 0; i < EPOCHS; i++)
	{
		InputValue value = values[rand() % VALUES_SIZE];
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
}
