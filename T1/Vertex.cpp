#include "Vertex.h"
#include <sstream>

Vertex::Vertex() {
    
}

Vertex::Vertex(std::string code, std::string name, int hours) :
	_code(code),
	_name(name),
	_hours(hours)
{}

Vertex::~Vertex() {
	//destrutor
}

std::string Vertex::code() const {
	return _code;
}

std::string Vertex::name() {
	return _name;
}

int Vertex::hours() {
	return _hours;
}

std::string Vertex::toString() const {
	std::stringstream ss;
	ss << _code << ": " << _name;
	return ss.str();
}