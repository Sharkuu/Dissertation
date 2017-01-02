//
// Created by olav on 14.10.2016.
//

#include "Crystal.h"

Crystal::Crystal(long long int n_el, long long int n_holes, double min_range, double max_range) {
    this->amount_electrons[0] = n_el;
    std::uniform_real_distribution<double> unif(min_range, max_range);
    std::default_random_engine re;
    for (unsigned long i = 0; i < n_el; i++) {
        std::vector<double> pos{unif(re), unif(re), unif(re)};
        Trap trap(pos);
        Electron *e = new Electron(pos);
        trap.setElectron(e);
        this->electrons.push_back(e);
        this->el_traps.push_back(trap);
        pos.clear();
    }
    for (unsigned long i = 0; i < n_holes; i++) {
        std::vector<double> pos{unif(re), unif(re), unif(re)};
        Trap trap(pos);
        //this->traps.push_back(trap);
        ElectronHole *hole = new ElectronHole(pos, trap);
        this->electron_holes.push_back(hole);
        pos.clear();
    }
}


std::vector<Trap> Crystal::getTraps() const {
    return this->el_traps;
}

std::vector<Electron *> Crystal::getElectrons() const {
    return this->electrons;
}

std::vector<ElectronHole *> Crystal::getElectronHoles() const {
    return this->electron_holes;
}

Crystal::~Crystal() {
    for (auto elec : electrons)
        delete elec;
    for (auto holes: electron_holes)
        delete holes;


}


double Crystal::calculateDistance(const Trap &trap, const ElectronHole *hole) const {
    return std::sqrt((trap.getX() - hole->getX()) * (trap.getX() - hole->getX()) +
                     (trap.getY() - hole->getY()) * (trap.getY() - hole->getY()) +
                     (trap.getZ() - hole->getZ()) * (trap.getZ() - hole->getZ()));
}

double Crystal::calculateTau(double distance, ElectronHole *el_hole, const Trap &trap) const {
    return (1 / S) * exp((trap.getEnergy() - el_hole->getEnergy()) * distance);
}

double Crystal::tunnelEffectProbability(double time, double tau) {
    return exp(-time / tau);

}

void Crystal::tunnelEffect(Trap &trap, int time) {
    int n = 0;
    for (auto i : this->electron_holes) {
        if (this->tunnelEffectProbability(time, this->calculateTau(this->calculateDistance(trap, i), i, trap)) <
            ((double) std::rand() / (double) (RAND_MAX)) && i->getTrap() != NULL) {
            trap.removeElectron(std::vector<double>{i->getX(), i->getY(), i->getZ()});
            i->nullTrap();
            electron_holes.erase(electron_holes.begin() + n);
            delete i;
            break;
        }
        n++;
    }
}

void Crystal::startSimulation(int time) {
    for (int t = 1; t < time; ++t) {
        for (auto i = this->el_traps.begin(); i != el_traps.end(); ++i) {
            if (i->isOccupied()) {
                this->tunnelEffect(*i, 86400);
            }
        }
        this->amount_electrons[t * 86400] = this->countElectrons();
        std::cout<<t<<std::endl;

    }
}

unsigned long Crystal::countElectrons() const {
    unsigned long electrons = 0;
    for (auto i = this->el_traps.begin(); i != el_traps.end(); ++i) {
        if (i->isOccupied())
            ++electrons;
    }
    return electrons;
}

void Crystal::saveToFile(std::string name){
    std::ofstream file;
    file.open(name);
    auto it = this->amount_electrons.cbegin();
    it++;
    for (; it != this->amount_electrons.cend(); ++it) {
        file << this->changeTime(it->first) << ";" << (double) it->second / this->amount_electrons[0] << "\n";
    }
    file.close();

    return;
}

double Crystal::changeTime(unsigned long time) const {
    return log10(time / 1728e2);

}

