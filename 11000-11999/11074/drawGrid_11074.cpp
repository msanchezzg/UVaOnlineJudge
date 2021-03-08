#include <iostream>
using namespace std;

#define newline cout << '\n';


void printCharLine(char c, int length, bool endline=true) {
	for(int i=0; i<length; i++) cout << c;
	if (endline) cout << '\n';
}


/**
 * 		**************				(LOOP 1)							(LOOP 2)
		**************				**************	(1.1)
		**..**..**..**				**************						**..**..**..**
		**..**..**..**				**..**..**..**	(LOOP 2)			(LOOP 3 = '**..')
		**************				**..**..**..**
		**************
		**..**..**..**		=> 									=> 
		**..**..**..**
		**************
		**************
		**..**..**..**
		**..**..**..**
		**************
		**************
 */
void drawGrid(int gridSize, int lineSize, int squareSize) {
	int horLineLength = (lineSize + squareSize) * gridSize + lineSize;

	for(int vertSquare=0; vertSquare<gridSize; vertSquare++) {	// (LOOP 1)
		for(int i=0; i<lineSize; i++) printCharLine('*', horLineLength);	// (1.1)

		for(int horSquare=0; horSquare<squareSize; horSquare++) {	// (LOOP 2)
			for(int horSquareLine=0; horSquareLine<gridSize; horSquareLine++) {		// (LOOP 3)
				printCharLine('*', lineSize, false);
				printCharLine('.', squareSize, false);
			}
			printCharLine('*', lineSize, false);
			newline;
		}
	}

	for(int i=0; i<lineSize; i++) printCharLine('*', horLineLength);
}

int main(){

	int c, gridSize, lineSize, squareSize;
	int horLineLength;
	c = 0;

	while(cin >> squareSize >> lineSize >> gridSize) {
		if (!squareSize && !lineSize && !gridSize) break;

		c++;
		printf("Case %d:\n", c);
		drawGrid(gridSize, lineSize, squareSize);
		newline;
	}

	return 0;
}
