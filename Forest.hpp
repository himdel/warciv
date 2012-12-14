#ifndef __FOREST_HPP__
#define __FOREST_HPP__

#include "Resource.hpp"

class Forest : public Resource {
public:
	Forest() : Resource("Forest") {}
	int gather(int amount);
};

#endif	// __FOREST_HPP__
