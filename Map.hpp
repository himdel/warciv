#ifndef __MAP_HPP__
#define __MAP_HPP__

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

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

private:
	static void pushV(int px, int py, queue< pair<int, int> > &fifo, vector< vector<bool> > &visited) {
		if ((px < 0) || (py < 0) || (px >= this->width) || (py >= this->height))
			return;
		if (visited[px][py])
			return;
		visited[px][py] = true;

		fifo.push_back(make_pair(px, py));
	}

	static void pushD(int px, int py, queue< pair<int, int> > &fifo, vector< vector<int> > &dist, int d) {
		if ((px < 0) || (py < 0) || (px >= this->width) || (py >= this->height))
			return;
		if (dist[px][py] <= d)
			return;
		dist[px][py] = d;

		fifo.push_back(make_pair(px, py));
	}

public:

	// find empty position closest to x, y
	bool closestEmpty(/*inout */ int &x, /*inout*/ int &y) {
		vector< vector<bool> > visited;
		visited.resize(this->width);
		for (int i = 0; i < this->width; i++)
			visited[i].resize(this->height, false);

		queue<pair<int, int> > fifo;
		Map::pushV(x, y, fifo, visited);

		while (!fifo.empty()) {
			pair<int, int> coords = fifo.pop_front();
			int px = coords.first;
			int py = coords.second;

			if (this->get(px, py) == NULL) {
				x = px;
				y = py;
				return true;
			}

			Map::pushV(px - 0, py - 1, fifo, visited);
			Map::pushV(px - 1, py - 1, fifo, visited);
			Map::pushV(px - 1, py - 0, fifo, visited);
			Map::pushV(px - 1, py + 1, fifo, visited);
			Map::pushV(px + 0, py + 1, fifo, visited);
			Map::pushV(px + 1, py + 1, fifo, visited);
			Map::pushV(px + 1, py + 0, fifo, visited);
			Map::pushV(px + 1, py - 1, fifo, visited);
		}

		return false;
	}

	// find position closest to x, y that fulfills condition f() without passing through something on the way
	bool closest(bool (*f)(T *), /*inout*/ int &x, /*inout*/ int &y) {
		vector< vector<int> > dist;
		dist.resize(this->width);
		for (int i = 0; i < this->width; i++)
			dist[i].resize(this->height, INT_MAX);

		queue<pair<int, int> > fifo;
		Map::pushD(x, y, fifo, dist, 0);

		while (!fifo.empty()) {
			pair<int, int> coords = fifo.pop_front();
			int px = coords.first;
			int py = coords.second;
			int d = dist[px][py];
			T* item = this->get(px, py);

			if (f(item) == true) {
				x = px;
				y = py;
				return true;
			}

			if (item != NULL)
				continue;

			d++;
			Map::pushD(px - 0, py - 1, fifo, dist, d);
			Map::pushD(px - 1, py - 1, fifo, dist, d);
			Map::pushD(px - 1, py - 0, fifo, dist, d);
			Map::pushD(px - 1, py + 1, fifo, dist, d);
			Map::pushD(px + 0, py + 1, fifo, dist, d);
			Map::pushD(px + 1, py + 1, fifo, dist, d);
			Map::pushD(px + 1, py + 0, fifo, dist, d);
			Map::pushD(px + 1, py - 1, fifo, dist, d);
		}

		return false;
	}
};

#endif	// __MAP_HPP__
