//
// Created by olav on 10.10.2016.
//

#ifndef DISSERTATION_TRAP_H
#define DISSERTATION_TRAP_H

#include "Electron.h"

class Trap {
private:
    std::vector<double> position;
    Electron *electron = NULL;
public:
    Trap(double x, double y, double z);

    ~Trap();

    void setElectron(Electron electron1);

    bool isOccupied();

    friend std::ostream &operator<<(std::ostream &s, const Trap &v);


};


#endif //DISSERTATION_TRAP_H
