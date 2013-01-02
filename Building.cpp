#include "Building.hpp"
using namespace std;


bool
Building::upgrade() {
	return false;
}

bool
Building::create(UnitType u) {
	return false;
}

void
Building::damage(int hitpoints) {
	this->hitpoints -= min(this->hitpoints, hitpoints);
}

string
Building::getPopis() {
	ostringstream os;
	os << base::getPopis() << "(" << this->hitpoints << ")";
	return os.str();
}
