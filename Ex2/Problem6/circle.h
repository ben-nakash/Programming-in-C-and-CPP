#ifndef CIRCLE_H
#define CIRCLE_H
#include<ncurses.h>
#include "shapes.h"

// All the methods gets a pointer of type "Shape", and the window we want to print it on.

void drawCircle(Shape *pCrc, WINDOW *win);	// Method that draws a Circle. It gets a pointer of type "Shape"
						// and the window which it should be printed on.
						
void moveCrc(Shape *pCrc, WINDOW *win, char c);	// Method that moves the circle according to the input.
						// The direction which needed to move the circle is inserted 
						// with the char 'c', which takes on of the following options: 
						// 'u'=up, 'd'=down, 'l'=left, 'r'=right.
						// The move is made by changing the Y or X value of the shape
						// and drawing it again.

void enlargeCrc(Shape *pCrc, WINDOW *win);	// Method that making the circle bigger by changing its
						// height and width, and draw it again.

void shrinkCrc(Shape *pCrc, WINDOW *win);	// Method that making the circle smaller by changing its
						// height and width, and draw it again.

#endif


