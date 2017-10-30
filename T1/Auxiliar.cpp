#include <vector>
#include <unordered_map>
#include <iostream>
#include "Vertex.h"

class Auxiliar {
public:
	static void print_map(std::unordered_map<std::string, Vertex> map) {
		for (auto p : map) {
			std::cout << p.second.toString() << std::endl;
		}
	}

	static void print_vector(std::vector<Vertex> vec) {
		for (auto v : vec) {
			std::cout << v.toString() << std::endl;
		}
	}
};