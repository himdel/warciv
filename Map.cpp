#include <iostream>
#include "Map.hpp"

using namespace std;

template <typename T>
Map<T>::Map(int w, int h) {
	this->data.resize(w);
	for (int i = 0; i < w; i++)
		this->data[i].resize(h, NULL);

	this->width = w;
	this->height = h;
}

template <typename T>
T*
Map<T>::get(int x, int y) {
	if ((x >= this->width) || (y >= this->height)) {
		cerr << "Map::get out of bounds " << x << ", " << y << endl;
		return NULL;
	}

	return this->data[x][y];
}

template <typename T>
void
Map<T>::put(int x, int y, T* elem) {
	if ((x >= this->width) || (y >= this->height)) {
		cerr << "Map::put out of bounds " << x << ", " << y << endl;
		return;
	}

	this->data[x][y] = pole;
}

template <typename T>
void
Map<T>::show() {
	for (int y = 0; y < this->height; y++) {
		for (int x = 0; x < this->width; x++)
			cout << this->data[x][y] << "\t\t";

		cout << endl;
	}
}

template <typename T>
Map<T>::~Map() {
	for (int x = 0; x < this->width; x++) {
		for (int y = 0; y < this->height; y++) {
			delete this->data[x][y];
			this->data[x][y] = NULL;
		}
	}
}
