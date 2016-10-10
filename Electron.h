//
// Created by olav on 10.10.2016.
//

#ifndef DISSERTATION_ELECTRON_H
#define DISSERTATION_ELECTRON_H
#include <iostream>
#include <vector>

class Electron{
private:
    double x_pos;
    double y_pos;
    double z_pos;

public:
    Electron(double x, double y, double z);
    std::vector<double> getPosition();
    inline void setX(double x){x_pos = x;}
    inline void setY(double y){y_pos = y;}
    inline void setZ(double z){z_pos = z;}


};


#endif //DISSERTATION_ELECTRON_H
