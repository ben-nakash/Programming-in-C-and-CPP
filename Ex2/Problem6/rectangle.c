#include <ncurses.h>
#include "rectangle.h"

void drawRectangle(Shape *pRec , WINDOW *win)
{
	int i,j;
	wmove(win, pRec->y,pRec->x);
	wcolor_set(win, pRec->color, NULL);

	for (i=0 ; i <= pRec->height ; i++) {
		for (j=0; j < pRec->width ; j++)
			waddstr(win, "*");
		wmove(win, pRec->y+i, pRec->x);		
	}
}


void moveRec(Shape *pRec, WINDOW *win, char c)
{
	int winY, winX;
	wclear(win);
	getmaxyx(win, winY, winX);
	switch (c) {
		case 'u':			
			if (pRec->y > 0)
				pRec->y--;
			break;
		case 'd':
			if ((pRec->y + pRec->height) < winY)
				pRec->y++;
			break;
		case 'l':
			if (pRec->x>0)
				pRec->x--;
			break;
		case 'r':
			if ((pRec->x + pRec->width) < winX)
				pRec->x++;
			break;
	}
	drawRectangle(pRec, win);
} 


void enlargeRec(Shape *pRec, WINDOW *win)
{
	int winY, winX;
	getmaxyx(win, winY, winX);
	wclear(win);
	if((pRec->x+pRec->width+2 < winX)&&(pRec->y+pRec->height < winY)) 
	{
		pRec->width +=3;
		pRec->height++;
	}
	drawRectangle(pRec, win);
}


void shrinkRec(Shape *pRec, WINDOW *win)
{
	wclear(win);
	if (pRec->width>9)
		pRec->width -=3;
	if (pRec->height>2)
		pRec->height--;
	drawRectangle(pRec, win);
}
