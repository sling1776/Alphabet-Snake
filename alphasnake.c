/*
Title: Random Walk

Summary: Displays a 10x10 grid with a path or 'snake' of capital letters going through it.


Name: Spencer Lingwall
A#: A02226577

Inputs: none
Outputs: none

Compiling Instructions: Visual Studios
************************************
Pseudocode
Begin
	Declare Variables
	Declare Array grid
	Begin initalizing grid loop
		start with first element
		loop begin
			set element to '.'
			move to next element
		end loop when reached last element in row
		proceed to next row
	end initializing grid loop
	declare starting place on grid
	declare starting value
	prepare random to be actually random
	begin snake loop (put letter A in top left corner)
		check top
			check right
				check bottom
					check left
						terrminate snake loop
		pick a random direction to turn
		you picked up!
			check that the space is open
				move snake position up one
				change to next letter value
				put new letter value in the snake's position
		you picked right!
			check that the space is open
				move snake position right one
				change to next letter value
				put new letter value in the snake's position
		you picked down!
			check that the space is open
				move snake position down one
				change to next letter value
				put new letter value in the snake's position
		you picked left!
			check that the space is open
				move snake position left one
				change to next letter value
				put new letter value in the snake's position
		return to beginning of the snake loop
	end snake loop when letter value is Z
	begin print grid with snake in it loop
		begin loop
			print element of grid (letter or '.')
			move to next element
		end loop when you reach the end of the row
		reset to first column
		proceed to next row
	end print grid with snake in it loop when last element of last row is printed
	ask for char before end
	get char
End
*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>


/*      Print the Snake in the grid      */

void print_snake(char grid[][10])
{
	int r, c;

	for (r = 0, c = 0; r <= 9; r++)										//begin print grid with snake in it loop
	{

		for (c = 0; c <= 9;)													//begin loop
		{
			printf("%c  ", grid[r][c]);												//print element of grid (letter or '.')
			c++;																		//move to next element
		}																			//end loop when you reach the end of the row
		c = 0;																	//reset to first column
		printf("\n");																//proceed to next row

	}																			//end print grid with snake in it loop when last element of last row is printed
	printf("press enter to contiune");
	getchar();																	//pause before repeating
	system("cls");																//clears the screen
}

int main()																	//Begin
{
	int direction, row, col;											//Declare Variables
	char grid[10][10], letter;													//Declare Array grid



	/*     initializes the grid so all elements are '.'      */

	for (row = 0; row <= 9;)															//begin initalizing grid loop 
	{
		col = 0;																	//start with first element
		for (; col <= 9;)																//loop begin
		{
			grid[row][col] = '.';														//set element to '.'
			col++;																		//move to next element
		}																			//end loop when reached last element in row
		row++;																		//proceed to next row
	}																			//end initializing grid loop



	/*      prepares for the snake loop       */

	row = 0, col = 0;															//declare starting place on grid
	letter = 'A';																//declare starting value
	srand((unsigned)time(NULL));												//prepare random to be actually random



	/*      Alphabet Snake Loop       */

	for (grid[row][col] = letter; letter < 'Z';)								//begin snake loop (put letter A in top left corner)
	{

		/*     Check to make sure snake isn't surrounded      */

		if (row - 1 < 0 || grid[row - 1][col] != '.')								//check top
			if (col + 1 > 9 || grid[row][col + 1] != '.')								//check right
				if (row + 1 > 9 || grid[row + 1][col] != '.')								//check bottom
					if (col - 1 < 0 || grid[row][col - 1] != '.')								//check left
					{
						printf("You Died!!!\n");
						break;																		//terrminate snake loop
						
					}

						/*     Create the Snake     */
		direction = rand() % 4;														//pick a random direction to turn
		switch (direction)
		{

			/*      Turn Upwards        */
		case 0:																		//you picked up!
			if (row - 1 >= 0 && grid[row - 1][col] == '.')								//check that the space is open
			{
				row--;																		//move snake position up one
				letter++;																	//change to next letter value
				grid[row][col] = letter;													//put new letter value in the snake's position
				print_snake(grid);
			}

			break;																	//return to beginning of snake loop


						/*      Turn Right         */
		case 1:																		//you picked right!
			if (col + 1 <= 9 && grid[row][col + 1] == '.')								//check that the space is open
			{
				col++;																		//move snake position right one
				letter++;																	//change to next letter value
				grid[row][col] = letter;													//put new letter value in the snake's position
				print_snake(grid);
			}

			break;																	//return to beginning of snake loop


						/*      Turn Down (for what?)*/
		case 2:																		//you picked down!
			if (row + 1 <= 9 && grid[row + 1][col] == '.')								//check that the space is open
			{
				row++;																		//move snake position down one
				letter++;																	//change to next letter value
				grid[row][col] = letter;													//put new letter value in the snake's position
				print_snake(grid);
			}

			break;																	//return to beginning of snake loop


						/*       Turn left         */
		case 3:																		//you picked left!
			if (col - 1 >= 0 && grid[row][col - 1] == '.')								//check that the space is open
			{
				col--;																		//move the snake position left one
				letter++;																	//change to next letter value
				grid[row][col] = letter;													//put new letter value in the snake's position
				print_snake(grid);
			}

			break;																	//return to beginning of the snake loop
		}

	}																			//end snake loop when letter value is Z



	/*      Print the Snake in the grid      */

	for (row = 0, col = 0; row <= 9; row++)										//begin print grid with snake in it loop
	{

		for (col = 0; col <= 9;)													//begin loop
		{
			printf("%c  ", grid[row][col]);												//print element of grid (letter or '.')
			col++;																		//move to next element
		}																			//end loop when you reach the end of the row
		col = 0;																	//reset to first column
		printf("\n");																//proceed to next row

	}																			//end print grid with snake in it loop when last element of last row is printed



	/*     prepare for end        */
	printf("Press Enter to End:");												//ask for char before end
	getchar();																	//get char
	return 0;																//End
}



