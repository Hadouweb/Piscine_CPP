#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

class Wall {
public:
	Wall(void) { };

	int id;
	int x;
	int y;
	char orientation;
};

ostream & operator<<(ostream & os, Wall const & w) {
	os << "x: " << w.x << " y: " << w.y << " o: " << w.orientation;
	return os;
};

class Player {
public:
	Player(void) { };
	Player & operator=(Player const & rhs) {
		x = rhs.x;
		y = rhs.y;
		wallsLeft = rhs.wallsLeft;
		id = rhs.id;
		dir = rhs.dir;
	}

	void setDir(void) {
		if (id == 0)
			dir = 'r';
		else if (id == 1)
			dir = 'l';
		else if (id == 2)
			dir = 'd';
	}

	int id;
	int x;
	int y;
	int wallsLeft;
	char dir;
};

ostream & operator<<(ostream & os, Player const & p) {
	os << "id: " << p.id << " x: " << p.x << " y: " << p.y << " wLeft: " << p.wallsLeft << " dir: " << p.dir;
	return os;
};

class Board {
public:
	Board(int pW, int pH, int pNbPlayer) : w(pW), h(pH), nbPlayer(pNbPlayer) {
		this->players = vector<Player>(nbPlayer);
		this->walls = vector<Wall>(50);
	};
	void addPlayer(Player & p) {
		players[p.id] = p;
		if (players[p.id].dir == '0')
			players[p.id].setDir();
		cerr << players[p.id] << endl;
	}
	void addWall(Wall & w) {
		walls[w.id] = w;
	}
	void addCurrentPlayers(void) {
		previousPlayers.push_back(players);
	}

	int myId;
	int w;
	int h;
	int nbPlayer;
	int nbWall;
	vector<Wall> walls;
	vector<Player> players;
	list< vector<Player> > previousPlayers;
};

ostream & operator<<(ostream & os, Board const & b) {
	os << "w: " << b.w << " h: " << b.h << " nbPlayer: " << b.nbPlayer << endl;
	for(vector<Wall>::const_iterator it = b.walls.begin(); it != b.walls.end(); ++it) {
		os << *it << endl;
	}
	for(vector<Player>::const_iterator it = b.players.begin(); it != b.players.end(); ++it) {
		os << *it << endl;
	}
	return os;
};

bool isWall(int x, int y, Board & b) {
	for(vector<Wall>::const_iterator it = b.walls.begin(); it != b.walls.end(); ++it) {
		if ((*it).orientation == 'V' && (((*it).x == x && (*it).y == y) || ((*it).x == x && (*it).y - 1 == y)))
			return true;
		if ((*it).orientation == 'H' && (((*it).x == x && (*it).y == y) || ((*it).x + 1 == x && (*it).y == y)))
			return true;
	}
	return false;
}

bool putWall(Board & b) {
	vector<Player> p = b.players;
	Player pEnemy;
	for(vector<Player>::const_iterator it = p.begin(); it != p.end(); it++) {
		if ((*it).id != b.myId)
			pEnemy = *it;
	}
	//cerr << pEnemy << endl;
	int y = pEnemy.y;
	int x = pEnemy.x;
	if (y < 1)
		y = 1;
	if (y > 8)
		y = 8;
	if (x < 1)
		x = 1;
	if (x > 8)
		x = 8;
	if (isWall(x, y, b))
		return false;
	if (pEnemy.dir == 'l')
		cout << x << " " << y << " V" << endl;
	else if (pEnemy.dir == 'r')
		cout << pEnemy.x + 1 << " " << y << " V" << endl;
	else if (pEnemy.dir == 'd')
		cout << x << " " << y << " H" << endl;
	return true;
}

void move(Board & b) {

	if (b.players[b.myId].dir == 'r') {
		if (isWall(b.players[b.myId].x, b.players[b.myId].y, b) && b.players[b.myId].y > 2)
			cout << "UP" << endl;
		cout << "RIGHT" << endl;
	}
	else if (b.players[b.myId].dir == 'l') {
		if (isWall(b.players[b.myId].x, b.players[b.myId].y, b) && b.players[b.myId].y > 2)
			cout << "UP" << endl;
		cout << "LEFT" << endl;
	}
	else if (b.players[b.myId].dir == 'd') {
		if (isWall(b.players[b.myId].x, b.players[b.myId].y, b) && b.players[b.myId].x > 2)
			cout << "LEFT" << endl;
		cout << "DOWN" << endl;
	}
}

int main()
{
	int w, h, playerCount, myId;
	cin >> w >> h >> playerCount >> myId; cin.ignore();
	Board b(w, h, playerCount);
	b.myId = myId;

	while (1) {
		for (int i = 0; i < playerCount; i++) {
			Player a;
			cin >> a.x >> a.y >> a.wallsLeft; cin.ignore();
			a.id = i;
			a.setDir();
			b.addPlayer(a);
		}
		cin >> b.nbWall; cin.ignore();
		for (int i = 0; i < b.nbWall; i++) {
			Wall w;
			cin >> w.x >> w.y >> w.orientation; cin.ignore();
			w.id = i;
			b.addWall(w);
		}
		b.addCurrentPlayers();
		bool havePutWall = false;
		if (b.players[b.myId].wallsLeft >= 3)
			putWall(b);
		else
			move(b);
		if (havePutWall == false)
			move(b);

		cerr << b << endl;
	}
}