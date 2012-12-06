//
//  main.cpp
//  Projekt do ZOO ZS2012
//
//  Created by David Prochazka on 10/23/12.
//  Copyright (c) 2012 David Prochazka. All rights reserved.
//

#include <iostream>
#include "HraciDeska.h"
#include "CivEngine.h"
int main(int argc, const char * argv[])
{
/*
    // Tady jsem si hral s ciselnou deskou
    zoo::HraciDeska* mojeDeska;
    mojeDeska = new zoo::HraciDeska(4, 7, 7);
    mojeDeska->vloz(0, 0, 8);
    mojeDeska->vloz(2, 3, 1);
    mojeDeska->vypisDesku();
    mojeDeska->ulozDoTextovehoSouboru("save.txt");
    delete mojeDeska;
*/
    
    // toto je velmi trivialni priklad pouziti objektove herni desky ve sve "hre"
    zoo::CivEngine* hra;
    hra = new zoo::CivEngine();
    hra->pokus();
    
    delete hra;
    
    return 0;
}

