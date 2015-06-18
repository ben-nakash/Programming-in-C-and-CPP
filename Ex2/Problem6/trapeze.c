#include <ncurses.h>
#include "trapeze.h"

void drawTrapeze(Shape *pTrp , WINDOW *win)
{
	int i,j;
	int counter=0;
	wcolor_set(win, pTrp->color, NULL);
	
	wmove(win, pTrp->y, pTrp->x);

	for (i=1 ; i<=pTrp->height ; i++) {
		for (j=1 ; j<=pTrp->width-counter*2 ; j++) {
			waddstr(win, "*");
		}
		wmove(win, pTrp->y+i, pTrp->x+i);
		counter++;
	}
}

void moveTrp(Shape *pTrp, WINDOW *win, char c)
{
	int winY, winX;
	wclear(win);
	getmaxyx(win, winY, winX);
	switch (c) {
		case 'u':
			if (pTrp->y > 0)
				pTrp->y--;
			break;
		case 'd':
			if ((pTrp->y + pTrp->height) < winY)
				pTrp->y++;
			break;
		case 'l':
			if (pTrp->x > 0) {
				wclear(win);
				pTrp->x--;
			}
			break;
		case 'r':
			if (pTrp->x + pTrp->width <winX) {
				wclear(win);
				pTrp->x++;
			}
			break;
	}
	drawTrapeze(pTrp, win);
} 

void enlargeTrp(Shape *pTrp, WINDOW *win)
{
	int winY, winX;
	getmaxyx(win, winY, winX);
	wclear(win);
	if((pTrp->x + 1 > 0) && (pTrp->x + pTrp->width +2 <winX) && (pTrp->y + pTrp->height <winY)) 
	{
		pTrp->width +=3;
		pTrp->height++;
	}
	drawTrapeze(pTrp, win);
}

void shrinkTrp(Shape *pTrp, WINDOW *win)
{
	wclear(win);
	if (pTrp->width>11 && pTrp->height>2)
	{
		pTrp->width -=3;
		pTrp->height--;
	}
	drawTrapeze(pTrp, win);
}

