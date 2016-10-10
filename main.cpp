//
// Created by olav on 10.10.2016.
//
#include <iostream>
#include "Electron.h"
#include "Trap.h"
int main() {
    Electron e1(0.05,6,7);
    std::vector < std::vector < double > > pos;
    pos.push_back(e1.getPosition());
    std::cout<<pos[0][0]<<" "<<pos[0][1]<<" "<<pos[0][2]<<std::endl;
    Trap t1(5,6,7);
    t1.setElectron(&e1);
    std::cout<<t1.isOccupied()<<std::endl;
    pos.push_back(e1.getPosition());
    std::cout<<pos[1][0]<<" "<<pos[1][1]<<" "<<pos[1][2]<<std::endl;
    return 0;
}