//
// Created by olav on 10.10.2016.
//

#ifndef DISSERTATION_TRAP_H
#define DISSERTATION_TRAP_H

#include "Electron.h"
/**
 *  Klasa reprezentująca pułapkę
 */
class Trap {
private:
    std::vector<double> position; /**< wektor współrzędnych pułapki*/
    Electron *electron = NULL; /**< wskaznik na uwięziony elektron*/
    double energy = 2.; //eV /**< energia pułapku*/
public:
    /**
 * Konstruktor tworzy obiekt o podanych wspolrzednych
 * @param position wektor współrzędnych
 */
    Trap(std::vector<double> position);

    ~Trap();

/**
 *
 * @return zwraca energię pułapku
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
 * pułapkuje elektron, ustawia  wskaźnik na niego
 * @param electron1 elektron do spułapkowania
 */
    void setElectron(Electron *electron1);

    Electron *getElectron() const;
/**
 * Usuwa elektorn z pułapki
 * @param position nowa pozycja elektronu
 */
    void removeElectron(std::vector<double> position);
/**
 * sprawdza czy w pułapce znajduje się elektron
 * @return TRUE jesli elektron jest spułapkowany
 */
    bool isOccupied() const;


    friend std::ostream &operator<<(std::ostream &s, const Trap &v);


};


#endif //DISSERTATION_TRAP_H
