#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "Course.h"
#include "Vertex.h"
#include "Auxiliar.cpp"

int main(int argc, char **argv) {
	Course computacao {"Ciência da Computação"};

	std::cout << "Ordem topológica do curso de " << computacao.name() << ":\n";
	Auxiliar::print_vector(computacao.curriculum.topologicalOrder());

	std::cout << "\n*** Indicação de disciplinas ***\n";
	computacao.makePlan();

	std::cout << "\nFim do programa\n";

	return 0;
}