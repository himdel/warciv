# not ruby yet!




template <typename T>
class Map
	vector< vector< T* > > data

	def Map(w, h)
		@data.resize(w)
		for (int i = 0; i < w; i++)
			@data[i].resize(h, nil)

		@width = w
		@height = h
	end

	def get(x, y)
		if ((x < 0) || (y < 0) || (x >= @width) || (y >= @height)) {
			cerr << "Map::get out of bounds " << x << ", " << y << endl
			return nil
		end

		return @data[x][y]
	end

	def put(int x, int y, T* elem)
		if ((x < 0) || (y < 0) || (x >= @width) || (y >= @height)) {
			cerr << "Map::put out of bounds " << x << ", " << y << endl
			return
		end

		@data[x][y] = elem
	end

	int getWidth() { return @width; }
	int getHeight() { return @height; }

	def show()
		unsigned maxw = 0
		for (int y = 0; y < @height; y++)
			for (int x = 0; x < @width; x++) {
				T mi = @data[x][y]
				maxw = max(maxw, mi ? (unsigned) mi.getPopis().length() : 1)
			end
		maxw++

		printf("   / ")
		for (int x = 0; x < @width; x++)
			printf("%-d", maxw, x)
		printf("\n")

		for (int y = 0; y < @height; y++) {
			printf("%-3d| ", y)
			for (int x = 0; x < @width; x++) {
				T mi = @data[x][y]
				printf("%-s", maxw, mi ? mi.getPopis().c_str() : "-")
			end
			printf("\n")
		end
	end

	~Map() {
		for (int x = 0; x < @width; x++) {
			for (int y = 0; y < @height; y++) {
				@data[x][y] = nil
			end
		end
	end

	def pushV(int px, int py, queue< pair<int, int> > &fifo, vector< vector<bool> > &visited)
		if ((px < 0) || (py < 0) || (px >= @width) || (py >= @height))
			return
		if (visited[px][py])
			return
		visited[px][py] = true

		fifo.push(make_pair(px, py))
	end

	def pushD(int px, int py, queue< pair<int, int> > &fifo, vector< vector<int> > &dist, int d)
		if ((px < 0) || (py < 0) || (px >= @width) || (py >= @height))
			return
		if (dist[px][py] <= d)
			return
		dist[px][py] = d

		fifo.push(make_pair(px, py))
	end

	def getD(pair<int, int> &pos, int px, int py, vector< vector<int> > dist, int d)
		if ((px < 0) || (py < 0) || (px >= @width) || (py >= @height))
			return false

		if (dist[px][py] != d - 1)
			return false

		if (self.get(px, py).nil? == false)
			return false

		pos.first = px
		pos.second = py
		return true
	end

	list< pair<int, int> >
	def wayUp(pair<int, int> pos, vector< vector<int> > dist)
		list< pair<int, int> > ret
		int d, px, py

		while ((d = dist[px = pos.first][py = pos.second]) > 0) {
			ret.push_front(pos)

			bool b = false
			b |= self.getD(pos, px - 0, py - 1, dist, d)
			b |= self.getD(pos, px - 1, py - 1, dist, d)
			b |= self.getD(pos, px - 1, py - 0, dist, d)
			b |= self.getD(pos, px - 1, py + 1, dist, d)
			b |= self.getD(pos, px + 0, py + 1, dist, d)
			b |= self.getD(pos, px + 1, py + 1, dist, d)
			b |= self.getD(pos, px + 1, py + 0, dist, d)
			b |= self.getD(pos, px + 1, py - 1, dist, d)
			if (!b)
				return ret
		end

		return ret
	end


	# find empty position closest to x, y
	pair<int, int>
	def closestEmpty(x, y)
		vector< vector<bool> > visited
		visited.resize(@width)
		for (int i = 0; i < @width; i++)
			visited[i].resize(@height, false)

		queue<pair<int, int> > fifo
		self.pushV(x, y, fifo, visited)

		while (!fifo.empty()) {
			pair<int, int> coords = fifo.front(); fifo.pop()
			int px = coords.first
			int py = coords.second

			if (self.get(px, py).nil?)
				return coords

			self.pushV(px - 0, py - 1, fifo, visited)
			self.pushV(px - 1, py - 1, fifo, visited)
			self.pushV(px - 1, py - 0, fifo, visited)
			self.pushV(px - 1, py + 1, fifo, visited)
			self.pushV(px + 0, py + 1, fifo, visited)
			self.pushV(px + 1, py + 1, fifo, visited)
			self.pushV(px + 1, py + 0, fifo, visited)
			self.pushV(px + 1, py - 1, fifo, visited)
		end

		return make_pair(-1, -1)
	end

	# find position closest to x, y that fulfills condition f() without passing through something on the way
	list< pair<int, int> >
	def closest(function< bool(T , int, int) > f, int x, int y)
		vector< vector<int> > dist
		dist.resize(@width)
		for (int i = 0; i < @width; i++)
			dist[i].resize(@height, INT_MAX)

		queue<pair<int, int> > fifo
		self.pushD(x, y, fifo, dist, 0)

		while (!fifo.empty()) {
			pair<int, int> coords = fifo.front(); fifo.pop()
			int px = coords.first
			int py = coords.second
			int d = dist[px][py]
			T* item = self.get(px, py)

			if (f(item, px, py) == true)
				return self.wayUp(coords, dist)

			if ((item.nil? == false) && ((px != x) || (py != y)))
				continue

			d++
			self.pushD(px - 0, py - 1, fifo, dist, d)
			self.pushD(px - 1, py - 1, fifo, dist, d)
			self.pushD(px - 1, py - 0, fifo, dist, d)
			self.pushD(px - 1, py + 1, fifo, dist, d)
			self.pushD(px + 0, py + 1, fifo, dist, d)
			self.pushD(px + 1, py + 1, fifo, dist, d)
			self.pushD(px + 1, py + 0, fifo, dist, d)
			self.pushD(px + 1, py - 1, fifo, dist, d)
		end

		list< pair<int, int> > ret
		return ret
	end
end

