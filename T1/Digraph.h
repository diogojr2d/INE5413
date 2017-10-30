// Author: Diogo Junior de Souza

#ifndef DIGRAPH_H
#define DIGRAPH_H

#include <unordered_map>
#include <vector>
#include "Vertex.h"

class Digraph {
    public:
        Digraph();
        ~Digraph();

        void addVertex(const Vertex& v);
        void rmVertex(Vertex& v);
        void connect(Vertex& v1, Vertex& v2);
        void connect(std::string k1, std::string k2);
        void disconnect(Vertex& v1, Vertex& v2);
        int order();
        std::unordered_map<std::string, Vertex> vertexes();
        Vertex randomVertex();
        std::unordered_map<std::string, Vertex> successors(const Vertex& v);
        std::unordered_map<std::string, Vertex> predecessors(const Vertex& v);
        int inDegree(const Vertex& v);
        int outDegree(const Vertex& v);

        std::vector<Vertex> topologicalOrder();
        void visit(Vertex v, std::vector<Vertex>& order, std::unordered_map<std::string, Vertex>& visited);

        Vertex getVertex(const std::string& code);
    private:
        std::unordered_map<std::string, Vertex> contents;
};

#endif