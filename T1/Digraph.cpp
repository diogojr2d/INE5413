#include "Digraph.h"
#include <algorithm>
#include <iostream>

#include "Auxiliar.cpp"

Digraph::Digraph() {
    // constructor
}

Digraph::~Digraph() {
	//destructor
}

void Digraph::addVertex(const Vertex& v) {
	if (contents.find(v.code()) != contents.end()) {
		std::cout << "Vértice já existe." << std::endl;
		return;
	}
	contents.insert(std::pair<std::string, Vertex>(v.code(), v));
}

void Digraph::rmVertex(Vertex& v) {
	if (contents.find(v.code()) == contents.end()) {
		std::cout << "Vértice não encontrado." << std::endl;
		return;
	}

	for (auto s : v.successors) {
		disconnect(v, contents.find(s)->second);
	}
	for (auto p : v.predecessors) {
		disconnect(contents.find(p)->second, v);
	}
	contents.erase(v.code());
}

void Digraph::connect(Vertex& v1, Vertex& v2) {
	if (contents.find(v1.code()) == contents.end() || contents.find(v2.code()) == contents.end()) {
		std::cout << "Vértices não encontrados." << std::endl;
		return;
	}
	v1.successors.insert(v2.code());
	v2.predecessors.insert(v1.code());
}

void Digraph::connect(std::string k1, std::string k2) {
	if (contents.find(k1) == contents.end() || contents.find(k2) == contents.end()) {
		std::cout << "Vértices não encontrados." << std::endl;
		return;
	}
	contents.find(k1)->second.successors.insert(k2);
	contents.find(k2)->second.predecessors.insert(k1);
}

void Digraph::disconnect(Vertex& v1, Vertex& v2) {
	if (contents.find(v1.code()) == contents.end() || contents.find(v2.code()) == contents.end()) {
		std::cout << "Vértices não encontrados." << std::endl;
		return;
	}
	v1.successors.erase(v2.code());
	v2.predecessors.erase(v1.code());
}

int Digraph::order() {
	return contents.size();
}

std::unordered_map<std::string, Vertex> Digraph::vertexes() {
	return contents;
}

std::unordered_map<std::string, Vertex> Digraph::successors(const Vertex& v) {
	std::unordered_map<std::string, Vertex> suc;

	if (contents.find(v.code()) == contents.end()) {
		std::cout << "Vértice não encontrado." << std::endl;
		return suc;
	}

	Vertex foundV = contents.find(v.code())->second;
	std::transform(foundV.successors.begin(), foundV.successors.end(),
			std::inserter(suc, suc.begin()),
			[this](const std::string& key) {
				return std::make_pair(key, getVertex(key));
			});
	
	return suc;
}

std::unordered_map<std::string, Vertex> Digraph::predecessors(const Vertex& v) {
	std::unordered_map<std::string, Vertex> pred;

	if (contents.find(v.code()) == contents.end()) {
		std::cout << "Vértice não encontrado." << std::endl;
		return pred;
	}

	Vertex foundV = contents.find(v.code())->second;
	std::transform(foundV.predecessors.begin(), foundV.predecessors.end(),
			std::inserter(pred, pred.begin()),
			[this](const std::string& key){
				return std::make_pair(key, getVertex(key));
			});

	return pred;
}

int Digraph::inDegree(const Vertex& v) {
	if (contents.find(v.code()) == contents.end()) {
		std::cout << "Vértice não encontrado." << std::endl;
		return 0;
	}
	return v.predecessors.size();
}

int Digraph::outDegree(const Vertex& v) {
	if (contents.find(v.code()) == contents.end()) {
		std::cout << "Vértice não encontrado." << std::endl;
		return 0;
	}
	return v.successors.size();
}

Vertex Digraph::randomVertex() {
	return contents.begin()->second;
}


Vertex Digraph::getVertex(const std::string& code) {
    if (contents.find(code) == contents.end()) {
    	throw "Vértice não existe.";
    }
    return contents.find(code)->second;
}

std::vector<Vertex> Digraph::topologicalOrder() {
	std::vector<Vertex> order {};
	std::unordered_map<std::string, Vertex> visited;

	//std::cout << "order vazio:\n";
	//Auxiliar::print_vector(order);

	//std::cout << "visited vazio:\n";
	//Auxiliar::print_map(visited);

	//std::cout << "Iniciando topologicalOrder...\n";
	for (auto v : contents) {
		if (visited.find(v.first) != visited.end())
			continue;
		//std::cout << "v: " << v.first << std::endl;
		visit(v.second, order, visited);
		//std::cout << "fim visit\n";
	}

	std::reverse(order.begin(), order.end());
	//std::cout << "Fim topologicalOrder\n";
	return order;
}

void Digraph::visit(Vertex v, std::vector<Vertex>& order, std::unordered_map<std::string, Vertex>& visited) {
	//std::cout << "Iniciando visit...\n";
	//std::cout << "v: " << v.toString() << std::endl;

	for (auto suc : v.successors) {
		//std::cout << "suc: " << suc << std::endl;
		if (visited.find(suc) == visited.end()) {
			//std::cout << "suc não encontrado, chamando visit again..." << std::endl;
			visit(contents.find(suc)->second, order, visited);
			//std::cout << "saiu visit recursivo\n";
		}
	}
	//std::cout << "saiu for do vertex v: " << v.toString() << std::endl;
	visited.insert(std::pair<std::string, Vertex>(v.code(), v));
	order.push_back(v);
	//std::cout << "order:\n";
	//Auxiliar::print_vector(order);

	//std::cout << "visited:\n";
	//Auxiliar::print_map(visited);	
}