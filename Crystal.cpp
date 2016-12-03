//
// Created by olav on 14.10.2016.
//

#include "Crystal.h"


Crystal::Crystal(unsigned long n) {
    double min_range, max_range;
    this->amount_electrons[0] = 0;
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
    this->amount_electrons[0] = n_el;
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
    }
    for (unsigned long i = 0; i < n_holes; i++) {
        std::vector<double> pos{(max_range - min_range) * ((double) std::rand() / (double) RAND_MAX) + min_range,
                                (max_range - min_range) * ((double) std::rand() / (double) RAND_MAX) + min_range,
                                (max_range - min_range) * ((double) std::rand() / (double) RAND_MAX) + min_range};
        Trap trap(pos);
        this->traps.push_back(trap);
        ElectronHole *hole = new ElectronHole(pos, trap);
        this->electron_holes.push_back(hole);
        pos.clear();
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
        std::cout << this->tunnelEffectProbability(time, this->calculateTau(this->calculateDistance(trap, i), i, trap))
                  << std::endl;
        if (this->tunnelEffectProbability(time, this->calculateTau(this->calculateDistance(trap, i), i, trap)) <
            ((double) std::rand() / (double) (RAND_MAX)) && i->getTrap() != NULL) {
            Electron *e = trap.getElectron();
            trap.removeElectron(std::vector<double>{i->getX(), i->getY(), i->getZ()});
            //i->getTrap()->setElectron(e);
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
        for (auto i = this->traps.begin(); i != traps.end(); ++i) {
            if (i->isOccupied()) {
                //std::cout<<"nowy"<<std::endl;
                this->tunnelEffect(*i, t);
                if (((double) std::rand() / (double) (RAND_MAX)) < 0.4) {
                    this->amount_electrons[t] = this->countElectrons();
                }
            }
        }
    }
}

unsigned long Crystal::countElectrons() const {
    unsigned long electrons = 0;
    for (auto i = this->traps.begin(); i != traps.end(); ++i) {
        if (i->isOccupied())
            ++electrons;
    }
    return electrons;
}

void Crystal::saveToFile() {
    std::ofstream file;
    file.open("./example.txt");
    for (auto it = this->amount_electrons.cbegin(); it != this->amount_electrons.cend(); ++it) {
        file << this->changeTime(it->first) << ";" << it->second / this->amount_electrons[0] << "\n";
    }
    file.close();

    return;
}

unsigned long Crystal::changeTime(unsigned long time) const {
    return log10(time / 1728e12);

}

