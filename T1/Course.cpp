#include "Course.h"
#include <iostream>

#include "Auxiliar.cpp"

Course::Course(std::string name):
_name{name}
{
    curriculum.addVertex(Vertex{"INE5402", "Programação Orientada a Objetos I", 6});
    curriculum.addVertex(Vertex{"INE5403", "Matemática Discreta para Computação", 6});
    curriculum.addVertex(Vertex{"MTM3100", "Cálculo 1", 4});
    curriculum.addVertex(Vertex{"EEL5105", "Circuitos e Técnicas Digitais", 5});
    curriculum.addVertex(Vertex{"INE5401", "Introdução à Computação", 2});

    curriculum.addVertex(Vertex{"INE5404", "Programação Orientada a Objetos II", 6});
    curriculum.connect("INE5402", "INE5404");
    curriculum.addVertex(Vertex{"INE5405", "Probabilidade e Estatística", 5});
    curriculum.connect("MTM3100", "INE5405");
    curriculum.addVertex(Vertex{"MTM3102", "Cálculo 2", 4});
    curriculum.connect("MTM3100", "MTM3102");
    curriculum.addVertex(Vertex{"MTM5512", "Geometria Analítica", 4});
    curriculum.addVertex(Vertex{"INE5406", "Sistemas Digitais", 5});
    curriculum.connect("EEL5105", "INE5406");
    curriculum.addVertex(Vertex{"INE5407", "Ciência, Tecnologia e Sociedade", 3});

    curriculum.addVertex(Vertex{"INE5408", "Estruturas de Dados", 6});
    curriculum.connect("INE5404", "INE5408");
    curriculum.addVertex(Vertex{"INE5410", "Programação Concorrente", 4});
    curriculum.connect("INE5404", "INE5410");
    curriculum.addVertex(Vertex{"INE5409", "Cálculo Numérico para Computação", 4});
    curriculum.connect("MTM3102", "INE5409");
    curriculum.connect("MTM5512", "INE5409");
    curriculum.addVertex(Vertex{"MTM5245", "Álgebra Linear", 4});
    curriculum.connect("MTM5512", "MTM5245");
    curriculum.addVertex(Vertex{"INE5411", "Organização de Computadores", 6});
    curriculum.connect("INE5406", "INE5411");

    curriculum.addVertex(Vertex{"INE5417", "Engenharia de Software I", 5});
    curriculum.connect("INE5408", "INE5417");
    curriculum.addVertex(Vertex{"INE5413", "Grafos", 4});
    curriculum.connect("INE5408", "INE5413");
    curriculum.connect("INE5403", "INE5413");
    curriculum.addVertex(Vertex{"INE5415", "Teoria da Computação", 4});
    curriculum.connect("INE5408", "INE5415");
    curriculum.connect("INE5403", "INE5415");
    curriculum.addVertex(Vertex{"INE5416", "Paradigmas de Programação", 5});
    curriculum.connect("INE5408", "INE5416");
    curriculum.addVertex(Vertex{"INE5412", "Sistemas Operacionais I", 4});
    curriculum.connect("INE5410", "INE5412");
    curriculum.connect("INE5411", "INE5412");
    curriculum.addVertex(Vertex{"INE5414", "Redes de Computadores I", 4});
    curriculum.connect("INE5404", "INE5414");
    
    curriculum.addVertex(Vertex{"INE5419", "Engenharia de Software II", 4});
    curriculum.connect("INE5417", "INE5419");
    curriculum.addVertex(Vertex{"INE5423", "Banco de Dados I", 4});
    curriculum.connect("INE5408", "INE5423");
    curriculum.addVertex(Vertex{"INE5421", "Linguagens Formais e Compiladores", 4});
    curriculum.connect("INE5415", "INE5421");
    curriculum.addVertex(Vertex{"INE5420", "Computação Gráfica", 4});
    curriculum.connect("INE5408", "INE5420");
    curriculum.connect("MTM3102", "INE5420");
    curriculum.connect("MTM5245", "INE5420");
    curriculum.addVertex(Vertex{"INE5418", "Computação Distribuída", 4});
    curriculum.connect("INE5412", "INE5418");
    curriculum.connect("INE5414", "INE5418");
    curriculum.addVertex(Vertex{"INE5422", "Redes de Computadores II", 4});
    curriculum.connect("INE5414", "INE5422");

    curriculum.addVertex(Vertex{"INE5453", "Introdução ao TCC", 1});
    curriculum.connect("INE5417", "INE5453");
    curriculum.addVertex(Vertex{"INE5427", "Planejamento e Gestão de Projetos", 4});
    curriculum.connect("INE5417", "INE5427");
    curriculum.addVertex(Vertex{"INE5426", "Construção de Compiladores", 4});
    curriculum.connect("INE5421", "INE5426");
    curriculum.addVertex(Vertex{"INE5425", "Modelagem e Simulação", 4});
    curriculum.connect("INE5405", "INE5425");
    curriculum.addVertex(Vertex{"INE5430", "Inteligência Artificial", 4});
    curriculum.connect("INE5405", "INE5430");
    curriculum.connect("INE5413", "INE5430");
    curriculum.connect("INE5416", "INE5430");
    curriculum.addVertex(Vertex{"INE5424", "Sistemas Operacionais II", 4});
    curriculum.connect("INE5412", "INE5424");

    curriculum.addVertex(Vertex{"INE5433", "Trabalho de Conclusão de Curso I (TCC)", 6});
    curriculum.connect("INE5453", "INE5433");
    curriculum.connect("INE5427", "INE5433");
    curriculum.addVertex(Vertex{"INE5432", "Banco de Dados II", 4});
    curriculum.connect("INE5423", "INE5432");
    curriculum.addVertex(Vertex{"INE5429", "Segurança em Computação", 4});
    curriculum.connect("INE5403", "INE5429");
    curriculum.connect("INE5414", "INE5429");
    curriculum.addVertex(Vertex{"INE5431", "Sistemas Multimídia", 4});
    curriculum.connect("INE5414", "INE5431");
    curriculum.addVertex(Vertex{"INE5428", "Informática e Sociedade", 4});
    curriculum.connect("INE5407", "INE5428");

    curriculum.addVertex(Vertex{"INE5434", "Trabalho de Conclusão de Curso II (TCC)", 9});
    curriculum.connect("INE5433", "INE5434");
}

