//
// Created by olav on 12.10.2016.
//

#ifndef DISSERTATION_FUNCTIONS_H
#define DISSERTATION_FUNCTIONS_H

#include "Electron.h"
#include "Trap.h"
#include <cstdlib>
#include <iostream>
#include <vector>

void createElectrons(std::vector<Electron> &electrons);

void createTraps(std::vector<Trap> &traps);

template<typename T>
void printVector(T vector) {
    for (auto i : vector)
        std::cout << i << ' ';
    std::cout << std::endl;

}


#endif //DISSERTATION_FUNCTIONS_H
