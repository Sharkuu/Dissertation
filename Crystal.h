//
// Created by olav on 14.10.2016.
//

#ifndef DISSERTATION_CRYSTAL_H
#define DISSERTATION_CRYSTAL_H



#include <ostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include "Trap.h"
#include "Electron.h"
#include "ElectronHole.h"
/**
 *  Klasa reprezentująca kryształ
 */

class Crystal {
private:
    const double S = 3e15; /**< wartość stałej 'attempt-to-escape frequency'*/
    std::map<unsigned long,unsigned long> amount_electrons; /**< mapa klucz - czas, wartosc - ilosc elektronow w stanie wzbudzonym */
    std::vector<Trap> el_traps; /**< wektor przechowujący wszystkie pułapki*/
    std::vector<Electron *> electrons; /**< wektor przechowujący wskaźniki do elektronów*/
    std::vector<ElectronHole *> electron_holes; /**< wektor przechowujący wskaźniki do dziur elektronowych*/

    /**
     * Funkcja do obliczania wartosci tau
     * @see calculateDistance()
     * @param distance dystans do przetunelowania
     * @param el_hole wskaznik na dziurę elektronową
     * @param trap referencja do pułapki
     * @return wartość tau
     */
    double calculateTau(double distance, ElectronHole * el_hole,const  Trap & trap) const;

    /**
     * Funkcja do obliczania odległości między pułapką a dziurą
     * @param trap referencja do pułapki
     * @param hole wskaznik na dziurę elektronową
     * @return odległość między parametrami
     */
    double calculateDistance(const Trap &trap, const ElectronHole * hole) const;

public:

    Crystal(unsigned long n);
    ~Crystal();

    /**
 * Konstruktor
 * @param n_el ilosc obiektów elektronu do stworzenia
 * @param n_el ilosc obiektów dziury elektronowej do stworzenia
 * @param min dolna granica którą mogą przyjmować współrzędne cząstek
 * @param max górna granica którą mogą przyjmować współrzędne cząstek
 */
    Crystal(long long int n_el, long long n_holes, double min, double max);

    /**
 * Funkcja zmieniajaca jednostę czasu
 * @param time czas do zamiany
 * @return czas podany w jednostce log10(t/2dni)
 */
    double changeTime(unsigned long time) const;

    /**
 * Funkcja rozpoczynająca symulacje
 * @param time symulowany czas działania
 */
    void startSimulation(int time);


    /**
     * Funkcja wykonująca efekt tunelowania
     * @param trap referencja do pułapki
     * @param time czas
     */
    void tunnelEffect(Trap &trap, int time);


    std::vector<Trap> getTraps() const;

    std::vector<Electron *> getElectrons() const;

    std::vector<ElectronHole *> getElectronHoles() const;
    /**
     * Funkcja do obliczania prawdopodobienstwa NIEZAJŚCIA tunelowania
     * @param time czas
     * @param tau wartość tau
     * @see calculateTau()
     * @return wartość prawdopodobieństwa
     */
    static double tunnelEffectProbability(double time, double tau) ;
    void removeAll();

    unsigned long countElectrons() const;
    void saveToFile() ;
};


#endif //DISSERTATION_CRYSTAL_H
