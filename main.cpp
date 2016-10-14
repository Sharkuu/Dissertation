//
// Created by olav on 10.10.2016.
//
#include <iostream>
#include "Electron.h"
#include "Trap.h"
#include "Crystal.h"
#include "Functions.h"
int main() {
    Crystal crystal = Crystal(2);
    printVector(crystal.getTraps());
    std::vector<Trap> traps = crystal.getTraps();
    std::cout<<*traps[0].getElectron()<<std::endl;
    std::cout<<*traps[1].getElectron()<<std::endl;
    crystal.getTraps().clear();
    crystal.getElectrons().clear();


    return 0;
}