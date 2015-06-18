#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <ncurses.h>
#include "shapes.h"

// All the methods gets a pointer of type "Shape", and the window we want to print it on.

void drawTriangle(Shape *pTrg, WINDOW *win);	// Method that draws a Triangle. It gets a pointer of type "Shape"
						// and the window which it should be printed on.

void moveTrg(Shape *pTrg, WINDOW *win, char c);	// Method that moves the triangle according to the input.
						// The direction which needed to move the triangle is inserted 
						// with the char 'c', which takes on of the following options: 
						// 'u'=up, 'd'=down, 'l'=left, 'r'=right.
						// The move is made by changing the Y or X value of the shape
						// and drawing it again.

void enlargeTrg(Shape *pTrg, WINDOW *win);	// Method that making the triangle bigger by changing its
						// height and width, and draw it again.

void shrinkTrg(Shape *pTrg, WINDOW *win);	// Method that making the triangle smaller by changing its
						// height and width, and draw it again.

#endif


