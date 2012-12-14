#ifndef __UI_HPP__
#define __UI_HPP__

class UI {
private:
	Map *map;
public:
	UI(Map *m) : map(m) {}
	void playerTurn(Player *p);
};

#endif	// __UI_HPP__
