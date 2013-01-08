require './Map.rb'
require './MapItem.rb'
require './Player.rb'
require './actions.rb'
require './buildings.rb'
require './units.rb'
# not ruby yet!


class UI
private:
	Map<MapItem> map
	void unit(Player p, Unit u)
	void building(Player p, Building b)

public:
	UI(Map<MapItem> m) : map(m) {}
	void playerTurn(int turn, Player p)
	bool eof()

	static void logAction(Unit u, string action, string desc, pair<int, int> pos = { -1, -1 }, MapItem tgt = nil)
	static void logAction(Building b, string action, string desc, MapItem tgt = nil)
end


template<typename T>
static T choice(string title, const vector<T> options, bool back, function<void(T)> fun = [] (T d) { cout << d.name; } ) {
	printf("%s\n", title.c_str())

	for (unsigned i = 0; i < options.size(); i++) {
		printf("%d. ", i + 1)
		fun(options[i])
		printf("\n")
	end
	if (back)
		printf("0. back\n")

	unsigned i = 0
	do {
		printf("> ")
		cin >> i
		if (cin.eof())
			throw EOF
		if (cin.fail()) {
			cin.clear()
			string s
			cin >> s
			# ignored
		end
	} while (i < (back ? 0 : 1) || i > options.size())

	if (i == 0)
		throw 0
	return options[i - 1]
end

void
unit(Player p, Unit u) {
	# doable actions
	vector<ActionData> acts
	for (unsigned i = 0; i < actions_count; i++)
		if (u.availActions().count( actions[i].type ))
			acts.push_back( actions[i] )

	# buildable buildings
	vector<BuildingData> bld
	for (unsigned i = 0; i < buildings_count; i++)
		if (buildings[i].base == bt_Any)
			bld.push_back( buildings[i] )

	# no unit loop
	printf("Selected unit: %s\n", u.getDetail().c_str())

	if (acts.size() == 0) {
		printf("(no available actions)\n")
		return
	end
	ActionData a = choice("Actions:", acts, true)

	int x, y
	switch (a.type) {
		case at_None:
			x = y = -1
			break

		case at_Move:
		case at_Attack:
		case at_Gather:
		case at_Build:
			printf("target> ")
			cin >> x >> y
			break
	end

	BuildingType bt = bt_Any
	if (a.type == at_Build) {
		function<void(BuildingData)> fun = [] (BuildingData d) {
			printf("%s (gold %d, wood %d)", d.name.c_str(), d.gold, d.wood)
		end
		BuildingData bd = choice("\nBuild what?", bld, false, fun)
		bt = bd.type
	end

	printf("\naction: %s", a.name.c_str())
	if (a.type != at_None)
		printf("(%d, %d)", x, y)
	if (bt)
		printf(" - %s", buildings[bt - 1].name.c_str())
	printf("\n")

	u.queueAction(a.type, x, y, bt)
	printf("Queued: %s\n\n", u.getDetail().c_str())
end

void
building(Player p, Building b) {
	# doable actions
	struct BuAcData {
		string name
		int gold
		int wood
		function<bool(void)> code
	end
	vector< BuAcData > acts

	for (unsigned bb = 0; bb < buildings_count; bb++)
		if (buildings[bb].base == b.Building::getType())
			acts.push_back({ "Upgrade to " + buildings[bb].name, buildings[bb].gold, buildings[bb].wood, [b, bb] () {
				return b.upgrade( buildings[bb].type )
			}})

	for (unsigned uu = 0; uu < units_count; uu++)
		if (units[uu].where == b.getType())
			acts.push_back({ "Build " + units[uu].name, units[uu].gold, units[uu].wood, [b, uu] () {
				return b.create( units[uu].type )
			}})

	# the loop
	for (;;) {
		printf("Selected building: %s\n", b.getDetail().c_str())

		if (acts.size() == 0) {
			printf("(no available actions)\n")
			return
		end

		function< void(BuAcData) > fun = [] (BuAcData d) {
			printf("%s (gold %d, wood %d)", d.name.c_str(), d.gold, d.wood)
		end
		BuAcData c = choice("Actions:", acts, true, fun)
		pair<int, int> pos = b.getPos()
		bool r = c.code()
		printf("%s: %s\n", r ? "OK": "didn't finish", c.name.c_str())

		# after upgrade
		if (@map.get(pos.first, pos.second) != b)
			return
	end
end

void
playerTurn(int turn, Player p) {
	printf("\n\nTah: %d\n", turn)

	printf("Hrac: %s (score %d)\n", p.getName().c_str(), p.getScore())
	printf("\n")

	@map.show()
	printf("\n")

	p.getBuildings().each do |b|
		b.preturnAction()
	end

	for (;;) {
		printf("Gold: %d; Wood: %d\n\n", p.getGold(), p.getWood())

		const vector<Building > buildings = p.getBuildings()
		if (buildings.size()) {
			printf("Available buildings:\n")
			int i = 0
			buildings.each do |b|
				printf("%d. %s\n", ++i, b.getDetail().c_str())
			end
			printf("\n")
		end

		const vector<Unit > units = p.getUnits()
		if (units.size()) {
			printf("Available units:\n")
			int i = 0
			units.each do |u|
				printf("%d. %s\n", ++i, u.getDetail().c_str())
			end
			printf("\n")
		end

		if (units.empty() && buildings.empty()) {
			printf("(no actions available)\n")
			return
		end

		if (cin.eof())
			throw EOF

		char c
		printf("Actions: [u]nit, [b]uilding, [t]urn, reshow [m]ap, [q]uit\n")
		printf("> ")
		cin >> c
		c = toupper(c)

		unsigned u, b

		switch (c) {
			case 'U':
				cin >> u
				if (u < 1 || u > units.size()) {
					printf("unknown unit %d\n", u)
					break
				end
				try {
					self.unit(p, units[u - 1])
				} catch (int e) {
					if (e != 0)
						throw e
				end
				break

			case 'B':
				cin >> b
				if (b < 1 || b > buildings.size()) {
					printf("unknown building %d\n", b)
					break
				end
				try {
					self.building(p, buildings[b - 1])
				} catch (int e) {
					if (e != 0)
						throw e
				end
				break

			case 'T':
				units.each do |u|
					u.performAction()
				end
				return

			case 'Q':
				throw EOF

			case 'M':
				printf("\n")
				@map.show()
				printf("\n")
				break

			default:
				printf("unknown action %c\n", c)
		end
	end
end

bool
eof() {
	return cin.eof()
end

 void
logAction(Unit u, string action, string desc, pair<int, int> pos, MapItem tgt) {
	printf("unit %s: %s", u.getPopis().c_str(), action.c_str())
	if (pos.first >= 0 && pos.second >= 0)
		printf("(%d, %d)", pos.first, pos.second)
	if (tgt)
		printf(" = %s", tgt.getPopis().c_str())
	if (desc != "")
		printf(" %s", desc.c_str())
	printf("\n")
end

 void
logAction(Building b, string action, string desc, MapItem tgt) {
	printf("building %s: %s", b.getPopis().c_str(), action.c_str())
	if (tgt)
		printf(" = %s", tgt.getPopis().c_str())
	if (desc != "")
		printf(" %s", desc.c_str())
	printf("\n")
end
