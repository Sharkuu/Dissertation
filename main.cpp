//
// Created by olav on 10.10.2016.
//



#include <iostream>

#include "Electron.h"
#include "Trap.h"
#include "Crystal.h"
#include "Functions.h"

int main(int argc, char *argv[]) {
    Crystal crystal = Crystal(1e4, 1e4, -800, 800);
    crystal.startSimulation(1000);
    std::cout << crystal.countElectrons();
    crystal.saveToFile("example.txt");
    //Crystal crystal = Crystal(1e4, 2e4, -1e3, 1e3);
    return 0;
}
