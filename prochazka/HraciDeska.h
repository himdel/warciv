//
//  HraciDeska.h
//  Projekt do ZOO ZS2012
//
//  Created by David Prochazka on 10/23/12.
//  Copyright (c) 2012 David Prochazka. All rights reserved.
//

#ifndef __zoo__HraciDeska__
#define __zoo__HraciDeska__

#include <iostream>
#include <fstream>
#include <vector>

namespace zoo {
    /**
     * @brief Dvojrozmerne pole cisel, ktere ma schopnost ulozit se do souboru a nacist se z nej
     *
     * Predstavuje tridu, kterou lze pouzit pro ukladani informaci o stavu hry do textoveho souboru.
     * Jak funguje vas nemusi zajimat. Dulezite je pouze rozhranni, ktere mate v hlavickovem souboru.
     */
    class HraciDeska{
    private:
        /// Hraci deska, ktera obsahuje pole cisel
        std::vector< std::vector<int> > m_deska;
        /// Pomocna promenna s poctem radku hraci desky
        unsigned int m_pocetRadek;
        /// Pomocna promenna s poctem sloupcu hraci desky
        unsigned int m_pocetSloupcu;
    public:
        /// Konstruktor, ktery vytvori pole prislusne velikosti a nastavi do kazde bunky nulovaci prvek
        HraciDeska(const unsigned int pocetRadek, const unsigned int pocetSloupcu, const int nulovaciPrvek);
        /// Vrati cislo na pozici na prislusnem radku a v prislusnem sloupci
        int vrat(const unsigned int radek, const unsigned int sloupec);
        /// Vlozi cislo na pozici na prislusnem radku a v prislusnem sloupci
        void vloz(const unsigned int radek, const unsigned int sloupec, const int prvek);
        /// Ulozi cele pole do textoveho souboru. V pripade problemu pouzijte absolutni cestu.
        void ulozDoTextovehoSouboru(const std::string cesta);
        /// Nacte cele pole z textoveho souboru. V pripade problemu pouzijte absolutni cestu.
        void nactiZTextovehoSouboru(const std::string cesta);
        /// Vraci aktualni pocet radek pole
        int getPocetRadek();
        /// Vraci aktualni pocet skloupcu pole
        int getPocetSloupcu();
        /// Vypise obsah aktualniho hraciho pole na obrazovku
        void vypisDesku();
    };
}

#endif