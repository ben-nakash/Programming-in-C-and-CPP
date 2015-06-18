#ifndef SHAPES_H
#define SHAPES_H
#include<ncurses.h>

/*--------------------------------------------------------------------------------------------*/
// Defining constant variables

#define RECTANGLE 10
#define TRAPEZE 11
#define TRIANGLE 12
#define CIRCLE 13
#define RHOMBUS 14
#define WIN_FIX 6
#define ON 1
#define OFF 0

/*--------------------------------------------------------------------------------------------*/
				
// Defining the struct of a shape. Each shape, no matter which type of has the same
// characters of - Y/X axis, height, width, color, and a pointer to a next shape in 
// case we need to save the shape.
// The character which distinguish each shape from another is the 'shape' character,
// that holds a constant virable that the software can identify.

typedef struct shape {
	int y, x, height, width, color, shape;
	struct shape *next;
	}Shape;

/*--------------------------------------------------------------------------------------------*/

// The 'init' method is basicly used to draw a "fresh new" draw of the needed shape 
// according to the input (which is checked in main.c file).
// It gets the pointer to the shape, the window it should be drawn to, the middle of
// that window (X/Y axis) to draw the shape in the middle, and an integer that indicates
// which type of shape it is so it would insert it as a character to it.

void init(Shape *pShape, WINDOW *win, int midScrY, int midScrX, int shape);

/*--------------------------------------------------------------------------------------------*/

// drawShape method gets a pointer and the screen to draw the shape on.
// In this method, it only checks which type of shape it is, and then goes to the 
// specific drawing method needed according to it.

void drawShape(Shape *pShape, WINDOW *win);

/*--------------------------------------------------------------------------------------------*/

// moveShape method gets a pointer and the screen to draw the shape on.
// In this method, it only checks which type of shape it is, and then goes to the 
// specific moving method needed according to it.
// The reason I don't have only one moving method for all the shapes is because each
// individual shape need different conditions for the movement so it won't exceed
// the screen boundries.

void moveShape(Shape *pShape, WINDOW *win, char c, int discoMod);

/*--------------------------------------------------------------------------------------------*/

// enlargeShape method gets a pointer and the screen to draw the shape on.
// In this method, it only checks which type of shape it is, and then goes to the 
// specific enlarge method needed according to it.
// The reason I don't have only one enlargement method for all the shapes is because each
// individual shape need different conditions for making it larger so it won't exceed
// the screen boundries.

void enlargeShape(Shape *pShape, WINDOW *win, int discoMod);

/*--------------------------------------------------------------------------------------------*/
	
// shrinkShape method gets a pointer and the screen to draw the shape on.
// In this method, it only checks which type of shape it is, and then goes to the 
// specific enlarge method needed according to it.

void shrinkShape(Shape *pShape, WINDOW *win, int discoMod);

/*--------------------------------------------------------------------------------------------*/

// changeColor method is used for changing the color character of the given shape.

void changeColor(Shape *pShape, WINDOW *win);

/*--------------------------------------------------------------------------------------------*/

// saveShape method is used to save the shape in order to show it later if given the specific
// input. It creates a new pointer of type "shape" and stores all the characters of the current
// shape into it. The saving of the shapes works in a linked list.
// If the head of the list is still NULL (nothing saved) then it links the head to the new created
// shape. If the head is not NULL (which means the linked list isn't empty) it goes all the way to
// the end of the list (with the 'next' pointer character) and insert the new shape as the last shape
// in the list.

Shape* saveShape(Shape *pHead, int y, int x, int height, int width, int color, int shape);

/*--------------------------------------------------------------------------------------------*/

// drawSavedShapes is a method to draw all the saved shapes. It goes in a loop and each
// shape it prints and go to the next one.

void drawSavedShapes(Shape *pHead, Shape *temp, WINDOW *win);

/*--------------------------------------------------------------------------------------------*/

// These methods is bonus methods I added as a bonus. When pressed 'd' it triggers "Disco Mod"
// on and off. When this mod is on, each move or making the shape bigger/smaller chenges the 
// shapes color.

int disco(int discoMod);
int checkDisco(int discoMod);

/*--------------------------------------------------------------------------------------------*/

// This method free all the memory allocated to the saved shapes. It gets pHead & temp pointers
// to free up the memory of the currently saved shapes.

void clearList(Shape *pHead, Shape *temp);

/*--------------------------------------------------------------------------------------------*/

#endif


