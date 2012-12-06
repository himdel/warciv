//
//  Pole.cpp
//  Projekt do ZOO ZS2012
//
//  Created by David Prochazka on 12/6/12.
//  Copyright (c) 2012 David Prochazka. All rights reserved.
//

#include "Pole.h"

zoo::Pole::Pole(std::string popis, int bahnitost):HraciPole(popis){
    m_bahnitost = bahnitost;
}

int zoo::Pole::getObrannyBonus(){
    return m_bahnitost*1000;
}