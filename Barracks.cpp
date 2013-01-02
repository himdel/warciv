#include "Barracks.hpp"
#include "units.hpp"

bool
Barracks::create(UnitType u) {
	Unit *unit = NULL;

	for (int i = 0; i < sizeof(units) / sizeof(UnitData); i++)
		if ((units[i].type == u) && (units[i].where == bt_Barracks)) {
			if (this->owner->cost(units[i].gold, units[i].wood))
				unit = units[i].make(this->owner);
			break;
		}

	if (!unit)
		return false;

	unit->place(this->map, this->x, this->y);
	this->owner->addUnit(unit);
	return true;
}
