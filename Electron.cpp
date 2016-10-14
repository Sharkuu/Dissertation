//
// Created by olav on 10.10.2016.
//

#include "Electron.h"

Electron::Electron(std::vector<double> pos) {
    this->position.push_back(pos[0]);
    this->position.push_back(pos[1]);
    this->position.push_back(pos[2]);
}

Electron::~Electron() {}

Electron::Electron() {
    this->position.push_back(0);
    this->position.push_back(0);
    this->position.push_back(0);
}


std::ostream &operator<<(std::ostream &s, const Electron &v) {
    return s << '<' << v.position[0] << ',' << v.position[1] << ',' << v.position[2] << '>' << std::endl;
}
