#include "Peon.hpp"


bool
Peon::gather(int x, int y) {
	bool r = this->move(x, y);
	if ((this->x != x) && (this->y != y))
		return r;

	// on the spot
	Resource *spot = dynamic_cast<Resource *>( this->map->get(x, y) );
	if (!spot)
		return false;

	return !! spot->gather(10, this->owner);
}

bool
Peon::build(int x, int y, BuildingType b) {
	bool r = this->move(x, y);
	if ((this->x != x) && (this->y != y))
		return r;

	// on the spot
	if (this->map->get(x, y) != NULL)
		return false;

	//TODO build
	return false;
}
