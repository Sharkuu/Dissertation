//
// Created by olav on 10.10.2016.
//

#ifndef DISSERTATION_TRAP_H
#define DISSERTATION_TRAP_H

#include "Electron.h"

class Trap {
private:
    double x_pos;
    double y_pos;
    double z_pos;
    Electron *electron = NULL;
public:
    Trap(double x, double y, double z);

    ~Trap();

    void setElectron(Electron *electron1);

    bool isOccupied();

};


#endif //DISSERTATION_TRAP_H
