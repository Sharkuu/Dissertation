//
// Created by olav on 14.10.2016.
//

#include "ElectronHole.h"


ElectronHole::ElectronHole(std::vector<double> pos, Trap trap) {
    this->trap = &trap;
    this->position.push_back(pos[0]);
    this->position.push_back(pos[1]);
    this->position.push_back(pos[2]);
}

void ElectronHole::nullTrap() {
    this->trap = NULL;
}

ElectronHole::~ElectronHole() {
    //delete this->trap;
}

std::ostream &operator<<(std::ostream &s, const ElectronHole &v) {
    return s << '<' << v.position[0] << ',' << v.position[1] << ',' << v.position[2] << '>' << std::endl;
}