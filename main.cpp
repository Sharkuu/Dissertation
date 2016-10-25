//
// Created by olav on 10.10.2016.
//
#include <iostream>
#include "Electron.h"
#include "Trap.h"
#include "Crystal.h"
#include "Functions.h"

int main() {
    Crystal crystal = Crystal(5, 0.0000001, 0.002);
    printVector(crystal.getTraps());
    crystal.startSimulation(5);
    crystal.removeAll();
    /* std::vector<Trap> traps = crystal.getTraps();
     std::cout<<*traps[0].getElectron()<<std::endl;
     //std::cout<<*traps[1].getElectron()<<std::endl;
     /*traps[0].removeElectron();
     if (traps[0].isOccupied())
     std::cout<<*traps[0].getElectron()<<std::endl;
     std::cout<<*traps[1].getElectron()<<std::endl;

     std::cout<<"-------------------------------------------------\n";
     if (traps[0].isOccupied())
     std::cout<<*traps[0].getElectron()<<std::endl;
     std::cout<<*traps[1].getElectron()<<std::endl;*/
    return 0;
}