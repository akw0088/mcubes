#include "include.h"

#ifndef ENGINE_H
#define ENGINE_H

class Engine
{
public:
	void init(void *param1, void *param2);
	void destroy();
	void quit();

	void render();
	void resize(int width, int height);

	void step();

private:
	int	time;
	void	*param1;
	void	*param2;
	HWND	hwnd;
	HDC	hdc;
};

#endif

