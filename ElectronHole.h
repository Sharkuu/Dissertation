//
// Created by olav on 14.10.2016.
//

#ifndef DISSERTATION_ELECTRONHOLE_H
#define DISSERTATION_ELECTRONHOLE_H

#include <ostream>
#include <vector>
#include "Trap.h"
/**
 *  Klasa reprezentująca dziurę elektronową
 */
class ElectronHole {
private:
    /** @brief wektor współrzędnych dziury*/
    std::vector<double> position;
    /** @brief wskaźnika na obiekt typu Trap (informacja czy obiekt znajduje się w pułapce)*/
    Trap *trap = NULL;
    /** @brief energia dziury [w eV]*/
    double energy = 1.;
public:

    /**
     * Konstruktor tworzy obiekt o podanych wspolrzednych i łączy go z pułapką
     * @param pos wektor współrzędnych
     * @param trap referencja do pułapku
    */
    ElectronHole(std::vector<double> pos, Trap &trap);

    /**
     *
     * @return zwraca energię dziury
     */
    inline double getEnergy() const { return energy; }

    /**
     *
     * @return zwraca x-ową współrzędną
    */
    inline double getX() const { return position[0]; }

    /**
     *
     * @return zwraca y-ową współrzędną
    */
    inline double getY() const { return position[1]; }

    /**
     *
     * @return zwraca z-ową współrzędną
    */
    inline double getZ() const { return position[2]; }

    /**
     *
     * @return zwraca adres do pułapki w której się obecne znajduje
     */
    inline Trap *getTrap() { return this->trap; }

    /**
     * @brief usuwa dziurę z pułapki, ustawia wskaznik trap na NULL
    */
    void nullTrap();

    ~ElectronHole();

    friend std::ostream &operator<<(std::ostream &s, const ElectronHole &v);

};

#endif //DISSERTATION_ELECTRONHOLE_H
