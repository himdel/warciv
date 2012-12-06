//
//  CivEngine.h
//  Projekt do ZOO ZS2012
//
//  Created by David Prochazka on 12/6/12.
//  Copyright (c) 2012 David Prochazka. All rights reserved.
//

#ifndef __zoo__CivEngine__
#define __zoo__CivEngine__

#include <iostream>
#include "ObjektovaHraciDeska.h"
#include "Pole.h"

namespace zoo{
    /**
     * @brief Trida reprezentujici fiktivni herni engine. 
     *
     * Ve finalnim projektu ji samozrejme nahradite mnozinou svych vlastnich trid.
     * Je zde demonstrovano jak pouzit objektovou herni desku pro ulozeni poli.
     */
    class CivEngine{
    private:
        /// Instance objektove herni desky, ktera ponese vsechna herni pole
        ObjektovaHraciDeska* m_hraciDeska;
    public:
        /// Konstruktor volajici inicializaci herni desky
        CivEngine();
        /// Fiktivni metoda, ktera pouze vola vypsani obsahu herni desky
        void pokus();
        /// Desktruktor rusici jednotlive prvky herni plochy
        ~CivEngine();
    private:
        /**
         * @brief Naplni jednotlive bunky hraci desky objekty
         *
         * Soukroma metoda, ktera fyzicky vytvori jednotlive casti hraci plochy
         * Tato metoda je velmi trivialni. Bylo by pekne ji napojit treba
         * na tridu HraciDeska a vytvorit pole podle hodnot v souboru.
         * Ale tim se pro zacatek netrapte.
         */
        void inicializujBunkyPole();
    };
}
#endif /* defined(__cpp_cviceni5_piskvorky__CivEngine__) */
