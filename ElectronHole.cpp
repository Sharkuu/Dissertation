//
// Created by olav on 14.10.2016.
//

#include "ElectronHole.h"


ElectronHole::ElectronHole(std::vector<double> pos) {
    this->position.push_back(pos[0]);
    this->position.push_back(pos[1]);
    this->position.push_back(pos[2]);
}

ElectronHole::~ElectronHole() {}