//
//  HraciDeska.h
//  Projekt do ZOO ZS2012
//
//  Created by David Prochazka on 10/23/12.
//  Copyright (c) 2012 David Prochazka. All rights reserved.
//

#ifndef __zoo__ObjektovaHraciDeska__
#define __zoo__ObjektovaHraciDeska__

#include <iostream>
#include <fstream>
#include <vector>
#include "HraciPole.h"

namespace zoo {
    /**
     * @brief Trida reprezentuji hraci desku skladajici se z hernich poli, ktere jsou objekty
     *
     * Toto je nejdulezitejsi cast prikladu. Tato deska je schopna do sebe zapouzdrit zakladni
     * chovani hraci desky. Vas herni engine by mohl tuto desku vyuzivat. Vyresite tim skladovani
     * informaci o hernich polich a ziskate jiz nachystanou kostru pro polymorfni chovani.
     * Budete si moci odvodit ruzne dalsi vlastni potomky tridy HraciPole a udelat tak desku
     * plnou ruznych hernich "kamenu". Samozrejme si libovolne doplnujte funkcionalitu zejmena
     * do trody HerniPole, aby hra fungovala jak potrebujete.
     */
    class ObjektovaHraciDeska{
    private:
        /// Hraci deska, ktera obsahuje jednotliva herni pole
        std::vector<std::vector< HraciPole*> > m_deska;
        /// Pomocna promenna s poctem radku hraci desky
        unsigned int m_pocetRadek;
        /// Pomocna promenna s poctem sloupcu hraci desky
        unsigned int m_pocetSloupcu;
    public:
        /// Konstruktor, ketry vytvori prazdne pole o predane velikosti
        ObjektovaHraciDeska(const unsigned int pocetRadek, const unsigned int pocetSloupcu);
        /// Pokud je to mozne, vrati objekt, ktery je na dane pozici v herni desce
        HraciPole* vrat(const unsigned int radek, const unsigned int sloupec);
        /// Vlozi novy objekt, ktery je potomkem tridy HraciPole na pozici v desce
        void vloz(const unsigned int radek, const unsigned int sloupec, HraciPole* pole);
        /// Vrati pocet radek matice (maximalni index je o jedno mensi)
        int getPocetRadek();
        /// Vrati pocet sloupcu matice (maximalni index je o jedno mensi)
        int getPocetSloupcu();
        /// Vypise popisy jednotlivych hracich poli na obrazovku
        void vypisDesku();
        /**
         * @brief Metoda mazajici jednotliva herni pole
         *
         * Tato metoda je trochu zvlastni. Obvykle maze objekty ten, kdo je vytvari
         * Ale v tomto pripade by to bylo komplikovane, proto vznikla tato specialni
         * cistici metoda.
         */
        void vymazDesku();
    };
}

#endif