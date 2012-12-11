#ifndef __MAP_HPP__
#define __MAP_HPP__

#include <vector>
using namespace std;

class Map {
private:
	/// Hraci deska, ktera obsahuje jednotliva herni pole
	std::vector<std::vector< HraciPole*> > m_deska;
	/// Pomocna promenna s poctem radku hraci desky
	unsigned int height;
	/// Pomocna promenna s poctem sloupcu hraci desky
	unsigned int width;
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

#endif	// __MAP_HPP__
