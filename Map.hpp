#ifndef __MAP_HPP__
#define __MAP_HPP__

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Map {
private:
	vector< vector< T* > > data;
	int width;
	int height;

public:
	Map(int w, int h) {
		this->data.resize(w);
		for (int i = 0; i < w; i++)
			this->data[i].resize(h, NULL);

		this->width = w;
		this->height = h;
	}

	T *get(int x, int y) {
		if ((x >= this->width) || (y >= this->height)) {
			cerr << "Map::get out of bounds " << x << ", " << y << endl;
			return NULL;
		}

		return this->data[x][y];
	}

	void put(int x, int y, T* elem) {
		if ((x >= this->width) || (y >= this->height)) {
			cerr << "Map::put out of bounds " << x << ", " << y << endl;
			return;
		}

		this->data[x][y] = elem;
	}

	int getWidth() { return this->width; }
	int getHeight() { return this->height; }

	void show() {
		for (int y = 0; y < this->height; y++) {
			for (int x = 0; x < this->width; x++)
				cout << this->data[x][y] << "\t\t";

			cout << endl;
		}
	}

	~Map() {
		for (int x = 0; x < this->width; x++) {
			for (int y = 0; y < this->height; y++) {
				delete this->data[x][y];
				this->data[x][y] = NULL;
			}
		}
	}
};

#endif	// __MAP_HPP__
