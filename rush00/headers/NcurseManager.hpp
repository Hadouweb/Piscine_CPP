#ifndef NCURSE_MANAGER_HPP
# define NCURSE_MANAGER_HPP

#include <sys/ioctl.h>
#include <unistd.h>
#include <ncurses.h>
#include <iostream>

/*
** DEFINE NCURSES
*/
# define KEY_SPACE 32
# define KEY_UP_ARROW 65
# define KEY_DOWN_ARROW 66
# define KEY_RIGHT_ARROW 67
# define KEY_LEFT_ARROW 68
# define KEY_ESC -1


class NcurseManager {
public:
    NcurseManager(void);
    NcurseManager(NcurseManager const & src);
    ~NcurseManager(void);
    NcurseManager & operator=(NcurseManager const & rhs);

	static bool haveEvent(void);
	void setTermSize(void);
	int getScreenHeight(void) const;
	int getScreenHeightMin(void) const;
	int getScreenWidth(void) const;
	int getCursorX(void) const;
	int getCursorY(void) const;
	bool setCursorX(int x);
	bool setCursorY(int y);
	void draw(int score) const;
	bool setCell(int y, int x, char c);
	bool isResized(void) const;
	char **getMap(void) const;

private:
	void _initMap(void);
	void _setBorder(void);
	int _maxWidth;
	int _maxHeight;
	int _cursorX;
	int _cursorY;
	char **_map;
};

#endif