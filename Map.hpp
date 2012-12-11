#ifndef __MAP_HPP__
#define __MAP_HPP__

#include <vector>

template <typename T>
class Map {
private:
	std::vector< std::vector< T* > > data;
	int width;
	int height;

public:
	Map(int w, int h);
	T *get(int x, int y);
	void put(int x, int y, T* elem);

	int getWidth() { return this->width }
	int getHeight() { return this->height }

	void show();

	~Map();
};

#endif	// __MAP_HPP__
