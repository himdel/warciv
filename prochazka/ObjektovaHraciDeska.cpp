//
//  HraciDeska.cpp
//  Projekt do ZOO ZS2012
//
//  Created by David Prochazka on 10/23/12.
//  Copyright (c) 2012 David Prochazka. All rights reserved.
//

#include "ObjektovaHraciDeska.h"

zoo::ObjektovaHraciDeska::ObjektovaHraciDeska(const unsigned int pocetRadek, const unsigned int pocetSloupcu){
    
    std::vector<HraciPole*> pomocnyRadek(pocetSloupcu, 0);
    // lze samozrejme i jinak
    m_deska.resize(pocetRadek);
    for(int i=0; i<pocetRadek; i++){
        m_deska[i] = pomocnyRadek;
    }
    m_pocetSloupcu = pocetSloupcu;
    m_pocetRadek = pocetRadek;
}

zoo::HraciPole* zoo::ObjektovaHraciDeska::vrat(const unsigned int radek, const unsigned int sloupec){
    // kontroluji, zda nepristupujeme mimo rozsah pole
    if ((radek < m_pocetRadek) and (sloupec < m_pocetSloupcu)){
        // kontroluji, zda je na pozici objekt
        if (m_deska[radek][sloupec] != 0){
            return m_deska[radek][sloupec];
        } else {
            std::cerr << "zoo::ObjektovaHraciDeska::vrat - Pokus o pristup do pole bez objektu" << std::endl;
            std::cerr << "Pozadadovana pozice [" << radek << ", " << sloupec << "]." << std::endl;
            return 0;
        }
    } else {
        std::cerr << "zoo::ObjektovaHraciDeska::vrat - Pokus o pristup mimo rozsah desky!" << std::endl;
        std::cerr << "Pozadadovana pozice [" << radek << ", " << sloupec << "]." << std::endl;
        std::cerr << "Maximalni pozice [" << m_pocetRadek-1 << ", " << m_pocetSloupcu-1 << "]." << std::endl;
        return 0;
    }
}

void zoo::ObjektovaHraciDeska::vloz(const unsigned int radek, const unsigned int sloupec, zoo::HraciPole* pole){
    // kontrola, zda nepristupuji mimo rozsah pole
    if ((radek < m_pocetRadek) and (sloupec < m_pocetSloupcu)){
        m_deska[radek][sloupec] = pole;
    } else {
        std::cerr << "zoo::ObjektovaHraciDeska::vloz - Pokus o pristup mimo rozsah desky!";
        std::cerr << "Pozadadovana pozice [" << radek << ", " << sloupec << "]." << std::endl;
        std::cerr << "Maximalni pozice [" << m_pocetRadek-1 << ", " << m_pocetSloupcu-1 << "]." << std::endl;
    }
}

int zoo::ObjektovaHraciDeska::getPocetRadek(){
    return m_pocetRadek;
}

int zoo::ObjektovaHraciDeska::getPocetSloupcu(){
    return m_pocetSloupcu;
}

void zoo::ObjektovaHraciDeska::vypisDesku(){
    for(int radek=0; radek<m_pocetRadek; radek++){
        for(int sloupec=0;  sloupec<m_pocetSloupcu; sloupec++){
            std::cout << m_deska[radek][sloupec]->getPopis() << "\t \t ";
        }
        std::cout << std::endl;
    }
}

void zoo::ObjektovaHraciDeska::vymazDesku(){
    for (int radek=0; radek<m_pocetRadek; radek++) {
        for (int sloupec=0; sloupec<m_pocetSloupcu; sloupec++) {
            // vzdy vymazu objekt a nastavim ukazatel na 0
            // tak je mozne testovat, zda tam nic neni
            delete m_deska[radek][sloupec];
            m_deska[radek][sloupec] = 0;
        }
    }
}
