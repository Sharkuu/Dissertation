//
// Created by olav on 14.10.2016.
//

#ifndef DISSERTATION_CRYSTAL_H
#define DISSERTATION_CRYSTAL_H



#include <ostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "Trap.h"
#include "Electron.h"
#include "ElectronHole.h"

class Crystal {
private:
    double S = 3e15;
    unsigned long amount_electrons_begin;
    std::vector<Trap> traps;
    std::vector<Electron *> electrons;
    std::vector<ElectronHole *> electron_holes;

    double calculateTau(double distance, ElectronHole * el_hole,const  Trap & trap) const;

    double calculateDistance(const Trap &trap, const ElectronHole * hole) const;

public:
    Crystal(unsigned long n);

    Crystal(long long int n_el, long long n_holes, double min, double max);

    void startSimulation(int time);

    void tunnelEffect(Trap &trap, int time);

    unsigned long electronsBeginnig() const;

    std::vector<Trap> getTraps() const;

    std::vector<Electron *> getElectrons() const;

    std::vector<ElectronHole *> getElectronHoles() const;

    static double tunnelEffectProbability(double time, double tau) ;
    void removeAll();
};


#endif //DISSERTATION_CRYSTAL_H
