//
// Created by olav on 14.10.2016.
//

#ifndef DISSERTATION_ELECTRONHOLE_H
#define DISSERTATION_ELECTRONHOLE_H

#include <ostream>
#include <vector>
#include "Trap.h"

class ElectronHole {
private:
    std::vector<double> position;
    Trap *trap = NULL;

    double energy = 1.; //eV
public:
    ElectronHole(std::vector<double> pos, Trap trap);

    inline double getEnergy() const { return energy; }

    inline double getX() const { return position[0]; }

    inline double getY() const { return position[1]; }

    inline double getZ() const { return position[2]; }

    inline Trap *getTrap() { return this->trap; }

    void nullTrap();

    ~ElectronHole();

    friend std::ostream &operator<<(std::ostream &s, const ElectronHole &v);

};

#endif //DISSERTATION_ELECTRONHOLE_H
