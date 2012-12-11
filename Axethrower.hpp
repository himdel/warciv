#ifndef __AXETHROWER_HPP__
#define __AXETHROWER_HPP__

class Axethrower : public Unit {
public:
	Axethrower() : MapItem("Axethrower") {}
	bool attack(int x, int y);
};

#endif	// __AXETHROWER_HPP__
