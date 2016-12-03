//
// Created by olav on 14.10.2016.
//

#ifndef DISSERTATION_CRYSTAL_H
#define DISSERTATION_CRYSTAL_H



#include <ostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include "Trap.h"
#include "Electron.h"
#include "ElectronHole.h"

class Crystal {
private:
    double S = 10e10;
    std::map<unsigned long,unsigned long> amount_electrons;
    std::vector<Trap> traps;
    std::vector<Electron *> electrons;
    std::vector<ElectronHole *> electron_holes;

    double calculateTau(double distance, ElectronHole * el_hole,const  Trap & trap) const;

    double calculateDistance(const Trap &trap, const ElectronHole * hole) const;

public:
    Crystal(unsigned long n);
    ~Crystal();
    Crystal(long long int n_el, long long n_holes, double min, double max);

    unsigned long changeTime(unsigned long time) const;
    void startSimulation(int time);

    void tunnelEffect(Trap &trap, int time);


    std::vector<Trap> getTraps() const;

    std::vector<Electron *> getElectrons() const;

    std::vector<ElectronHole *> getElectronHoles() const;

    static double tunnelEffectProbability(double time, double tau) ;
    void removeAll();
    unsigned long countElectrons() const;
    void saveToFile() ;
};


#endif //DISSERTATION_CRYSTAL_H
