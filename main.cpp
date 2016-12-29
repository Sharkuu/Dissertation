//
// Created by olav on 10.10.2016.
//



#include <iostream>

#include "Electron.h"
#include "Trap.h"
#include "Crystal.h"
#include "Functions.h"

int main(int argc, char *argv[]) {
    Crystal crystal = Crystal(1e6, 1e6, -900, 900);
    crystal.startSimulation(1825);
    std::cout << crystal.countElectrons();
    crystal.saveToFile("example.txt");

    return 0;
}
