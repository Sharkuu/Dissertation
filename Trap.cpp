//
// Created by olav on 10.10.2016.
//
/*
 *
 * @TODO
 * rekombinacja dziura-elektorn
 * prawdopodobienstwo tunelowania
 *
 * */
#include "Trap.h"

Trap::Trap(std::vector<double> pos) {
    this->position.push_back(pos[0]);
    this->position.push_back(pos[1]);
    this->position.push_back(pos[2]);
}

Trap::~Trap() {}

bool Trap::isOccupied() const{
    if (this->electron){
        return true;}
    return false;

}
Electron* Trap::getElectron() const{
    if (this->electron)
        return this->electron;
    return NULL;
}

void Trap::removeElectron() {
    this->electron->setX(0);
    this->electron->setY(0);
    this->electron->setZ(0);
    this->electron = NULL;

}

void Trap::setElectron(Electron *electron1) {
    this->electron = electron1;
}

std::ostream &operator<<(std::ostream &s, const Trap &v) {
    return s << '<' << v.position[0] << ',' << v.position[1] << ',' << v.position[2] << "> " << std::endl;
}

