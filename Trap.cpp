//
// Created by olav on 10.10.2016.
//

#include "Trap.h"

Trap::Trap(double x, double y, double z) {
    this->x_pos = x;
    this->y_pos = y;
    this->z_pos = z;
}

Trap::~Trap() { }

bool Trap::isOccupied() {
    if (this->electron != NULL)
        return true;
    return false;

}

void Trap::setElectron(Electron electron1) {
    electron1.setX(this->x_pos);
    electron1.setY(this->y_pos);
    electron1.setZ(this->z_pos);
    this->electron = &electron1;
}

std::ostream & operator <<( std::ostream & s, const Trap & v )
{
    return s << '<' << v.x_pos << ',' << v.y_pos << ',' << v.z_pos << '>';
}

