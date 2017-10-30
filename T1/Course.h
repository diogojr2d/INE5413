// Author: Diogo Junior de Souza

#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "Digraph.h"

class Course {
    public:
        Course(std::string name);
        ~Course();

        std::string name();
        void makePlan();

        Digraph curriculum;
    private:
        std::string _name;
};

#endif