//
//  CivEngine.cpp
//  Projekt do ZOO ZS2012
//
//  Created by David Prochazka on 12/6/12.
//  Copyright (c) 2012 David Prochazka. All rights reserved.
//

#include "CivEngine.h"

zoo::CivEngine::CivEngine(){
    // vytvorim si pole
    m_hraciDeska = new ObjektovaHraciDeska(3,3);
    inicializujBunkyPole();
}

void zoo::CivEngine::inicializujBunkyPole(){
    // naplnim prvni radek
    m_hraciDeska->vloz(0, 0, new Pole("bahnite pole", 10));
    m_hraciDeska->vloz(0, 1, new Pole("bahnite pole", 10));
    m_hraciDeska->vloz(0, 2, new Pole("bahnite pole", 10));
    // naplnim druhy radek
    m_hraciDeska->vloz(1, 0, new Pole("suche pole", 1));
    m_hraciDeska->vloz(1, 1, new Pole("suche pole", 2));
    m_hraciDeska->vloz(1, 2, new Pole("suche pole", 1));
    // naplnim treti radek
    m_hraciDeska->vloz(2, 0, new Pole("pocurane pole", 20));
    m_hraciDeska->vloz(2, 1, new Pole("suche pole", 2));
    m_hraciDeska->vloz(2, 2, new Pole("suche pole", 1));
}

void zoo::CivEngine::pokus(){
    m_hraciDeska->vypisDesku();
}


zoo::CivEngine::~CivEngine(){
    m_hraciDeska->vymazDesku();
}