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
    double energy = 1; //eV
public:
    Trap(std::vector<double> position);

    ~Trap();

    inline double getX() const { return position[0]; }

    inline double getY() const { return position[1]; }

    inline double getZ() const { return position[2]; }

    inline double getEnergy() const { return energy; }

    void setElectron(Electron *electron1);

    Electron *getElectron() const;

    void removeElectron(std::vector<double> position);

    bool isOccupied() const;


    friend std::ostream &operator<<(std::ostream &s, const Trap &v);


};


#endif //DISSERTATION_TRAP_H
