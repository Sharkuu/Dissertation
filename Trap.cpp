//
// Created by olav on 10.10.2016.
//

#include "Trap.h"

Trap::Trap(double x, double y, double z) {
    this->position.push_back(x);
    this->position.push_back(y);
    this->position.push_back(z);
}

Trap::~Trap() { }

bool Trap::isOccupied() {
    if (this->electron != NULL)
        return true;
    return false;

}

void Trap::setElectron(Electron electron1) {
    electron1.setX(this->position[0]);
    electron1.setY(this->position[1]);
    electron1.setZ(this->position[2]);
    this->electron = &electron1;
}

std::ostream & operator <<( std::ostream & s, const Trap & v )
{
    return s << '<' << v.position[0] << ',' << v.position[1] << ',' << v.position[2] << '>';
}

