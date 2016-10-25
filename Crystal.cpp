//
// Created by olav on 14.10.2016.
//

#include "Crystal.h"


Crystal::Crystal(unsigned long n) {
    double min_range, max_range;
    this->amount_electrons_begin = n;
    std::vector<double> pos;
    std::cout << " Enter min position of traps: \n";
    std::cin >> min_range;
    std::cout << " Enter max position of traps: \n";
    std::cin >> max_range;
    for (unsigned long i = 0; i < n; i++) {
        pos.push_back((max_range - min_range) * ((double) std::rand() / (double) RAND_MAX) + min_range);
        pos.push_back((max_range - min_range) * ((double) std::rand() / (double) RAND_MAX) + min_range);
        pos.push_back((max_range - min_range) * ((double) std::rand() / (double) RAND_MAX) + min_range);
        Trap trap = Trap(pos);
        Electron *e = new Electron(pos);
        trap.setElectron(e);
        this->electrons.push_back(e);
        this->traps.push_back(trap);
        pos.clear();


    }
}

Crystal::Crystal(unsigned long n, double min_range, double max_range) {
    this->amount_electrons_begin = n;
    std::vector<double> pos;
    for (unsigned long i = 0; i < n; i++) {
        pos.push_back((max_range - min_range) * ((double) std::rand() / (double) RAND_MAX) + min_range);
        pos.push_back((max_range - min_range) * ((double) std::rand() / (double) RAND_MAX) + min_range);
        pos.push_back((max_range - min_range) * ((double) std::rand() / (double) RAND_MAX) + min_range);
        Trap trap = Trap(pos);
        Electron *e = new Electron(pos);
        trap.setElectron(e);
        this->electrons.push_back(e);
        this->traps.push_back(trap);
        pos.clear();


    }
}

std::vector<Trap> Crystal::getTraps() const {
    return this->traps;
}

std::vector<Electron *> Crystal::getElectrons() const {
    return this->electrons;
}

void Crystal::removeAll() {
    for (auto i = this->electrons.begin(); i != this->electrons.end(); ++i)
        delete *i;


}

unsigned long Crystal::electronsBeginnig() const {
    return this->amount_electrons_begin;
}



double Crystal::calculateDistance(const Trap &trap) const {
    return std::sqrt((trap.getX() - 0) * (trap.getX() - 0) +
                     (trap.getY() - 0) * (trap.getY() - 0) +
                     (trap.getZ() - 0) * (trap.getZ() - 0));
}

double Crystal::calculateTau(double distance) const {
    return pow(S, -1) * exp(cr_alpha * distance);
}
double Crystal::tunnelEffectProbability(double time, double tau) const {
    return exp(-time / tau);

}
void Crystal::tunnelEffect(Trap &trap, int time) {
    std::cout <<  this->calculateDistance(trap)<< std::endl;
    std::cout <<  this->calculateTau(this->calculateDistance(trap))<< std::endl;
    double tau = this->calculateTau(this->calculateDistance(trap));
    std::cout <<  this->tunnelEffectProbability(time,tau)<< std::endl;
    if (exp(-time / this->calculateTau(this->calculateDistance(trap))) == 4) {
        trap.removeElectron();
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
    std::cout << this->amount_electrons_begin << std::endl;
    unsigned long amount_electrons_end = 0;
    for (auto i = this->traps.begin(); i != traps.end(); ++i) {
        if (i->isOccupied())
            amount_electrons_end++;
    }
    std::cout << amount_electrons_end << std::endl;
}





