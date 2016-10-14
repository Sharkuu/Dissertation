//
// Created by olav on 10.10.2016.
//

#ifndef DISSERTATION_ELECTRON_H
#define DISSERTATION_ELECTRON_H

#include <iostream>
#include <vector>

class Electron {
private:
    std::vector<double> position;


public:
    Electron(std::vector<double> pos);

    Electron();

    ~Electron();


    inline void setX(double x) { position[0] = x; }

    inline void setY(double y) { position[1] = y; }

    inline void setZ(double z) { position[2] = z; }

    friend std::ostream &operator<<(std::ostream &s, const Electron &v);


};


#endif //DISSERTATION_ELECTRON_H
