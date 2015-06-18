// Name: Ben Nakash.
// I.D : 303140057

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "rectangle.h"
#include "triangle.h"
#include "trapeze.h"
#include "rhombus.h"
#include "circle.h"
#include "shapes.h"

int main(int argc, char* argv[])
{
	if (argc != 2) {
		printf("Invalid input, Please enter a file name. \n");
		return 0;
	}	
	
	// Defining Variables
	int mainWinY, mainWinX, secWinY, secWinX, input, lastShape, midScrY, midScrX, i;
	int y,x,height,width,color,shape;
	int discoMod=OFF;
	
	FILE *file;
	
	/*--------------------------------------------------------------------------------------*/
	
	// Creating the Pointers for the current shape, the Head of the linked list,
	// and a temporary pointer.
	Shape *pShape = (Shape *)malloc(sizeof(Shape));
	Shape *pHead = NULL;
	Shape *temp;

	/*--------------------------------------------------------------------------------------*/
	
	// Creating windows and placing their height & width in integers.
	// The Main Window is used only for the menu. The Secnodary window comes above it and  
	// used for printing the shapes
 	WINDOW *mainWin = initscr();
	getmaxyx(mainWin, mainWinY, mainWinX);
	WINDOW *secWin = newwin(mainWinY-WIN_FIX, mainWinX, 0, 0);	
	getmaxyx(secWin, secWinY, secWinX);
	
	midScrY = secWinY/2;
	midScrX = secWinX/2;
	
	/*--------------------------------------------------------------------------------------*/
	
	// Some functions 
	curs_set(0);		// Make the typing mark invisible.
	noecho();		// Make that we won't see the keyboard input on screen.
	keypad(stdscr, TRUE);	// Applying the use of the Arrows Keys.
	
	/*--------------------------------------------------------------------------------------*/
	
	// Enable the use of colors and Defining the them.
	start_color();
	if (has_colors() && COLOR_PAIRS >= 6)	{
	 	init_pair(1, COLOR_WHITE  , COLOR_BLACK);
	 	init_pair(2, COLOR_RED    , COLOR_BLACK);
	 	init_pair(3, COLOR_GREEN  , COLOR_BLACK);
		init_pair(4, COLOR_YELLOW , COLOR_BLACK);
	 	init_pair(5, COLOR_CYAN   , COLOR_BLACK);
	 	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	 	init_pair(7, COLOR_BLUE   , COLOR_BLACK);
	}
	
	/*--------------------------------------------------------------------------------------*/
	
	// Creating the menu 
	
	wcolor_set(mainWin, 5, NULL);
	move(mainWinY-WIN_FIX, 0);
	for (i=0 ; i<mainWinX/2-2 ; i++) {
		waddch(mainWin, ACS_RARROW); 
	}
	addstr("Menu");
	for (i=0 ; i<mainWinX/2-2 ; i++) {
		waddch(mainWin, ACS_LARROW);
	}
	if (mainWinX%2==1)
		waddch(mainWin, ACS_LARROW);		
		
	waddstr(mainWin, "'1' - Rectangle \t |  'c' - Change Color 	\t| 'w' - Save to file \n");
	waddstr(mainWin, "'2' - Trapeze	  \t |  'n' - Delete Shape 	\t| 'l' - Load from file \n");
	waddstr(mainWin, "'3' - Triangle  \t |  's' - Save Shape	\t| 'd' - Disco Mod \n");
	waddstr(mainWin, "'4' - Circle	  \t |  'a' - Print Saved Shapes\t| 'q' - Quit	\n");
	waddstr(mainWin, "'5' - Rhombus   \t |  '+/-' Resize Shape	\t|		\n");
		
	/*--------------------------------------------------------------------------------------*/

	while ((input = getch()) != 'q') {
		switch (input) {
			case '1':	init(pShape, secWin, midScrY, midScrX, RECTANGLE);
					lastShape=RECTANGLE;
					break;

			case '2':	init(pShape, secWin, midScrY, midScrX, TRAPEZE);
					lastShape=TRAPEZE;
					break;

			case '3':	init(pShape, secWin, midScrY, midScrX, TRIANGLE);
					lastShape=TRIANGLE;
					break;
				
			case '4':	init(pShape, secWin, midScrY, midScrX, CIRCLE);
					lastShape=CIRCLE;
					break;
			
			case '5':	init(pShape, secWin, midScrY, midScrX, RHOMBUS);
					lastShape=RHOMBUS;
					break;
				
			case 'n':	wclear(secWin);
					pShape->shape=0;
					clearList(pHead, temp);
					pHead = NULL;
					break;
				
			case 'c':	changeColor(pShape, secWin);
					break;
				
			case '+':	enlargeShape(pShape, secWin, discoMod);
					break;

			case '-':	shrinkShape(pShape, secWin, discoMod);	
					break;

			case KEY_UP:	moveShape(pShape, secWin, 'u', discoMod);
					break;
			
			case KEY_DOWN:	moveShape(pShape, secWin, 'd', discoMod);
					break;

			case KEY_LEFT:	moveShape(pShape, secWin, 'l', discoMod);
					break;

			case KEY_RIGHT:	moveShape(pShape, secWin, 'r', discoMod);
					break;
			
			case 'd':	discoMod = disco(discoMod);
					break;
			
			case 's':	pHead = saveShape(pHead, pShape->y, pShape->x, pShape->height, pShape->width, 								  pShape->color, pShape->shape);
					break;
					
			case 'a':	drawSavedShapes(pHead, temp, secWin);
					break;
					
			case 'l':	file = fopen(argv[1], "r");
					if (file==NULL) 
						break;
					
					clearList(pHead, temp);
					pHead=NULL;	
		
					while (1) {
						fscanf(file, "%d %d %d %d %d %d", &y, &x, &height, &width, &color, &shape);
						pHead = saveShape(pHead, y, x, height, width, color, shape);
						if (feof(file))
							break;
					}
	
					fclose(file);
					drawSavedShapes(pHead, temp, secWin);
					break;
					
			case 'w':	file = fopen(argv[1], "a");
					fprintf(file, "%d %d %d %d %d %d\n", pShape->y, pShape->x, pShape->height, 										pShape->width, pShape->color, pShape->shape);
					fclose(file);
					break;	
		}
		wrefresh(secWin);
	}
	
	clearList(pHead, temp);
	free(pShape);
	
	delwin(mainWin);
	endwin();

	return 0;
}


		
