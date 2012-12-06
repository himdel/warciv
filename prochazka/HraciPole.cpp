//
//  HraciPole.cpp
//  Projekt do ZOO ZS2012
//
//  Created by David Prochazka on 12/6/12.
//  Copyright (c) 2012 David Prochazka. All rights reserved.
//

#include "HraciPole.h"

zoo::HraciPole::HraciPole(std::string popis){
    if (popis == ""){
        std::cerr << "zoo::HraciPole::HraciPole - snazite se do popisu pole nastavit prazdnou hodnotu" << std::endl;
    }
    m_popis = popis;
}


std::string zoo::HraciPole::getPopis(){
    return m_popis;
}