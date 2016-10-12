//
// Created by olav on 10.10.2016.
//
#include <iostream>
#include "Electron.h"
#include "Trap.h"
#include "Functions.h"

int main() {
    std::vector<Electron> electrons;
    std::vector<Trap> traps;
    createElectrons(electrons);
    printVector(electrons);
    createTraps(traps);
    printVector(traps);
    electrons.clear();
    traps.clear();
    traps[0].setElectron(electrons[2]);
    std::cout << traps[0].isOccupied();

    return 0;
}