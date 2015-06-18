#ifndef RHOMBUS_H
#define RHOMBUS_H
#include<ncurses.h>
#include "shapes.h"

// All the methods gets a pointer of type "Shape", and the window we want to print it on.

void drawRhombus(Shape *pRmb, WINDOW *win);	// Method that draws a Rhombus. It gets a pointer of type "Shape"
						// and the window which it should be printed on.

void moveRmb(Shape *pRmb, WINDOW *win, char c);	// Method that moves the rhombus according to the input.
						// The direction which needed to move the rhombus is inserted 
						// with the char 'c', which takes on of the following options: 
						// 'u'=up, 'd'=down, 'l'=left, 'r'=right.
						// The move is made by changing the Y or X value of the shape
						// and drawing it again.

void enlargeRmb(Shape *pRmb, WINDOW *win);	// Method that making the rhombus bigger by changing its
						// height and width, and draw it again.

void shrinkRmb(Shape *pRmb, WINDOW *win);	// Method that making the rhombus smaller by changing its
						// height and width, and draw it again.

#endif


