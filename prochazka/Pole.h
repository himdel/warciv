//
//  Pole.h
//  Projekt do ZOO ZS2012
//
//  Created by David Prochazka on 12/6/12.
//  Copyright (c) 2012 David Prochazka. All rights reserved.
//

#ifndef __cpp_cviceni5_piskvorky__Pole__
#define __cpp_cviceni5_piskvorky__Pole__

#include <iostream>
#include "HraciPole.h"

namespace zoo {
    /**
     * @brief Trida reprezentujici pole s hlinou (opravdove pole, kde se sazi)
     *
     * Toto je trivialni potomek obecneho hraciho pole, ktery ukazuje, jak 
     * se ma odvodit konkretni hraci pole. Kazde hlinene pole ma treba bahnitost.
     * To je jeho specialni vlastnost, kterou potrebujeme pro vypocet obranneho bon.
     */
    class Pole: public HraciPole{
    private:
        /// Mira nasaknuti pudy vodou, ma vliv na obranny bonus - vic bahnite, vic bezpecne
        int m_bahnitost;
    public:
        /// Konstruktor inicializujici atributy
        Pole(std::string popis, int bahnitost);
        /// Vypocte a vrati obranny bonus na zaklade bahnitosti pudy
        int getObrannyBonus();
    };
}
#endif 
