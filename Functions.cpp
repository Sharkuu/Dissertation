//
// Created by olav on 12.10.2016.
//

#include "Functions.h"

void createElectrons(std::vector<Electron> &electrons) {
    double min_range, max_range;
    int n;
    std::cout << " Enter min position of electrons: \n";
    std::cin >> min_range;
    std::cout << " Enter max position of electrons: \n";
    std::cin >> max_range;
    std::cout << " Enter amount of generated electrons: \n";
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        Electron e = Electron((max_range - min_range) * ((double) std::rand() / (double) RAND_MAX) + min_range,
                              (max_range - min_range) * ((double) std::rand() / (double) RAND_MAX) + min_range,
                              (max_range - min_range) * ((double) std::rand() / (double) RAND_MAX) + min_range);
        electrons.push_back(e);
    }

}

void createTraps(std::vector<Trap> &traps) {
    double min_range, max_range;
    int n;
    std::cout << " Enter min position of traps: \n";
    std::cin >> min_range;
    std::cout << " Enter max position of traps: \n";
    std::cin >> max_range;
    std::cout << " Enter amount of generated traps: \n";
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        Trap e = Trap((max_range - min_range) * ((double) std::rand() / (double) RAND_MAX) + min_range,
                      (max_range - min_range) * ((double) std::rand() / (double) RAND_MAX) + min_range,
                      (max_range - min_range) * ((double) std::rand() / (double) RAND_MAX) + min_range);
        traps.push_back(e);
    }


}

