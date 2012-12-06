//
//  HraciDeska.cpp
//  Projekt do ZOO ZS2012
//
//  Created by David Prochazka on 10/23/12.
//  Copyright (c) 2012 David Prochazka. All rights reserved.
//

#include "HraciDeska.h"

zoo::HraciDeska::HraciDeska(const unsigned int pocetRadek, const unsigned int pocetSloupcu, const int nulovaciPrvek){
    
    std::vector<int> pomocnyRadek(pocetSloupcu, nulovaciPrvek);
    // lze samozrejme i jinak
    m_deska.resize(pocetRadek);
    for(int i=0; i<pocetRadek; i++){
        m_deska[i] = pomocnyRadek;
    }
    m_pocetSloupcu = pocetSloupcu;
    m_pocetRadek = pocetRadek;
}

int zoo::HraciDeska::vrat(const unsigned int radek, const unsigned int sloupec){
    // kontroluji, zda nepristupuji mimo rozsah pole
    if ((radek < m_pocetRadek) and (sloupec < m_pocetSloupcu)){
        return m_deska[radek][sloupec];
    } else {
        std::cerr << "zoo::HraciDeska::vrat - Pokus o pristup mimo rozsah desky!" << std::endl;
        std::cerr << "Pozadadovana pozice [" << radek << ", " << sloupec << "]." << std::endl;
        std::cerr << "Maximalni pozice [" << m_pocetRadek-1 << ", " << m_pocetSloupcu-1 << "]." << std::endl;
        return 0;
    }
}

void zoo::HraciDeska::vloz(const unsigned int radek, const unsigned int sloupec, const int prvek){
    // kontroluji, zda nepristupuji mimo rozsah pole
    if ((radek < m_pocetRadek) and (sloupec < m_pocetSloupcu)){
        m_deska[radek][sloupec] = prvek;
    } else {
        std::cerr << "zoo::HraciDeska::vloz - Pokus o pristup mimo rozsah desky!" << std::endl;
        std::cerr << "Pozadadovana pozice [" << radek << ", " << sloupec << "]." << std::endl;
        std::cerr << "Maximalni pozice [" << m_pocetRadek-1 << ", " << m_pocetSloupcu-1 << "]." << std::endl;
    }
}

int zoo::HraciDeska::getPocetRadek(){
    return m_pocetRadek;
}

int zoo::HraciDeska::getPocetSloupcu(){
    return m_pocetSloupcu;
}

void zoo::HraciDeska::vypisDesku(){
    for(int radek=0; radek<m_pocetRadek; radek++){
        for(int sloupec=0;  sloupec<m_pocetSloupcu; sloupec++){
            std::cout << m_deska[radek][sloupec] << " ";
        }
        std::cout << std::endl;
    }
}

void zoo::HraciDeska::ulozDoTextovehoSouboru(const std::string cesta){
    std::ofstream out(cesta.c_str());
    if (out.is_open()){
        // uloz pocet radek a pocet sloupcu
        out << m_pocetRadek << " " << m_pocetSloupcu << std::endl;
        // uloz postupne obsah matice
        for(int radek=0; radek<m_pocetRadek; radek++){
            for(int sloupec=0;  sloupec<m_pocetSloupcu; sloupec++){
                out << m_deska[radek][sloupec] << " ";
            }
            out << std::endl;
        }
        out.close();
    } else {
        std::cerr << "zoo::HraciDeska::ulozDoTextovehoSouboru - Nelze ulozit do: " << cesta << std::endl;
    }
}

void zoo::HraciDeska::nactiZTextovehoSouboru(const std::string cesta){
    std::ifstream in(cesta.c_str());
    if (in.is_open()){
        // nacti pocet radek a pocet sloupcu
        in >> m_pocetRadek;
        in >> m_pocetSloupcu;
        // vytvor matici prislusne velikosti
        std::vector<int> pomocnyRadek(m_pocetSloupcu, 0);
        m_deska.resize(m_pocetRadek);
        for(int i=0; i<m_pocetRadek; i++){
            m_deska[i] = pomocnyRadek;
        }
        // nacti postupne obsah matice
        for(int radek=0; radek<m_pocetRadek; radek++){
            for(int sloupec=0;  sloupec<m_pocetSloupcu; sloupec++){
                in >> m_deska[radek][sloupec];
            }
        }
        in.close();
    } else {
        std::cerr << "zoo::HraciDeska::ulozDoTextovehoSouboru - Nelze ulozit do: " << cesta << std::endl;
    }
}