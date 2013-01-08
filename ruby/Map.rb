# not ruby yet!


using namespace std;


template <typename T>
class Map
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
		if ((x < 0) || (y < 0) || (x >= this->width) || (y >= this->height)) {
			cerr << "Map::get out of bounds " << x << ", " << y << endl;
			return NULL;
		}

		return this->data[x][y];
	}

	void put(int x, int y, T* elem) {
		if ((x < 0) || (y < 0) || (x >= this->width) || (y >= this->height)) {
			cerr << "Map::put out of bounds " << x << ", " << y << endl;
			return;
		}

		this->data[x][y] = elem;
	}

	int getWidth() { return this->width; }
	int getHeight() { return this->height; }

	void show() {
		unsigned maxw = 0;
		for (int y = 0; y < this->height; y++)
			for (int x = 0; x < this->width; x++) {
				T *mi = this->data[x][y];
				maxw = std::max(maxw, mi ? (unsigned) mi->getPopis().length() : 1);
			}
		maxw++;

		printf("   / ");
		for (int x = 0; x < this->width; x++)
			printf("%-*d", maxw, x);
		printf("\n");

		for (int y = 0; y < this->height; y++) {
			printf("%-3d| ", y);
			for (int x = 0; x < this->width; x++) {
				T *mi = this->data[x][y];
				printf("%-*s", maxw, mi ? mi->getPopis().c_str() : "-");
			}
			printf("\n");
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
	void pushV(int px, int py, queue< pair<int, int> > &fifo, vector< vector<bool> > &visited) {
		if ((px < 0) || (py < 0) || (px >= this->width) || (py >= this->height))
			return;
		if (visited[px][py])
			return;
		visited[px][py] = true;

		fifo.push(make_pair(px, py));
	}

	void pushD(int px, int py, queue< pair<int, int> > &fifo, vector< vector<int> > &dist, int d) {
		if ((px < 0) || (py < 0) || (px >= this->width) || (py >= this->height))
			return;
		if (dist[px][py] <= d)
			return;
		dist[px][py] = d;

		fifo.push(make_pair(px, py));
	}

	bool getD(pair<int, int> &pos, int px, int py, vector< vector<int> > dist, int d) {
		if ((px < 0) || (py < 0) || (px >= this->width) || (py >= this->height))
			return false;

		if (dist[px][py] != d - 1)
			return false;

		if (this->get(px, py) != NULL)
			return false;

		pos.first = px;
		pos.second = py;
		return true;
	}

	list< pair<int, int> >
	wayUp(pair<int, int> pos, vector< vector<int> > dist) {
		list< pair<int, int> > ret;
		int d, px, py;

		while ((d = dist[px = pos.first][py = pos.second]) > 0) {
			ret.push_front(pos);

			bool b = false;
			b |= this->getD(pos, px - 0, py - 1, dist, d);
			b |= this->getD(pos, px - 1, py - 1, dist, d);
			b |= this->getD(pos, px - 1, py - 0, dist, d);
			b |= this->getD(pos, px - 1, py + 1, dist, d);
			b |= this->getD(pos, px + 0, py + 1, dist, d);
			b |= this->getD(pos, px + 1, py + 1, dist, d);
			b |= this->getD(pos, px + 1, py + 0, dist, d);
			b |= this->getD(pos, px + 1, py - 1, dist, d);
			if (!b)
				return ret;
		}

		return ret;
	}

public:

	# find empty position closest to x, y
	pair<int, int>
	closestEmpty(int x, int y) {
		vector< vector<bool> > visited;
		visited.resize(this->width);
		for (int i = 0; i < this->width; i++)
			visited[i].resize(this->height, false);

		queue<pair<int, int> > fifo;
		this->pushV(x, y, fifo, visited);

		while (!fifo.empty()) {
			pair<int, int> coords = fifo.front(); fifo.pop();
			int px = coords.first;
			int py = coords.second;

			if (this->get(px, py) == NULL)
				return coords;

			this->pushV(px - 0, py - 1, fifo, visited);
			this->pushV(px - 1, py - 1, fifo, visited);
			this->pushV(px - 1, py - 0, fifo, visited);
			this->pushV(px - 1, py + 1, fifo, visited);
			this->pushV(px + 0, py + 1, fifo, visited);
			this->pushV(px + 1, py + 1, fifo, visited);
			this->pushV(px + 1, py + 0, fifo, visited);
			this->pushV(px + 1, py - 1, fifo, visited);
		}

		return make_pair(-1, -1);
	}

	# find position closest to x, y that fulfills condition f() without passing through something on the way
	list< pair<int, int> >
	closest(function< bool(T *, int, int) > f, int x, int y) {
		vector< vector<int> > dist;
		dist.resize(this->width);
		for (int i = 0; i < this->width; i++)
			dist[i].resize(this->height, INT_MAX);

		queue<pair<int, int> > fifo;
		this->pushD(x, y, fifo, dist, 0);

		while (!fifo.empty()) {
			pair<int, int> coords = fifo.front(); fifo.pop();
			int px = coords.first;
			int py = coords.second;
			int d = dist[px][py];
			T* item = this->get(px, py);

			if (f(item, px, py) == true)
				return this->wayUp(coords, dist);

			if ((item != NULL) && ((px != x) || (py != y)))
				continue;

			d++;
			this->pushD(px - 0, py - 1, fifo, dist, d);
			this->pushD(px - 1, py - 1, fifo, dist, d);
			this->pushD(px - 1, py - 0, fifo, dist, d);
			this->pushD(px - 1, py + 1, fifo, dist, d);
			this->pushD(px + 0, py + 1, fifo, dist, d);
			this->pushD(px + 1, py + 1, fifo, dist, d);
			this->pushD(px + 1, py + 0, fifo, dist, d);
			this->pushD(px + 1, py - 1, fifo, dist, d);
		}

		list< pair<int, int> > ret;
		return ret;
	}
end

