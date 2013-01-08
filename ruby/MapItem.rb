require './Map.rb'
# not ruby yet!


class MapItem
protected:
	Map<MapItem> map
	int x, y
	std::string popis

public:
	MapItem(std::string popis)
	void place(Map<MapItem> map, int x, int y)
	void place(int x, int y)
	void remove()

	int distance(int x, int y)
	int distance(MapItem i)

	virtual std::string getPopis()
	virtual std::string getDetail()
	virtual ~MapItem(){}

	pair<int, int> getPos() { return make_pair(@x, @y); }
end

std::ostream& operator<<(std::ostream &o, MapItem m)



static int
distance(int x1, int y1, int x2, int y2) {
	int dx = fabs(x1 - x2)
	int dy = fabs(y1 - y2)
	return max(dx, dy)
end


MapItem::MapItem(std::string popis) {
	@popis = popis
	@map = nil
end

void
MapItem::place(Map<MapItem> map, int x, int y) {
	@map = map
	self.place(x, y)
end

void
MapItem::place(int x, int y) {
	@x = x
	@y = y
	@map.put(x, y, self)
end

void
MapItem::remove() {
	assert(@map)
	assert(@map.get(x, y) == self)
	@map.put(x, y, nil)
end

std::string
MapItem::getPopis() {
	return @popis
end

std::string
MapItem::getDetail() {
	return self.getPopis()
end

int
MapItem::distance(int x, int y) {
	return ::distance(@x, @y, x, y)
end

int
MapItem::distance(MapItem i) {
	return ::distance(@x, @y, i.x, i.y)
end

std::ostream&
operator<<(std::ostream &o, MapItem m) {
	return o << (m ? m.getPopis() : "(road)")
end
