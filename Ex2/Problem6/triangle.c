#include <ncurses.h>
#include "triangle.h"

void drawTriangle(Shape *pTrg , WINDOW *win)
{
	int i,j;
	int counter=0;
	wcolor_set(win, pTrg->color, NULL);
	
	wmove(win, pTrg->y, pTrg->x);

	for (i=1 ; i<=pTrg->height ; i++) {
		for (j=0; j<pTrg->width-2*counter; j++)
			waddstr(win, "*");
		wmove(win, pTrg->y+i, pTrg->x+i);
		counter++;
	}
}


void moveTrg(Shape *pTrg, WINDOW *win, char c)
{
	int winY, winX;
	wclear(win);
	getmaxyx(win, winY, winX);
	switch (c) {
		case 'u':
			if (pTrg->y > 0)
				pTrg->y--;
			break;
		case 'd':
			if ((pTrg->y + pTrg->height) < winY)
				pTrg->y++;
			break;
		case 'l':
			if (pTrg->x > 0)
				pTrg->x--; 
			break;
		case 'r':
			if ((pTrg->x + pTrg->width) < winX)
				pTrg->x++;
			break;
	}
	drawTriangle(pTrg, win);
} 


void enlargeTrg(Shape *pTrg, WINDOW *win)
{
	int winY, winX;
	getmaxyx(win, winY, winX);
	wclear(win);
	if ((pTrg->y + pTrg->height < winY) && (pTrg->x + pTrg->width + 1 < winX))
	{
		pTrg->width +=2;
		pTrg->height++;
	}
	drawTriangle(pTrg, win);
}


void shrinkTrg(Shape *pTrg, WINDOW *win)
{
	wclear(win);
	if (pTrg->width>5 && pTrg->height>3)
	{
		pTrg->width -=2;
		pTrg->height--;
	}
	drawTriangle(pTrg, win);
}

