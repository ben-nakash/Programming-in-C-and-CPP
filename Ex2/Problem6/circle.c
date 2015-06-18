#include <ncurses.h>
#include "circle.h"

void drawCircle(Shape *pCrc, WINDOW *win)
{
    int i, j;
    int height=pCrc->height, width=pCrc->width, x=pCrc->x, y=pCrc->y;
    double dx,dy;
    wcolor_set(win, pCrc->color, NULL);
 
    for(i = -height ; i <= height ; i++) 
    {
            for(j = -width ; j <= width ; j++) 
            {
                dx = (double)j / (double)width;
                dy = (double)i / (double)height;
                if(dx*dx+dy*dy <= 1) {
                    wmove(win,y+i,x+j);
                    waddstr(win, "*");
                }
            }
    }   
}


void moveCrc(Shape *pCrc, WINDOW *win, char c)
{
	int winY, winX;
	wclear(win);
	getmaxyx(win, winY, winX);
	switch (c) {
		case 'u':
			if (pCrc->y - pCrc->height > 0)
				pCrc->y--;
			break;
		case 'd':
			if ((pCrc->y + pCrc->height + 1) < winY)
				pCrc->y++;
			break;
		case 'l':
			if (pCrc->x - pCrc->width>0)
				pCrc->x--;
			break;
		case 'r':
			if ((pCrc->x + pCrc->width + 1) < winX)
				pCrc->x++;
			break;
	}
	drawCircle(pCrc, win);
} 


void enlargeCrc(Shape *pCrc, WINDOW *win)
{
	int winY, winX;
	int y=pCrc->y , x=pCrc->x, height=pCrc->height, width=pCrc->width;
	getmaxyx(win, winY, winX);
	wclear(win);
	if( (y-height>0) && (y+height+1<winY) && (x+width+2<winX) && (x-width-1>0)) 
	{
		pCrc->width +=2;
		pCrc->height++;
	}
	drawCircle(pCrc, win);
}


void shrinkCrc(Shape *pCrc, WINDOW *win)
{
	wclear(win);
	if (pCrc->width>4 && pCrc->height>2)
	{
		pCrc->width -=2;
		pCrc->height--;
	}
	drawCircle(pCrc, win);
}
