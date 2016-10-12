//
// Created by olav on 10.10.2016.
//

#include "Electron.h"

Electron::Electron(double x, double y, double z) {
    this->x_pos = x;
    this->y_pos = y;
    this->z_pos = z;
}

Electron::~Electron() {}

std::vector<double> Electron::getPosition() {
    std::vector<double> position;
    position.push_back(this->x_pos);
    position.push_back(this->y_pos);
    position.push_back(this->z_pos);
    return position;
}

std::ostream &operator<<(std::ostream &s, const Electron &v) {
    return s << '<' << v.x_pos << ',' << v.y_pos << ',' << v.z_pos << '>';
}
