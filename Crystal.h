//
// Created by olav on 14.10.2016.
//

#ifndef DISSERTATION_CRYSTAL_H
#define DISSERTATION_CRYSTAL_H

#include <ostream>
#include <vector>
#include <cstdlib>
#include "Trap.h"
#include "Electron.h"

class Crystal {
private:
    std::vector<Trap> traps;
    std::vector<Electron> electrons;

public:
    Crystal(unsigned long n);

    std::vector<Trap> getTraps();

    std::vector<Electron> getElectrons();
};


#endif //DISSERTATION_CRYSTAL_H
