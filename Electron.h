//
// Created by olav on 10.10.2016.
//

#ifndef DISSERTATION_ELECTRON_H
#define DISSERTATION_ELECTRON_H

#include <iostream>
#include <vector>

/**
 *  Klasa reprezentująca elektron
 */
class Electron {
private:
    /** @brief wektor współrzędnych elektronu*/
    std::vector<double> position;


public:

    /**
     * Konstruktor tworzy obiekt o podanych wspolrzednych
     * @param pos wektor współrzędnych
     */
    Electron(std::vector<double> pos);

    ~Electron();

    /**
     * Zmianna x-owej wartości współrzędnej
     * @param x nowa wartość współrzędnej
     */
    inline void setX(double x) { position[0] = x; }

    /**
     * Zmianna y-owej wartości współrzędnej
     * @param y nowa wartość współrzędnej
     */
    inline void setY(double y) { position[1] = y; }

    /**
     * Zmianna z-owej wartości współrzędnej
     * @param z nowa wartość współrzędnej
     */
    inline void setZ(double z) { position[2] = z; }

    friend std::ostream &operator<<(std::ostream &s, const Electron &v);


};


#endif //DISSERTATION_ELECTRON_H
