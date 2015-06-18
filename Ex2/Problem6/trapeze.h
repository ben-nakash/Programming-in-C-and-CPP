#ifndef TRAPEZE_H
#define TRAPEZE_H
#include<ncurses.h>
#include "shapes.h"

// All the methods gets a pointer of type "Shape", and the window we want to print it on.

void drawTrapeze(Shape *pTrp, WINDOW *win);	// Method that draws a Trapeze. It gets a pointer of type "Shape"
						// and the window which it should be printed on.

void moveTrp(Shape *pTrp, WINDOW *win, char c);	// Method that moves the trapeze according to the input.
						// The direction which needed to move the trapeze is inserted 
						// with the char 'c', which takes on of the following options: 
						// 'u'=up, 'd'=down, 'l'=left, 'r'=right.
						// The move is made by changing the Y or X value of the shape
						// and drawing it again.

void enlargeTrp(Shape *pTrp, WINDOW *win);	// Method that making the trapeze bigger by changing its
						// height and width, and draw it again.

void shrinkTrp(Shape *pTrp, WINDOW *win);	// Method that making the trapeze smaller by changing its
						// height and width, and draw it again.

#endif


