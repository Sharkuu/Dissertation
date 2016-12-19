//
// Created by olav on 10.10.2016.
//



#include <iostream>

#include "Electron.h"
#include "Trap.h"
#include "Crystal.h"
#include "Functions.h"

int main(int argc, char* argv[]) {
    //testing::InitGoogleTest(&argc,argv);
   // test();
    Crystal crystal = Crystal(1e6, 1e6, -900, 900);
    crystal.startSimulation(9125);
    //std::cout<<crystal.countElectrons()<<std::endl;
    std::cout<<std::endl;
    std::cout<<crystal.countElectrons();
    crystal.saveToFile();
    //crystal.removeAll();

    /*std::cout<<"ELECTRONS"<<std::endl;
    std::vector<Electron*> electrons = crystal.getElectrons();
    std::cout<<*electrons[0]<<std::endl;
    std::cout<<*electrons[1]<<std::endl;
    std::cout<<*electrons[2]<<std::endl;
    std::cout<<"Holes"<<std::endl;
    std::vector<ElectronHole*> electronHoles = crystal.getElectronHoles();
    std::cout<<*electronHoles[0]<<std::endl;
    std::cout<<*electronHoles[1]<<std::endl;
   // crystal.removeAll();
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
