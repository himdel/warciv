#ifndef __FOREST_HPP__
#define __FOREST_HPP__

class Forest : public MapItem {
private:
	int wood;
public:
	Forest() : MapItem("Forest") {}
	int avail();
	int gather(int amount);
	std::string getPopis();
};

#endif	// __FOREST_HPP__
