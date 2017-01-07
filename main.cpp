//
// Created by olav on 10.10.2016.
//



#include <iostream>

#include "Electron.h"
#include "Trap.h"
#include "Crystal.h"


int main(int argc, char *argv[]) {
    Crystal crystal = Crystal(3276, 3276, -509, 509);


    crystal.startSimulation(1000);
    std::cout << crystal.countElectrons();
    crystal.saveToFile("example.txt");
    return 0;
}
//Crystal crystal = Crystal(8000, 8000, -742, 742);
//Crystal crystal = Crystal(6400, 6400, -688, 688);
//Crystal crystal = Crystal(5120, 5120, -592, 592);
//Crystal crystal = Crystal(4096, 4096, -549, 549);
//Crystal crystal = Crystal(3276, 3276, -509, 509);