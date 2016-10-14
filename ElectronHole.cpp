//
// Created by olav on 14.10.2016.
//

#include "ElectronHole.h"


ElectronHole::ElectronHole(double x, double y, double z) {
    this->position.push_back(x);
    this->position.push_back(y);
    this->position.push_back(z);
}

ElectronHole::~ElectronHole() {}