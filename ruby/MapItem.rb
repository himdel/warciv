require './Map.rb'
# not ruby yet!


class MapItem
	Map<MapItem> map
	int x, y

	MapItem(popis)
	void place(Map<MapItem> map, int x, int y)
	void place(x, y)
	void remove()

	int distance(x, y)
	int distance(i)

	virtual string getPopis()
	virtual string getDetail()
	virtual ~MapItem(){}

	pair<int, int> getPos() { return make_pair(@x, @y); }
end

ostream& operator<<(ostream &o, MapItem m)



def distance(x1, y1, x2, y2)
	int dx = fabs(x1 - x2)
	int dy = fabs(y1 - y2)
	return max(dx, dy)
end


def MapItem(popis)
	@popis = popis
	@map = nil
end

def place(Map<MapItem> map, int x, int y)
	@map = map
	self.place(x, y)
end

def place(x, y)
	@x = x
	@y = y
	@map.put(x, y, self)
end

def remove()
	assert(@map)
	assert(@map.get(x, y) == self)
	@map.put(x, y, nil)
end

def getPopis()
	return @popis
end

def getDetail()
	return self.getPopis()
end

def distance(x, y)
	return ::distance(@x, @y, x, y)
end

def distance(i)
	return ::distance(@x, @y, i.x, i.y)
end

ostream&
operator<<(ostream &o, MapItem m) {
	return o << (m ? m.getPopis() : "(road)")
end
