#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include "shapes.h"

void init(Shape *pShape, WINDOW *win, int midScrY, int midScrX, int shape)
{
	wclear(win);
	pShape->y = midScrY;
	pShape->x = midScrX;
	pShape->color = 1;
	pShape->shape = shape;
	wcolor_set(win, pShape->color, NULL);
	
	switch(pShape->shape) {
		case RECTANGLE:	pShape->height = 3;
				pShape->width = 10;
				break;
			
		case TRAPEZE:	pShape->height = 3;
				pShape->width = 14;
				break;
			
		case TRIANGLE:	pShape->height = 5;
				pShape->width = 9;
				break;
			
		case CIRCLE:	pShape->height = 3;
				pShape->width = 6;
				break;
			
		case RHOMBUS:	pShape->height = 5;
				pShape->width = 9;
				break;
	}
	drawShape(pShape, win);	
}


void drawShape(Shape *pShape, WINDOW *win)
{
	switch(pShape->shape) {
		case RECTANGLE:	drawRectangle(pShape, win);
				break;
		case TRAPEZE:	drawTrapeze  (pShape, win);
				break;
		case TRIANGLE:	drawTriangle (pShape, win);
				break;
		case CIRCLE:	drawCircle   (pShape, win);
				break;
		case RHOMBUS:	drawRhombus  (pShape, win);
				break;
	}
}


void moveShape(Shape *pShape, WINDOW *win, char c, int discoMod)
{
	if (checkDisco(discoMod)==ON)
		changeColor(pShape, win);
		
	switch(pShape->shape) {
		case RECTANGLE:
			switch(c) {
				case 'u': moveRec(pShape, win, 'u');
					  break;
				case 'd': moveRec(pShape, win, 'd');
					  break;
				case 'l': moveRec(pShape, win, 'l');
					  break;
				case 'r': moveRec(pShape, win, 'r');
					  break;
			}
			break;
		
		case TRAPEZE:
			switch(c) {
				case 'u': moveTrp(pShape, win, 'u');
					  break;
				case 'd': moveTrp(pShape, win, 'd');
					  break;
				case 'l': moveTrp(pShape, win, 'l');
					  break;
				case 'r': moveTrp(pShape, win, 'r');
					  break;
			}
			break;
		
		case TRIANGLE:
			switch (c) {
				case 'u': moveTrg(pShape, win, 'u');
					  break;
				case 'd': moveTrg(pShape, win, 'd');
					  break;
				case 'l': moveTrg(pShape, win, 'l');
					  break;
				case 'r': moveTrg(pShape, win, 'r');
					  break;
			}
			break;
			
		case CIRCLE:
			switch(c) {
				case 'u': moveCrc(pShape, win, 'u');
					  break;
				case 'd': moveCrc(pShape, win, 'd');
					  break;
				case 'l': moveCrc(pShape, win, 'l');
					  break;
				case 'r': moveCrc(pShape, win, 'r');
					  break;
			}
			break;
			
		case RHOMBUS:
			switch(c) {
				case 'u': moveRmb(pShape, win, 'u');
					  break;
				case 'd': moveRmb(pShape, win, 'd');
					  break;
				case 'l': moveRmb(pShape, win, 'l');
					  break;
				case 'r': moveRmb(pShape, win, 'r');
					  break;
			}
			break;
	}
}


void enlargeShape(Shape *pShape, WINDOW *win, int discoMod)
{
	if (checkDisco(discoMod)==ON)
		changeColor(pShape, win);
	
	switch(pShape->shape) {
		case RECTANGLE:	enlargeRec(pShape, win);
				break;
				
		case TRAPEZE:	enlargeTrp(pShape, win);
				break;
				
		case TRIANGLE:	enlargeTrg(pShape, win);
				break;
				
		case CIRCLE:	enlargeCrc(pShape, win);
				break;
				
		case RHOMBUS:	enlargeRmb(pShape, win);
				break;
	}
}


void shrinkShape(Shape *pShape, WINDOW *win, int discoMod)
{
	if (checkDisco(discoMod)==ON)
		changeColor(pShape, win);
	
	switch(pShape->shape) {
		case RECTANGLE:	shrinkRec(pShape, win);
				break;
				
		case TRAPEZE:	shrinkTrp(pShape, win);
				break;
				
		case TRIANGLE:	shrinkTrg(pShape, win);
				break;
				
		case CIRCLE:	shrinkCrc(pShape, win);
				break;
				
		case RHOMBUS:	shrinkRmb(pShape, win);
				break;
	}
}


void changeColor(Shape *pShape, WINDOW *win)
{
	pShape->color++;
	if (pShape->color > 7)
		pShape->color=1;
	drawShape(pShape, win);
}


int disco(int discoMod)
{
	if (discoMod == OFF)
		return discoMod = ON;
	else
		return discoMod = OFF;
}

int checkDisco(int discoMod)
{
	if (discoMod == OFF)
		return OFF;
	else
		return ON;
}


Shape* saveShape(Shape *pHead, int y, int x, int height, int width, int color, int shape)
{
	if (shape==0)
		return pHead;
	Shape* newShape;
	Shape* temp;
	
	newShape = (Shape*)malloc(sizeof(Shape));
	newShape->y = y;
	newShape->x = x;
	newShape->height = height;
	newShape->width = width;
	newShape->color = color;
	newShape->shape = shape;
	newShape->next = NULL;
	
	if(pHead == NULL)
		pHead = newShape;
	else
	{
		for (temp=pHead ; temp->next != NULL ; temp=temp->next);
		temp->next=newShape;
	}
	return pHead;
}


void drawSavedShapes(Shape *pHead, Shape *temp, WINDOW *win)
{
	if (pHead==NULL)
		return;
	wclear(win);
	for (temp=pHead ; temp != NULL ; temp=temp->next)
		drawShape(temp, win);
}


void clearList(Shape *pHead, Shape *temp)
{
	if (pHead == NULL) 
		return;
	else {
		temp = pHead;
		while(pHead->next != NULL) {
			temp=pHead->next;
			free(pHead);
			pHead=temp;
		}
		free(pHead);
	}
}



















