#include "Unit.hpp"


bool
Unit::move (int x, int y) {
}

virtual bool
Unit::gather (int x, int y) {
}

virtual bool
Unit::build (int x, int y, BuildingType b) {
}

virtual bool
Unit::attack (int x, int y) {
}

bool
Unit::stop () {
}

void
Unit::die () {
}

virtual bool
Unit::actionPending () {
}

virtual bool
Unit::performAction () {
}

virtual std::string
Unit::getPopis () {
}
