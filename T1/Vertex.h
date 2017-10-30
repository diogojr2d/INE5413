// Author: Diogo Junior de Souza

#ifndef VERTEX_H
#define VERTEX_H

#include <unordered_set>
#include <string>

class Vertex {
    public:
        Vertex();
        explicit Vertex(std::string code, std::string name, int hours);
        ~Vertex();

        std::string code() const;
        std::string name();
        int hours();

        std::unordered_set<std::string> successors;
        std::unordered_set<std::string> predecessors;

        std::string toString() const;
    private:
        std::string _code;
        std::string _name;
        int _hours;
};

#endif