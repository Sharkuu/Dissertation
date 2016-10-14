//
// Created by olav on 14.10.2016.
//

#include "Crystal.h"


Crystal::Crystal(unsigned long n) {
    double min_range, max_range;
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
        Electron e = Electron(pos);
        trap.setElectron(e);
        this->traps.push_back(trap);
        this->electrons.push_back(e);
        pos.clear();


}}

std::vector<Trap> Crystal::getTraps() {
    return this->traps;
}

std::vector<Electron> Crystal::getElectrons() {
    return this->electrons;
}