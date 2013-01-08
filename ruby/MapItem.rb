require './Map.rb'
# not ruby yet!


class MapItem
	Map<MapItem> map
	int x, y

	MapItem(string popis)
	void place(Map<MapItem> map, int x, int y)
	void place(int x, int y)
	void remove()

	int distance(int x, int y)
	int distance(MapItem i)

	virtual string getPopis()
	virtual string getDetail()
	virtual ~MapItem(){}

	pair<int, int> getPos() { return make_pair(@x, @y); }
end

ostream& operator<<(ostream &o, MapItem m)



distance(int x1, int y1, int x2, int y2) {
	int dx = fabs(x1 - x2)
	int dy = fabs(y1 - y2)
	return max(dx, dy)
end


MapItem(string popis) {
	@popis = popis
	@map = nil
end

place(Map<MapItem> map, int x, int y) {
	@map = map
	self.place(x, y)
end

place(int x, int y) {
	@x = x
	@y = y
	@map.put(x, y, self)
end

remove() {
	assert(@map)
	assert(@map.get(x, y) == self)
	@map.put(x, y, nil)
end

getPopis() {
	return @popis
end

getDetail() {
	return self.getPopis()
end

distance(int x, int y) {
	return ::distance(@x, @y, x, y)
end

distance(MapItem i) {
	return ::distance(@x, @y, i.x, i.y)
end

ostream&
operator<<(ostream &o, MapItem m) {
	return o << (m ? m.getPopis() : "(road)")
end
