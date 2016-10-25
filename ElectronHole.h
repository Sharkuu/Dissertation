//
// Created by olav on 14.10.2016.
//

#ifndef DISSERTATION_ELECTRONHOLE_H
#define DISSERTATION_ELECTRONHOLE_H

#include <ostream>
#include <vector>

class ElectronHole {
private:
    std::vector<double> position;
public:
    ElectronHole(std::vector<double> pos);

    ~ElectronHole();


};

#endif //DISSERTATION_ELECTRONHOLE_H
