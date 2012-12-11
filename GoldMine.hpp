#ifndef __GOLDMINE_HPP__
#define __GOLDMINE_HPP__

class GoldMine : public MapItem {
private:
	int gold;
public:
	GoldMine() : MapItem("GoldMine") {}
	int avail();
	int gather(int amount);
	std::string getPopis();
};

#endif	// __GOLDMINE_HPP__
