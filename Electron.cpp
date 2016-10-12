//
// Created by olav on 10.10.2016.
//

#include "Electron.h"

Electron::Electron(double x, double y, double z) {
    this->position.push_back(x);
    this->position.push_back(y);
    this->position.push_back(z);
}

Electron::~Electron() {}



std::ostream &operator<<(std::ostream &s, const Electron &v) {
    return s << '<' << v.position[0] << ',' << v.position[1] << ',' << v.position[2] << '>';
}
