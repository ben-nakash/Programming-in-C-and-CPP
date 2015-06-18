#include <ncurses.h>
#include "rhombus.h"

void drawRhombus(Shape *pRmb , WINDOW *win)
{
	int i,j;
	int counter=0;
	int height=pRmb->height , width=pRmb->width, x=pRmb->x, y=pRmb->y;
	wcolor_set(win, pRmb->color, NULL);
	
	wmove(win, y, x);
	for (i=1 ; i<=height ; i++) {
		for (j=0; j<width-2*counter; j++)
			waddstr(win, "*");
		wmove(win, y+i, x+i);
		counter++;
	}
	
	wmove(win, y, x);
	counter=0;
	
	for (i=1 ; i<=height ; i++) {
		for (j=0; j<width-4*counter; j++)
			waddstr(win, "*");
		wmove(win, y-i, x+i*2);
		counter++;
	} 
	
}

void moveRmb(Shape *pRmb, WINDOW *win, char c)
{
	int winY, winX;
	wclear(win);
	getmaxyx(win, winY, winX);
	switch (c) {
		case 'u':
			if (pRmb->y - pRmb->height/2 > 0)
				pRmb->y--;
			break;
		case 'd':
			if ((pRmb->y + pRmb->height) < winY)
				pRmb->y++;
			break;
		case 'l':
			if (pRmb->x >0) 
				pRmb->x--;
			break;
		case 'r':
			if (pRmb->x + pRmb->width <winX)
				pRmb->x++;
			break;
	}
	drawRhombus(pRmb, win);
} 

void enlargeRmb(Shape *pRmb, WINDOW *win)
{
	int winY, winX;
	int y=pRmb->y , x=pRmb->x, height=pRmb->height, width=pRmb->width;
	getmaxyx(win, winY, winX);
	wclear(win);
	if((y+height+1 < winY) && (y-height/2 > 0) && (x+width+3 < winX))
	{
		pRmb->width +=4;
		pRmb->height+=2;
	}
	drawRhombus(pRmb, win);
}

void shrinkRmb(Shape *pRmb, WINDOW *win)
{
	wclear(win);
	if (pRmb->width>5 && pRmb->height>3)
	{
		pRmb->width -=4;
		pRmb->height-=2;
	}
	drawRhombus(pRmb, win);
}

