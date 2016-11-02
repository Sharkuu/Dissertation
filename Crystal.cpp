//
// Created by olav on 14.10.2016.
//

#include "Crystal.h"


Crystal::Crystal(unsigned long n) {
    double min_range, max_range;
    this->amount_electrons_begin = n;
    std::cout << " Enter min position of traps: \n";
    std::cin >> min_range;
    std::cout << " Enter max position of traps: \n";
    std::cin >> max_range;
    for (unsigned long i = 0; i < n; i++) {
        std::vector<double> pos{(max_range - min_range) * ((double) std::rand() / (double) RAND_MAX) + min_range,
                                (max_range - min_range) * ((double) std::rand() / (double) RAND_MAX) + min_range,
                                (max_range - min_range) * ((double) std::rand() / (double) RAND_MAX) + min_range};
        Trap trap(pos);
        Electron *e = new Electron(pos);
        trap.setElectron(e);
        this->electrons.push_back(e);
        this->traps.push_back(trap);
        pos.clear();


    }
}

Crystal::Crystal(long long int n_el, long long int n_holes, double min_range, double max_range) {
    this->amount_electrons_begin = n_el;
    for (unsigned long i = 0; i < n_el; i++) {
        std::vector<double> pos{(max_range - min_range) * ((double) std::rand() / (double) RAND_MAX) + min_range,
                                (max_range - min_range) * ((double) std::rand() / (double) RAND_MAX) + min_range,
                                (max_range - min_range) * ((double) std::rand() / (double) RAND_MAX) + min_range};
        Trap trap(pos);
        Electron *e = new Electron(pos);
        trap.setElectron(e);
        this->electrons.push_back(e);
        this->traps.push_back(trap);
        pos.clear();
        if (i < n_holes) {
            std::vector<double> pos{(max_range - min_range) * ((double) std::rand() / (double) RAND_MAX) + min_range,
                                    (max_range - min_range) * ((double) std::rand() / (double) RAND_MAX) + min_range,
                                    (max_range - min_range) * ((double) std::rand() / (double) RAND_MAX) + min_range};
            Trap *trap = new Trap(pos);
            this->traps.push_back(*trap);
            ElectronHole *hole = new ElectronHole(pos, trap);
            this->electron_holes.push_back(hole);
            pos.clear();
        }
    }
}

std::vector<Trap> Crystal::getTraps() const {
    return this->traps;
}

std::vector<Electron *> Crystal::getElectrons() const {
    return this->electrons;
}

std::vector<ElectronHole *> Crystal::getElectronHoles() const {
    return this->electron_holes;
}

void Crystal::removeAll() {
    for (auto i = this->electrons.begin(); i != this->electrons.end(); ++i)
        delete *i;


}

unsigned long Crystal::electronsBeginnig() const {
    return this->amount_electrons_begin;
}


double Crystal::calculateDistance(const Trap &trap, const ElectronHole *hole) const {
    return std::sqrt((trap.getX() - hole->getX()) * (trap.getX() - hole->getX()) +
                     (trap.getY() - hole->getY()) * (trap.getY() - hole->getY()) +
                     (trap.getZ() - hole->getZ()) * (trap.getZ() - hole->getZ()));
}

double Crystal::calculateTau(double distance, ElectronHole *el_hole, const Trap &trap) const {
    return pow(this->S, -1) * exp((trap.getEnergy() - el_hole->getEnergy()) * distance);
}

double Crystal::tunnelEffectProbability(double time, double tau) {
    return exp(-time / tau);

}

void Crystal::tunnelEffect(Trap &trap, int time) {
    double probability = 1;
    int k,n = 0;
    ElectronHole *hole = NULL;
    for (auto i = this->electron_holes.begin(); i != electron_holes.end(); ++i) {
        hole = *i;
        if (this->tunnelEffectProbability(time, this->calculateTau(this->calculateDistance(trap, hole), hole, trap)) <
            probability && hole->getTrap()!=NULL) {
            k=n;
            probability = this->tunnelEffectProbability(time, this->calculateTau(this->calculateDistance(trap, *i), *i,
                                                                                 trap));
        }
        n++;
    }
     //  electron_holes.erase(electron_holes.begin()+k);
    if (probability < 1) {
        Electron *e = trap.getElectron();
        trap.removeElectron(std::vector<double>{hole->getX(), hole->getY(), hole->getZ()});
        Trap *new_trap = hole->getTrap();
        new_trap->setElectron(e);

    }
}

void Crystal::startSimulation(int time) {
    for (int t = 0; t < time; ++t) {
        for (auto i = this->traps.begin(); i != traps.end(); ++i) {
            if (i->isOccupied()) {
                this->tunnelEffect(*i, t);
            }
        }
    }
    /*std::cout << this->amount_electrons_begin << std::endl;
    unsigned long amount_electrons_end = 0;
    for (auto i = this->traps.begin(); i != traps.end(); ++i) {
        if (i->isOccupied())
            amount_electrons_end++;
    }
    std::cout << amount_electrons_end << std::endl;*/
}





