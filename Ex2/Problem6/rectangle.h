#ifndef RECTANGLE_H
#define RECTANGLE_H
#include<ncurses.h>
#include "shapes.h"

// All the methods gets a pointer of type "Shape", and the window we want to print it on.

void drawRectangle(Shape *pRec, WINDOW *win); 	// Method that draws a Rectangle. It gets a pointer of type "Shape"
						// and the window which it should be printed on.
						
void moveRec(Shape *pRec, WINDOW *win, char c);	// Method that moves the rectangle according to the input.
						// The direction which needed to move the rectangle is inserted 
						// with the char 'c', which takes on of the following options: 
						// 'u'=up, 'd'=down, 'l'=left, 'r'=right.
						// The move is made by changing the Y or X value of the shape
						// and drawing it again.
						
void enlargeRec(Shape *pRec, WINDOW *win);	// Method that making the rectangle bigger by changing its
						// height and width, and draw it again.
						
void shrinkRec(Shape *pRec, WINDOW *win);	// Method that making the rectangle smaller by changing its
						// height and width, and draw it again.


#endif


