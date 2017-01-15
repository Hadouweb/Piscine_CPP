#include "NcurseManager.hpp"

NcurseManager::NcurseManager(void) {
	initscr();
	this->setTermSize();
	this->_initMap();
	this->draw();
	noecho();
	nodelay(stdscr,TRUE);
	curs_set(0);
	// Todo context
	//this->initStartMenu();
	//printWindow(this->getStartMenu(), ACS_VLINE, ACS_HLINE);
}

bool NcurseManager::setCell(int y, int x, char c) {
	int height = this->getScreenHeight();
	int width = this->getScreenWidth();

	if (y >= 0 && y < height && x >= 0  && x < width) {
		this->_map[y][x] = c;
		return TRUE;
	}
	return FALSE;
}

void NcurseManager::_setBorder(void) {
	int height = this->getScreenHeight();
	int width = this->getScreenWidth();

	for (int x = 0; x < width; x++) {
		this->_map[0][x] = '*';
		this->_map[height - 1][x] = '*';
	}
}

void NcurseManager::_initMap(void) {
	int height = this->getScreenHeight();
	int width = this->getScreenWidth();

	this->_map = new char*[height];
	for (int i = 0; i < height; i++)
		this->_map[i] = new char[width];

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			this->_map[y][x] = ' ';
		}
	}
	this->_setBorder();
}

void NcurseManager::draw(void) const {
	int height = this->getScreenHeight();
	int width = this->getScreenWidth();

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			mvaddch(y, x, this->_map[y][x]);
		}
	}
	refresh();
}

NcurseManager::NcurseManager(NcurseManager const &src) {
	*this = src;
}

NcurseManager::~NcurseManager(void) {
	endwin();
	// Todo

}

NcurseManager &NcurseManager::operator=(NcurseManager const &rhs) {
	if (this != &rhs)
	{
		// Todo
	}
	return *this;
}


bool NcurseManager::haveEvent(void) {
	int		ch;

	ch = getch();
	if (ch != ERR)
	{
		ungetch(ch);
		return TRUE;
	}
	else
		return FALSE;
}

void NcurseManager::setTermSize(void) {
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	this->_maxHeight = w.ws_row;
	this->_maxWidth = w.ws_col;
}

int NcurseManager::getScreenHeight(void) const {
	return this->_maxHeight;
}

int NcurseManager::getScreenWidth(void) const {
	return this->_maxWidth;
}

bool NcurseManager::setCursorX(int x) {
	int width = this->getScreenWidth();
	if (x >= 0 && x < width) {
		this->setCell(this->_cursorY, this->_cursorX, ' ');
		this->_cursorX = x;
		this->setCell(this->_cursorY, this->_cursorX, '>');
		return TRUE;
	}
	return FALSE;
}

bool NcurseManager::setCursorY(int y) {
	int height = this->getScreenHeight();
	if (y > 0 && y < height - 1) {
		this->setCell(this->_cursorY, this->_cursorX, ' ');
		this->_cursorY = y;
		this->setCell(this->_cursorY, this->_cursorX, '>');
		return TRUE;
	}
	return FALSE;
}

int NcurseManager::getCursorX(void) const {
	return this->_cursorX;
}

int NcurseManager::getCursorY(void) const {
	return this->_cursorY;
}