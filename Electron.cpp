//
// Created by olav on 10.10.2016.
//

#include "Electron.h"

std::vector < double > Electron::getPosition() {
    std::vector < double > position;
    position.push_back( this->x_pos );
    position.push_back( this->y_pos );
    position.push_back( this->z_pos );
    return position;
}
Electron::Electron(double x, double y, double z) {
    this->x_pos = x;
    this->y_pos = y;
    this->z_pos = z;
}