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

bool Trap::isOccupied() {
    if (this->electron != NULL){
        return true;}
    return false;

}

void Trap::removeElectron() {
    this->electron = NULL;
}

void Trap::setElectron(Electron *electron1) {
    this->electron = electron1;
}

std::ostream &operator<<(std::ostream &s, const Trap &v) {
    return s << '<' << v.position[0] << ',' << v.position[1] << ',' << v.position[2] << "> " << std::endl;
}

