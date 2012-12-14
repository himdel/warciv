#ifndef __FOREST_HPP__
#define __FOREST_HPP__

class Resource : public MapItem {
private:
	int quantity;
public:
	Resource(std::string popis) : MapItem(popis) {}
	int avail();
	int gather(int amount);
	std::string getPopis();	// popis(quantity)
};

#endif	// __FOREST_HPP__
