#ifndef __GOLDMINE_HPP__
#define __GOLDMINE_HPP__

class GoldMine : public MapItem {
private:
	int gold;
public:
	int avail();
	int gather(int amount);
	std::string getPopis();
};

#endif	// __GOLDMINE_HPP__
