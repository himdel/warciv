#ifndef __ACTIONS_HPP__
#define __ACTIONS_HPP__

#include <string>
#include "enums.hpp"

struct ActionData {
	ActionType type;
	std::string name;
};

extern ActionData actions[];
extern unsigned actions_count;

#endif	// __ACTIONS_HPP__