Course::~Course() {
    //destrutor
}

std::string Course::name() {
    return _name;
}

void Course::makePlan() {
    //std::unordered_set<std::string> semester;
    //std::vector<Vertex> postponed;
    int semHours = 0;
    int semNumber = 1;
    bool nextSem = false;

    Digraph copyCurriculum = curriculum;
    std::cout << "Digite o código das disciplinas já cursadas:\n";
    std::cout << "(um código por linha, vazio para terminar)\n";
    std::string input = "0";
    std::string end = "";
    while (input.compare(end) != 0) {
        std::getline(std::cin, input);
        if (input.compare(end) != 0) {
            Vertex x = Vertex{input, "", 0};
            copyCurriculum.rmVertex(x);
        }
    }

    std::vector<Vertex> topologicalOrder = copyCurriculum.topologicalOrder();
    std::cout << "Recomendação para o " << semNumber << "º semestre:\n";
    for (auto i = 0u; i < topologicalOrder.size(); i++) {
        auto disc = topologicalOrder[i];
        nextSem = (semHours + disc.hours() > 30);
        if (!nextSem) {
            semHours += disc.hours();
            std::cout << disc.toString() << std::endl;
            if (i == topologicalOrder.size()-1)
                std::cout << "Carga Horária: " << semHours << " h/semana\n";
        } else {
            std::cout << "Carga Horária: " << semHours << " h/semana\n";
            semNumber++;
            if (i != topologicalOrder.size()-1)
                std::cout << "\nRecomendação para o " << semNumber << "º semestre:\n";
            semHours = 0;
        }
    }
}