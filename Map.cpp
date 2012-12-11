#include <iostream>
#include <fstream>

#include "Map.hpp"

using namespace std;

//TODO format, etc; HraciPole -> T

Map::Map(const unsigned int pocetRadek, const unsigned int pocetSloupcu) {
	vector<HraciPole*> pomocnyRadek(pocetSloupcu, 0);
	// lze samozrejme i jinak
	m_deska.resize(pocetRadek);
	for(int i=0; i<pocetRadek; i++) {
		m_deska[i] = pomocnyRadek;
	}
	this->width = pocetSloupcu;
	this->height = pocetRadek;
}

zoo::HraciPole* Map::vrat(const unsigned int radek, const unsigned int sloupec) {
	// kontroluji, zda nepristupujeme mimo rozsah pole
	if ((radek < this->height) and (sloupec < this->width)) {
		// kontroluji, zda je na pozici objekt
		if (m_deska[radek][sloupec] != 0) {
			return m_deska[radek][sloupec];
		} else  {
			cerr << "Map::vrat - Pokus o pristup do pole bez objektu" << endl;
			cerr << "Pozadadovana pozice [" << radek << ", " << sloupec << "]." << endl;
			return 0;
		}
	} else  {
		cerr << "Map::vrat - Pokus o pristup mimo rozsah desky!" << endl;
		cerr << "Pozadadovana pozice [" << radek << ", " << sloupec << "]." << endl;
		cerr << "Maximalni pozice [" << this->height-1 << ", " << this->width-1 << "]." << endl;
		return 0;
	}
}

void Map::vloz(const unsigned int radek, const unsigned int sloupec, zoo::HraciPole* pole) {
	// kontrola, zda nepristupuji mimo rozsah pole
	if ((radek < this->height) and (sloupec < this->width)) {
		m_deska[radek][sloupec] = pole;
	} else  {
		cerr << "Map::vloz - Pokus o pristup mimo rozsah desky!";
		cerr << "Pozadadovana pozice [" << radek << ", " << sloupec << "]." << endl;
		cerr << "Maximalni pozice [" << this->height-1 << ", " << this->width-1 << "]." << endl;
	}
}

int Map::getPocetRadek() {
	return this->height;
}

int Map::getPocetSloupcu() {
	return this->width;
}

void Map::vypisDesku() {
	for (int radek=0; radek<this->height; radek++) {
		for (int sloupec=0;  sloupec<this->width; sloupec++) {
			cout << m_deska[radek][sloupec]->getPopis() << "\t \t ";
		}
		cout << endl;
	}
}

void Map::vymazDesku() {
	for (int radek=0; radek<this->height; radek++)  {
		for (int sloupec=0; sloupec<this->width; sloupec++)  {
			// vzdy vymazu objekt a nastavim ukazatel na 0
			// tak je mozne testovat, zda tam nic neni
			delete m_deska[radek][sloupec];
			m_deska[radek][sloupec] = 0;
		}
	}
}
