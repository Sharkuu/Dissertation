//
// Created by olav on 14.10.2016.
//

#ifndef DISSERTATION_CRYSTAL_H
#define DISSERTATION_CRYSTAL_H

#define S 3*powl(10,15)
#define cr_alpha powl(1,-0.997)

#include <ostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "Trap.h"
#include "Electron.h"
#include "ElectronHole.h"

class Crystal {
private:
    unsigned long amount_electrons_begin;
    std::vector<Trap> traps;
    std::vector<Electron *> electrons;
    std::vector<ElectronHole *> electron_holes;

    double calculateTau(double distance) const;

    double calculateDistance(const Trap &trap) const;

public:
    Crystal(unsigned long n);

    Crystal(unsigned long n, double min, double max);

    void startSimulation(int time);

    void tunnelEffect(Trap &trap, int time);

    unsigned long electronsBeginnig() const;

    std::vector<Trap> getTraps() const;

    std::vector<Electron *> getElectrons() const;

    void removeAll();
};


#endif //DISSERTATION_CRYSTAL_H
