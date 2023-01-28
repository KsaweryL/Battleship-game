#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

#include <chrono>
#include <thread>


#define SPACE_FOR_CHAR_ARRAYS 5					//space available for character arrays
using namespace std;


int CharShipsOccurence(char CharGrid[2][2][11][11])			//checks the occurence of the ship on the character grids
{

	int ShipsOccurrence[2][5];

	for (int player = 0; player < 2; player++)
	{
		for (int p = 0; p < 5; p++)
		{
			ShipsOccurrence[player][p] = 0;				//initially, all ships occurences' are set to 0
		}
	}


	for (int player = 0; player < 2; player++)
	{


		for (int AllGrids = 0; AllGrids < 1; AllGrids++)
		{

			for (int FirstMatrix = 0; FirstMatrix < 10; FirstMatrix++)
			{

				for (int SecondMatrix = 0; SecondMatrix < 10; SecondMatrix++)			//checks every part of ships' grid for both of the players
				{
					//If some part of the ship exists - add a number to ShipsOcurrence
					if (CharGrid[player][0][FirstMatrix][SecondMatrix] == 49) ShipsOccurrence[player][0]++;		//destroyer - 1
					if (CharGrid[player][0][FirstMatrix][SecondMatrix] == 50) ShipsOccurrence[player][1]++;		//submarine - 2
					if (CharGrid[player][0][FirstMatrix][SecondMatrix] == 51) ShipsOccurrence[player][2]++;		//cruiser - 3
					if (CharGrid[player][0][FirstMatrix][SecondMatrix] == 52) ShipsOccurrence[player][3]++;		//battleship - 4
					if (CharGrid[player][0][FirstMatrix][SecondMatrix] == 53) ShipsOccurrence[player][4]++;		//carrier - 5


				}
			}



		}
	}

	string ShipName[5];					//initialising an array of strings that consist of ship's name - for future optimisation
	ShipName[0] = "Destroyer";
	ShipName[1] = "Submarine";
	ShipName[2] = "Cruiser";
	ShipName[3] = "Battleship";
	ShipName[4] = "Carrier";

	cout << "\n\nSunk ships:";

	for (int player = 0; player < 2; player++)
	{
		for (int i = 0; i < 5; i++)
		{
			//Here the program detects if the occurrence of every ship happened at least once, if not - it means the particular ship no longer exists 
			if (ShipsOccurrence[player][i] == 0)
			{
				cout << "\n - The " << ShipName[i] << " of the player number " << player + 1 << " has been completely destroyed!";
				ShipsOccurrence[player][i] = 0;

			}

		}
	}

	return 0;

}

int IntShipsOccurence(int Grid[2][2][10][10])			//checks occurence of the ship on the integer grids
{

	int ShipsOccurrence[2][5];

	for (int player = 0; player < 2; player++)
	{
		for (int p = 0; p < 5; p++)
		{
			ShipsOccurrence[player][p] = 0;
		}
	}


	for (int player = 0; player < 2; player++)
	{


		for (int AllGrids = 0; AllGrids < 1; AllGrids++)
		{

			for (int FirstMatrix = 0; FirstMatrix < 10; FirstMatrix++)
			{

				for (int SecondMatrix = 0; SecondMatrix < 10; SecondMatrix++)			//checks every part of ships' grid for both of the players
				{
					//If some part of the ship exist - add a number to ShipsOcurrence
					if (Grid[player][0][FirstMatrix][SecondMatrix] == 1) ShipsOccurrence[player][0]++;		//destroyer - 1
					if (Grid[player][0][FirstMatrix][SecondMatrix] == 2) ShipsOccurrence[player][1]++;		//submarine - 2
					if (Grid[player][0][FirstMatrix][SecondMatrix] == 3) ShipsOccurrence[player][2]++;		//cruiser - 3
					if (Grid[player][0][FirstMatrix][SecondMatrix] == 4) ShipsOccurrence[player][3]++;		//battleship - 4
					if (Grid[player][0][FirstMatrix][SecondMatrix] == 5) ShipsOccurrence[player][4]++;		//carrier - 5


				}
			}



		}
	}

	string ShipName[5];				//initialising an array of strings that consist of ship's name - for future optimisation
	ShipName[0] = "Destroyer";
	ShipName[1] = "Submarine";
	ShipName[2] = "Cruiser";
	ShipName[3] = "Battleship";
	ShipName[4] = "Carrier";

	cout << "\n\nSunk ships: \n";

	for (int player = 0; player < 2; player++)
	{
		for (int i = 0; i < 5; i++)
		{
			//Here the program detects if the occurrence of every ship happened at least once, if not - it means the particular ship no longer exists 
			if (ShipsOccurrence[player][i] == 0)
			{
				cout << "\nThe " << ShipName[i] << " of the player number " << player + 1 << " has been completely destroyed!\n";
				ShipsOccurrence[player][i] = 0;

			}

		}
	}

	return 0;

}

void DisplayCurrentGridStatus(int Grid[2][2][10][10])				//Displays current integer grids' status for both of the players
{																	//This function is not used, but is here in case it was necessary
	for (int player = 0; player < 2; player++)
	{
		cout << "\n\nThe Grids of player number " << player + 1;
		for (int AllGrids = 0; AllGrids < 2; AllGrids++)
		{

			if (AllGrids == 0)
			{
				cout << "\n\nThe grid for the ships:";
			}
			else
			{
				cout << "\n\nThe grid for the fired shots:";
			}
			cout << "\n\n";

			cout << "  X 1 2 3 4 5 6 7 8 9 10\n Y";
			for (int FirstMatrix = 0; FirstMatrix < 10; FirstMatrix++)
			{
				cout << "\n";

				if (FirstMatrix == 9)
				{
					cout << FirstMatrix + 1 << " ";
				}
				else
				{
					cout << " " << FirstMatrix + 1 << " ";
				}

				for (int SecondMatrix = 0; SecondMatrix < 10; SecondMatrix++)
				{

					cout << " " << Grid[player][AllGrids][FirstMatrix][SecondMatrix];
				}
			}
		}
	}

	IntShipsOccurence(Grid);

	return;
}

void DisplayCurrentCharGridStatus(char CharGrid[2][2][11][11])			//displays the general status of all grids for both players using numbers and letters
{

	for (int player = 0; player < 2; player++)
	{
		cout << "\n\nThe Grids of player number " << player + 1;
		for (int AllGrids = 0; AllGrids < 2; AllGrids++)
		{

			if (AllGrids == 0)
			{
				cout << "\n\nThe grid for the ships:";
			}
			else
			{
				cout << "\n\nThe grid for the fired shots:";
			}
			cout << "\n\n";

			cout << "  X 1 2 3 4 5 6 7 8 9 10\n Y";
			for (int FirstMatrix = 0; FirstMatrix < 10; FirstMatrix++)
			{
				cout << "\n";

				if (FirstMatrix == 9)
				{
					cout << FirstMatrix + 1 << " ";
				}
				else
				{
					cout << " " << FirstMatrix + 1 << " ";
				}

				for (int SecondMatrix = 0; SecondMatrix < 10; SecondMatrix++)
				{

					cout << " " << CharGrid[player][AllGrids][FirstMatrix][SecondMatrix];
				}
			}
		}
	}

	return;
}


void DisplayCurrentCharGridStatusPlayer(int player, char CharGrid[2][2][11][11])		//displays the general status of all grids for particular player using numbers and letters
{

	cout << "\n\nThe Grids of player number " << player + 1;
	for (int AllGrids = 0; AllGrids < 2; AllGrids++)
	{

		if (AllGrids == 0)
		{
			cout << "\n\nThe grid for the ships:";
		}
		else
		{
			cout << "\n\nThe grid for the fired shots:";
		}
		cout << "\n\n";

		cout << "  X 1 2 3 4 5 6 7 8 9 10\n Y";
		for (int FirstMatrix = 0; FirstMatrix < 10; FirstMatrix++)
		{
			cout << "\n";

			if (FirstMatrix == 9)
			{
				cout << FirstMatrix + 1 << " ";
			}
			else
			{
				cout << " " << FirstMatrix + 1 << " ";
			}

			for (int SecondMatrix = 0; SecondMatrix < 10; SecondMatrix++)
			{

				cout << " " << CharGrid[player][AllGrids][FirstMatrix][SecondMatrix];


			}
		}


	}


	CharShipsOccurence(CharGrid);

	return;
}


void Battle(int StartPlayer, int DamagedPlayer, int Grid[2][2][10][10], char CharGrid[2][2][11][11])			//the function for a battle
{
	int* ShotCoord;				//creating temporary coordinates for the fired shots
	ShotCoord = new int[2];

	char CharShotCoord[2][10];				//creating coordinates for the fired shots - characters
	CharShotCoord[0][9] = NULL;				//Assigning value NULL to the last part of the array
	CharShotCoord[1][9] = NULL;				//Assigning value NULL to the last part of the array

	int Issue[2];							//IF ussue happens, execute the appropriate if
	Issue[0] = 0;
	Issue[1] = 0;


	cout << "\n\nAt which point do you want to shoot?\n";

	cout << "\nPlease determine the number on the X axis: ";
	cin >> CharShotCoord[0];

	//It may happen that a user determines coordinates as letters and not integers by mistake, if that is the case the program below detects it and asks for a proper number
	while ((CharShotCoord[0][0] != 49) && (CharShotCoord[0][0] != 50) && (CharShotCoord[0][0] != 51) && (CharShotCoord[0][0] != 52)
		&& (CharShotCoord[0][0] != 53) && (CharShotCoord[0][0] != 54) && (CharShotCoord[0][0] != 55) && (CharShotCoord[0][0] != 56) && (CharShotCoord[0][0] != 57))				 //continue this loop as long as the number is not from 1 to 9
	{

		cout << "\nThe input must be an integer between 1 and 10, please redefine it!\n";
		cout << "\nPlease determine the number on the X axis: ";
		cin >> CharShotCoord[0];
	}

	if ((CharShotCoord[0][0] == 49) && (CharShotCoord[0][1] == 48))			//If the number quals 10, set the coordinates on X axis to 10
	{
		ShotCoord[0] = 10;
		Issue[0]++;
	}

	cout << "\nPlease determine the number on the Y axis: ";
	cin >> CharShotCoord[1];

	//It may happen that a user determines coordinates as letters and not integers by mistake, if that is the case the program below detects it and asks for a proper number
	while ((CharShotCoord[1][0] != 49) && (CharShotCoord[1][0] != 50) && (CharShotCoord[1][0] != 51) && (CharShotCoord[1][0] != 52)
		&& (CharShotCoord[1][0] != 53) && (CharShotCoord[1][0] != 54) && (CharShotCoord[1][0] != 55) && (CharShotCoord[1][0] != 56) && (CharShotCoord[1][0] != 57))				//continue this loop as long as the number is not from 1 to 9
	{
		cout << "\nThe input must be an integer between 1 and 10, please redefine it!\n";
		cout << "\nPlease determine the number on the Y axis: ";
		cin >> CharShotCoord[1];
	}

	if ((CharShotCoord[1][0] == 49) && (CharShotCoord[1][1] == 48))		//If the number quals 10, set the coordinates on Y axis to 10
	{
		ShotCoord[1] = 10;
		Issue[1]++;
	}

	if (Issue[0] == 0)				//If number 10 was chosen, do not execute this if
	{
		sscanf_s(CharShotCoord[0], "%d", &ShotCoord[0]);
	}
	if (Issue[1] == 0)				//If number 10 was chosen, do not execute this if
	{
		sscanf_s(CharShotCoord[1], "%d", &ShotCoord[1]);
	}


	ShotCoord[0] -= 1;		//Grids for coordinates are 9 x 9 (since the initial coordinate is 0 x 0), while the user interprets them as 10 x 10, 
	ShotCoord[1] -= 1;		//so each number determined by the user should be decreased by 1, in order for the program to read it properly  


	//If  player number 1 starts, than ships of player number 2 take damage
	//Depending on whether it was a hit or miss, the place in the grid of the player number 1 will be filled with 6 or 7

	//1,2,3,4,5 = an operational ship
	//6 , x = damaged ship
	//6 , x = hit
	//7 , - = miss
	if ((Grid[DamagedPlayer][0][ShotCoord[1]][ShotCoord[0]] == 1) || (Grid[DamagedPlayer][0][ShotCoord[1]][ShotCoord[0]] == 2) || (Grid[DamagedPlayer][0][ShotCoord[1]][ShotCoord[0]] == 3)
		|| (Grid[DamagedPlayer][0][ShotCoord[1]][ShotCoord[0]] == 4) || (Grid[DamagedPlayer][0][ShotCoord[1]][ShotCoord[0]] == 5))				//If at the given position an anemy player has any type of ship, a hit is registered
	{
		cout << "\n --------------- Player number " << StartPlayer + 1 << " has hit! --------------- ";
		Grid[DamagedPlayer][0][ShotCoord[1]][ShotCoord[0]] = 9;		//damaged ship indicator is temporarily set to 9
		Grid[StartPlayer][1][ShotCoord[1]][ShotCoord[0]] = 6;		//a hit is registered in the shots' grid of the attacking player ("6")

		CharGrid[StartPlayer][1][ShotCoord[1]][ShotCoord[0]] = 120;			//a hit is registered in the shots' grid of the attacking player ("x")

	}
	else
	{
		if (Grid[DamagedPlayer][0][ShotCoord[1]][ShotCoord[0]] == 6)			//If the attacking player shoots at the position that he/she already shot at (aka 6 or x), nothing changes
		{
			cout << "\n --------------- Player number " << StartPlayer + 1 << " has already hit a ship at this position! --------------- ";
		}
		else                                                                     //otherwise, it was a miss
		{
			cout << "\n --------------- Player number " << StartPlayer + 1 << " has missed! --------------- ";
			Grid[StartPlayer][1][ShotCoord[1]][ShotCoord[0]] = 7;		//miss		//second grid

			CharGrid[StartPlayer][1][ShotCoord[1]][ShotCoord[0]] = 45;			//-
		}
	}

	delete[] ShotCoord;

	return;
}

int war(int StartPlayer, int ContPlayer, int Grid[2][2][10][10], char CharGrid[2][2][11][11], int WinningPlayer[1])			//a war, aka a set of battles that take place as long as one pf the players win
{


	int Counter[2];				//the counter counts all hits that happend during the game, if it reaches 17 (which is the number for all cells that are occupied by ships), then is stops the game
	Counter[0] = 0;
	Counter[1] = 0;
	//player 1 = 0
	//player 2 = 1

	while (1)					//the infinite loop
	{



		cout << "\nThe current player: " << StartPlayer + 1;
		cout << "\nThe next player: " << ContPlayer + 1;

		DisplayCurrentCharGridStatusPlayer(StartPlayer, CharGrid);





		Battle(StartPlayer, ContPlayer, Grid, CharGrid);		// a battle



		cout << "\n";
		for (int FirstMatrix = 0; FirstMatrix < 10; FirstMatrix++)
		{

			for (int SecondMatrix = 0; SecondMatrix < 10; SecondMatrix++)
			{

				if (Grid[ContPlayer][0][FirstMatrix][SecondMatrix] == 9)		//It detects 9 from the grid (a hit), adds 1 to the counter and then sets it to 6 in order not to get confused
				{																//in the next loop
					Counter[ContPlayer]++;

					Grid[ContPlayer][0][FirstMatrix][SecondMatrix] = 6;

					CharGrid[ContPlayer][0][FirstMatrix][SecondMatrix] = 120;		//x
					//6 , x = damaged ship
				}
			}
		}


		DisplayCurrentCharGridStatusPlayer(StartPlayer, CharGrid);


		if (Counter[0] == 17)
		{
			cout << "\n\nPlayer 2 wins!";
			WinningPlayer[0] = 2;
			break;
		}

		if (Counter[1] == 17)
		{
			cout << "\n\nPlayer 1 wins!";
			WinningPlayer[0] = 1;
			break;
		}

		if (StartPlayer == 0)
		{
			StartPlayer = 1;
		}
		else
		{
			StartPlayer = 0;
		}


		if (ContPlayer == 0)
		{
			ContPlayer = 1;
		}
		else
		{
			ContPlayer = 0;
		}


		char* Proceed;
		Proceed = new char[1];

		cout << "\n\nPress any letter + enter to proceed to the next round:\n";		//proceeding to the next round
		cin >> Proceed[0];

		delete[] Proceed;

		system("cls");			//clears the debugger from all of the previous information
	}
	return 0;
}

void PrintingIssueTooLongTooShort(int INTCoordsP[2][2][5][5], int player, int ship, string ShipName[5])		//this function simply prints the informationd and asks the user for new coordinates when summoned
{
	cout << "\nThe " << ShipName[ship] << " of the player number " << player + 1 << " is too long or too short, please redefine the coordinates of this ship:\n";

	cout << "\nThe new first number of the initial coordinates equals: ";
	cin >> INTCoordsP[player][0][ship][0];

	cout << "\nThe new second number of the initial coordinates equals: ";
	cin >> INTCoordsP[player][0][ship][1];

	cout << "\nThe new first number of the terminating coordinates equals: ";
	cin >> INTCoordsP[player][1][ship][0];

	cout << "\nThe new second number of the terminating coordinates equals: ";
	cin >> INTCoordsP[player][1][ship][1];

	return;
}


void Assessment(int INTCoordsP[2][2][5][5], string ShipName[5])				//this function asseses the coordinates if those were properly determined
{
	int IfIssueCheckAgainAll;
	IfIssueCheckAgainAll = 0;

	for (int player = 0; player < 2; player++)
	{

		for (int ship = 0; ship < 5; ship++)
		{
			if (IfIssueCheckAgainAll != 0)
			{
				ship--;								//if the problem occurred regarding coordinates of one of the ships, 
													//after redefining them the program checks this ship again to decide if everything is ok with it
				IfIssueCheckAgainAll = 0;
			}

			//Checking, if the initial (beginning) and terminating coordinates of the ship are read from left to right or top to bottom

			//Checking collumns
			if (INTCoordsP[player][0][ship][0] > INTCoordsP[player][1][ship][0])		//If the initial column is greater than the terminating one, initiate this if 
			{
				int* PreviousCoords;
				PreviousCoords = new int[1];

				PreviousCoords[0] = INTCoordsP[player][0][ship][0];

				INTCoordsP[player][0][ship][0] = INTCoordsP[player][1][ship][0];

				INTCoordsP[player][1][ship][0] = PreviousCoords[0];

				IfIssueCheckAgainAll++;

				delete[] PreviousCoords;

				cout << "\nSince the initiatory coordinates of the " << ShipName[ship] << " of player number " << player + 1 << " are greater than the terminating ones, their order has been automatically reversed and their new values are now as follows: \n";

				std::chrono::milliseconds timespan(10000);

				std::this_thread::sleep_for(timespan);

				cout << "\nThe new first number of the initial coordinates equals: ";
				cout << INTCoordsP[player][0][ship][0];

				cout << "\nThe new second number of the initial coordinates equals: ";
				cout << INTCoordsP[player][0][ship][1];

				cout << "\nThe new first number of the terminating coordinates equals: ";
				cout << INTCoordsP[player][1][ship][0];

				cout << "\nThe new second number of the terminating coordinates equals: ";
				cout << INTCoordsP[player][1][ship][1];

				std::chrono::milliseconds timespan2(15000);

				std::this_thread::sleep_for(timespan2);

			}

			//Checking rows
			if (INTCoordsP[player][0][ship][1] > INTCoordsP[player][1][ship][1])		//If the initial row is greater than the terminating one, initiate this if 
			{
				int* PreviousCoords;
				PreviousCoords = new int[1];

				PreviousCoords[0] = INTCoordsP[player][0][ship][1];

				INTCoordsP[player][0][ship][1] = INTCoordsP[player][1][ship][1];

				INTCoordsP[player][1][ship][1] = PreviousCoords[0];

				IfIssueCheckAgainAll++;

				delete[] PreviousCoords;

				cout << "\nSince the initiatory coordinates of the " << ShipName[ship] << " of player number " << player + 1 << " are greater than the terminating ones, their order has been automatically reversed and their new values are now as follows: \n";

				std::chrono::milliseconds timespan3(10000);

				std::this_thread::sleep_for(timespan3);

				cout << "\nThe new first number of the initial coordinates equals: ";
				cout << INTCoordsP[player][0][ship][0];

				cout << "\nThe new second number of the initial coordinates equals: ";
				cout << INTCoordsP[player][0][ship][1];

				cout << "\nThe new first number of the terminating coordinates equals: ";
				cout << INTCoordsP[player][1][ship][0];

				cout << "\nThe new second number of the terminating coordinates equals: ";
				cout << INTCoordsP[player][1][ship][1];

				std::chrono::milliseconds timespan4(15000);

				std::this_thread::sleep_for(timespan4);

			}

			//Checking if Coordinates of the beginning and the ending are the same

			if ((INTCoordsP[player][0][ship][0] == INTCoordsP[player][1][ship][0]) && (INTCoordsP[player][0][ship][1] == INTCoordsP[player][1][ship][1]))
			{
				IfIssueCheckAgainAll++;

				cout << "\nThe beginning and terminating coordinates of the " << ShipName[ship] << " of the player number " << player + 1 << " are both the same, please redefine both sets of coordinates:\n";

				cout << "\nThe new first number of the initial coordinates equals: ";
				cin >> INTCoordsP[player][0][ship][0];

				cout << "\nThe new second number of the initial coordinates equals: ";
				cin >> INTCoordsP[player][0][ship][1];

				cout << "\nThe new first number of the terminating coordinates equals: ";
				cin >> INTCoordsP[player][1][ship][0];

				cout << "\nThe new second number of the terminating coordinates equals: ";
				cin >> INTCoordsP[player][1][ship][1];
			}


			//Checking if there are any ships that are positioned diagonally
			if (INTCoordsP[player][0][ship][0] != INTCoordsP[player][1][ship][0])		//If neither the collumns nor the rows from beginning and terminating postions equal each other, 
			{																			//then the the ship is positioned diagonally
				if (INTCoordsP[player][0][ship][1] != INTCoordsP[player][1][ship][1])
				{
					IfIssueCheckAgainAll++;
					while ((INTCoordsP[player][0][ship][1] != INTCoordsP[player][1][ship][1]) && (INTCoordsP[player][0][ship][0] != INTCoordsP[player][1][ship][0]))
					{
						cout << "\nPlayer number " << player + 1 << " has put his/her " << ShipName[ship] << " diagonally, please redefine the coordinates of this ship:\n";

						cout << "\nThe new first number of the initial coordinates equals: ";
						cin >> INTCoordsP[player][0][ship][0];

						cout << "\nThe new second number of the initial coordinates equals: ";
						cin >> INTCoordsP[player][0][ship][1];

						cout << "\nThe new first number of the terminating coordinates equals: ";
						cin >> INTCoordsP[player][1][ship][0];

						cout << "\nThe new second number of the terminating coordinates equals: ";
						cin >> INTCoordsP[player][1][ship][1];
					}
				}

			}

			//Checking if the ships take the apprippriate quantity of space

			if (ship == 0) //Level 2 ships: Destroyer		(take 2 cells)
			{
				while (((abs(INTCoordsP[player][0][ship][0] - INTCoordsP[player][1][ship][0]) != 1) && (abs(INTCoordsP[player][0][ship][0] - INTCoordsP[player][1][ship][0]) != 0)) ||
					((abs(INTCoordsP[player][1][ship][1] - INTCoordsP[player][0][ship][1]) != 1) && ((abs(INTCoordsP[player][1][ship][1] - INTCoordsP[player][0][ship][1])) != 0)))
				{
					IfIssueCheckAgainAll++;
					PrintingIssueTooLongTooShort(INTCoordsP, player, ship, ShipName);
				}
			}

			if (ship == 1 || ship == 2)  //Level 3 ships: submarine and cruiser
			{

				while (((abs(INTCoordsP[player][0][ship][0] - INTCoordsP[player][1][ship][0]) != 2) && (abs(INTCoordsP[player][0][ship][0] - INTCoordsP[player][1][ship][0]) != 0)) ||
					((abs(INTCoordsP[player][1][ship][1] - INTCoordsP[player][0][ship][1]) != 2) && ((abs(INTCoordsP[player][1][ship][1] - INTCoordsP[player][0][ship][1])) != 0)))
				{
					//cin >> a[2];
					IfIssueCheckAgainAll++;
					PrintingIssueTooLongTooShort(INTCoordsP, player, ship, ShipName);
				}

			}

			if (ship == 3)  //Level 4 ships: battleship
			{
				while (((abs(INTCoordsP[player][0][ship][0] - INTCoordsP[player][1][ship][0]) != 3) && (abs(INTCoordsP[player][0][ship][0] - INTCoordsP[player][1][ship][0]) != 0)) ||
					((abs(INTCoordsP[player][1][ship][1] - INTCoordsP[player][0][ship][1]) != 3) && ((abs(INTCoordsP[player][1][ship][1] - INTCoordsP[player][0][ship][1])) != 0)))
				{
					//cin >> a[2];
					IfIssueCheckAgainAll++;
					PrintingIssueTooLongTooShort(INTCoordsP, player, ship, ShipName);
				}
			}

			if (ship == 4)  //Level 5 ships: cruiser
			{
				while (((abs(INTCoordsP[player][0][ship][0] - INTCoordsP[player][1][ship][0]) != 4) && (abs(INTCoordsP[player][0][ship][0] - INTCoordsP[player][1][ship][0]) != 0)) ||
					((abs(INTCoordsP[player][1][ship][1] - INTCoordsP[player][0][ship][1]) != 4) && ((abs(INTCoordsP[player][1][ship][1] - INTCoordsP[player][0][ship][1])) != 0)))
				{
					//cin >> a[2];
					IfIssueCheckAgainAll++;
					PrintingIssueTooLongTooShort(INTCoordsP, player, ship, ShipName);
				}
			}

			//checking if any of the coordinates are beyond the grip

			if ((INTCoordsP[player][0][ship][0] < 0) || (INTCoordsP[player][0][ship][0] > 10))
			{
				IfIssueCheckAgainAll++;
				cout << "\nPlayer number " << player + 1 << " has set the first number of the initial coordinates of his/her " << ShipName[ship] << " as the collumn, that is beyond the grid, please redefine this number:\n";
				cin >> INTCoordsP[player][0][ship][0];
			}

			if ((INTCoordsP[player][0][ship][1] < 0) || (INTCoordsP[player][0][ship][1] > 10))
			{
				IfIssueCheckAgainAll++;
				cout << "\nPlayer number " << player + 1 << " has set the second number of the initial coordinates of his/her " << ShipName[ship] << " as the row, that is beyond the grid, please redefine this number:\n";
				cin >> INTCoordsP[player][0][ship][1];
			}

			if ((INTCoordsP[player][1][ship][0] < 0) || (INTCoordsP[player][1][ship][0] > 10))
			{
				IfIssueCheckAgainAll++;
				cout << "\nPlayer number " << player + 1 << " has set the first number of the terminating coordinates of his/her " << ShipName[ship] << " as the collumn, that is beyond the grid, please redefine this number:\n";
				cin >> INTCoordsP[player][1][ship][0];
			}

			if ((INTCoordsP[player][1][ship][1] < 0) || (INTCoordsP[player][1][ship][1] > 10))
			{
				IfIssueCheckAgainAll++;
				cout << "\nPlayer number " << player + 1 << " has set the second number of the terminating coordinates of his/her " << ShipName[ship] << " as the row, that is beyond the grid, please redefine this number:\n";
				cin >> INTCoordsP[player][1][ship][1];
			}



		}

	}


}


int PuttingShipsOnGrid(int INTCoordsP[2][2][5][5], int Grid[2][2][10][10], char CharGrid[2][2][11][11], string ShipName[5])		//Puts ships on the grids + detects any overlaps
{
	int ErrorDetector = 0;

	for (int player = 0; player < 2; player++)
	{
		for (int ship = 0; ship < 5; ship++)
		{


			//checking if the overlap happens - initial and terminating coordinates

			//initial
			if ((Grid[player][0][INTCoordsP[player][0][ship][1] - 1][INTCoordsP[player][0][ship][0] - 1] == 1) || (Grid[player][0][INTCoordsP[player][0][ship][1] - 1][INTCoordsP[player][0][ship][0] - 1] == 2) || (Grid[player][0][INTCoordsP[player][0][ship][1] - 1][INTCoordsP[player][0][ship][0] - 1] == 3) || (Grid[player][0][INTCoordsP[player][0][ship][1] - 1][INTCoordsP[player][0][ship][0] - 1] == 4) || (Grid[player][0][INTCoordsP[player][0][ship][1] - 1][INTCoordsP[player][0][ship][0] - 1] == 5))			//overlap detector - if one of the ships is positioned at coordinates that are supposed to equal 0, detector is triggered

			{


				Grid[player][0][INTCoordsP[player][1][ship][1] - 1][INTCoordsP[player][1][ship][0] - 1] = 0;		//sets initial coordinates to 0 - integers grid

				CharGrid[player][0][INTCoordsP[player][1][ship][1] - 1][INTCoordsP[player][1][ship][0] - 1] = 48;   //sets initial coordinates to 0 - characters grid

				//DisplayCurrentGridStatus(Grid);			//checking


				cout << "\n\nThe " << ShipName[ship] << " of the player number " << player + 1 << " has overlapped with another ship!\nPlease, redefine the coordinates of the " << ShipName[ship] << "\n";			//asks the user for new coordinates

				cout << "\nThe new first number of the initial coordinates equals: ";
				cin >> INTCoordsP[player][0][ship][0];

				cout << "\nThe new second number of the initial coordinates equals: ";
				cin >> INTCoordsP[player][0][ship][1];

				cout << "\nThe new first number of the terminating coordinates equals: ";
				cin >> INTCoordsP[player][1][ship][0];

				cout << "\nThe new second number of the terminating coordinates equals: ";
				cin >> INTCoordsP[player][1][ship][1];

				Assessment(INTCoordsP, ShipName);			//asseses those coordinates once again



				ErrorDetector++;					//if an error with coordonates is detected, check the ship for which they are related to once again

			}
			else
			{
				if (ErrorDetector == 0)				//if problems have occured, do not print initial coordinates of the ship
				{

					if (ship == 0)		//destroyer
					{
						Grid[player][0][INTCoordsP[player][0][ship][1] - 1][INTCoordsP[player][0][ship][0] - 1] = 1;

						CharGrid[player][0][INTCoordsP[player][0][ship][1] - 1][INTCoordsP[player][0][ship][0] - 1] = 49;
					}

					if (ship == 1)		//submarine
					{
						Grid[player][0][INTCoordsP[player][0][ship][1] - 1][INTCoordsP[player][0][ship][0] - 1] = 2;

						CharGrid[player][0][INTCoordsP[player][0][ship][1] - 1][INTCoordsP[player][0][ship][0] - 1] = 50;
					}

					if (ship == 2)		//cruiser
					{
						Grid[player][0][INTCoordsP[player][0][ship][1] - 1][INTCoordsP[player][0][ship][0] - 1] = 3;

						CharGrid[player][0][INTCoordsP[player][0][ship][1] - 1][INTCoordsP[player][0][ship][0] - 1] = 51;

					}

					if (ship == 3)		//battleship
					{
						Grid[player][0][INTCoordsP[player][0][ship][1] - 1][INTCoordsP[player][0][ship][0] - 1] = 4;

						CharGrid[player][0][INTCoordsP[player][0][ship][1] - 1][INTCoordsP[player][0][ship][0] - 1] = 52;
					}

					if (ship == 4)		//carrier
					{
						Grid[player][0][INTCoordsP[player][0][ship][1] - 1][INTCoordsP[player][0][ship][0] - 1] = 5;

						CharGrid[player][0][INTCoordsP[player][0][ship][1] - 1][INTCoordsP[player][0][ship][0] - 1] = 53;
					}


				}

			}


			//terminating
			if ((Grid[player][0][INTCoordsP[player][1][ship][1] - 1][INTCoordsP[player][1][ship][0] - 1] == 1) || (Grid[player][0][INTCoordsP[player][1][ship][1] - 1][INTCoordsP[player][1][ship][0] - 1] == 2) || (Grid[player][0][INTCoordsP[player][1][ship][1] - 1][INTCoordsP[player][1][ship][0] - 1] == 3) || (Grid[player][0][INTCoordsP[player][1][ship][1] - 1][INTCoordsP[player][1][ship][0] - 1] == 4) || (Grid[player][0][INTCoordsP[player][1][ship][1] - 1][INTCoordsP[player][1][ship][0] - 1] == 5))	   //overlap detector - the same procedure as for the initial coordinates, but now for the terminating ones
			{
				Grid[player][0][INTCoordsP[player][0][ship][1] - 1][INTCoordsP[player][0][ship][0] - 1] = 0;

				CharGrid[player][0][INTCoordsP[player][0][ship][1] - 1][INTCoordsP[player][0][ship][0] - 1] = 48;



				//DisplayCurrentGridStatus(Grid);			//checking


				cout << "\n\nThe " << ShipName[ship] << " of the player number " << player + 1 << " has overlapped with another ship!\nPlease, redefine the coordinates of the " << ShipName[ship] << "\n";

				cout << "\nThe new first number of the initial coordinates equals: ";
				cin >> INTCoordsP[player][0][ship][0];

				cout << "\nThe new second number of the initial coordinates equals: ";
				cin >> INTCoordsP[player][0][ship][1];

				cout << "\nThe new first number of the terminating coordinates equals: ";
				cin >> INTCoordsP[player][1][ship][0];

				cout << "\nThe new second number of the terminating coordinates equals: ";
				cin >> INTCoordsP[player][1][ship][1];

				Assessment(INTCoordsP, ShipName);


				ErrorDetector++;

			}
			else
			{
				if (ErrorDetector == 0)					//if problems have occured, do not print terminating oordinates
				{
					if (ship == 0)		//destroyer
					{
						Grid[player][0][INTCoordsP[player][1][ship][1] - 1][INTCoordsP[player][1][ship][0] - 1] = 1;

						CharGrid[player][0][INTCoordsP[player][1][ship][1] - 1][INTCoordsP[player][1][ship][0] - 1] = 49;
					}

					if (ship == 1)		//submarine
					{
						Grid[player][0][INTCoordsP[player][1][ship][1] - 1][INTCoordsP[player][1][ship][0] - 1] = 2;

						CharGrid[player][0][INTCoordsP[player][1][ship][1] - 1][INTCoordsP[player][1][ship][0] - 1] = 50;
					}

					if (ship == 2)		//cruiser
					{
						Grid[player][0][INTCoordsP[player][1][ship][1] - 1][INTCoordsP[player][1][ship][0] - 1] = 3;

						CharGrid[player][0][INTCoordsP[player][1][ship][1] - 1][INTCoordsP[player][1][ship][0] - 1] = 51;
					}

					if (ship == 3)		//battleship
					{
						Grid[player][0][INTCoordsP[player][1][ship][1] - 1][INTCoordsP[player][1][ship][0] - 1] = 4;

						CharGrid[player][0][INTCoordsP[player][1][ship][1] - 1][INTCoordsP[player][1][ship][0] - 1] = 52;
					}

					if (ship == 4)		//carrier
					{
						Grid[player][0][INTCoordsP[player][1][ship][1] - 1][INTCoordsP[player][1][ship][0] - 1] = 5;

						CharGrid[player][0][INTCoordsP[player][1][ship][1] - 1][INTCoordsP[player][1][ship][0] - 1] = 53;
					}
				}

			}



			if (ErrorDetector == 0)		//if problems have occured, do not print any additional ones
			{
				if (INTCoordsP[player][0][ship][0] == INTCoordsP[player][1][ship][0])				//if the first coordinate of the beginning equals the first coordinate of the ending (I.e. collumns are the same, so we need to operate on rows)
				{																		//then fill the blank spaces beewten those coordinates with 1
					for (int i = INTCoordsP[player][0][ship][1]; i < INTCoordsP[player][1][ship][1] - 1; i++)
					{

						if ((Grid[player][0][i][INTCoordsP[player][1][ship][0] - 1] == 1) || (Grid[player][0][i][INTCoordsP[player][1][ship][0] - 1] == 2) || (Grid[player][0][i][INTCoordsP[player][1][ship][0] - 1] == 3) || (Grid[player][0][i][INTCoordsP[player][1][ship][0] - 1] == 4) || (Grid[player][0][i][INTCoordsP[player][1][ship][0] - 1] == 5))

						{

							//In case we needed to terminate the remaining ones

							for (int j = i - 1; j >= INTCoordsP[player][0][ship][1]; j--)
							{
								Grid[player][0][j][INTCoordsP[player][1][ship][0] - 1] = 0;
							}

							Grid[player][0][INTCoordsP[player][0][ship][1] - 1][INTCoordsP[player][0][ship][0] - 1] = 0;

							Grid[player][0][INTCoordsP[player][1][ship][1] - 1][INTCoordsP[player][1][ship][0] - 1] = 0;

							CharGrid[player][0][INTCoordsP[player][0][ship][1] - 1][INTCoordsP[player][0][ship][0] - 1] = 48;

							CharGrid[player][0][INTCoordsP[player][1][ship][1] - 1][INTCoordsP[player][1][ship][0] - 1] = 48;

							//DisplayCurrentGridStatus(Grid);			//checking

							cout << "\n\nThe " << ShipName[ship] << " of the player number " << player + 1 << " has overlapped with another ship!\nPlease, redefine the coordinates of the " << ShipName[ship] << "\n";

							cout << "\nThe new first number of the initial coordinates equals: ";
							cin >> INTCoordsP[player][0][ship][0];

							cout << "\nThe new second number of the initial coordinates equals: ";
							cin >> INTCoordsP[player][0][ship][1];

							cout << "\nThe new first number of the terminating coordinates equals: ";
							cin >> INTCoordsP[player][1][ship][0];

							cout << "\nThe new second number of the terminating coordinates equals: ";
							cin >> INTCoordsP[player][1][ship][1];



							Assessment(INTCoordsP, ShipName);

							ErrorDetector++;

							break;


						}
						else
						{
							if (ship == 0)		//destroyer
							{
								Grid[player][0][i][INTCoordsP[player][1][ship][0] - 1] = 1;

								CharGrid[player][0][i][INTCoordsP[player][1][ship][0] - 1] = 49;
							}

							if (ship == 1)		//submarine
							{
								Grid[player][0][i][INTCoordsP[player][1][ship][0] - 1] = 2;

								CharGrid[player][0][i][INTCoordsP[player][1][ship][0] - 1] = 50;
							}

							if (ship == 2)		//cruiser
							{
								Grid[player][0][i][INTCoordsP[player][1][ship][0] - 1] = 3;

								CharGrid[player][0][i][INTCoordsP[player][1][ship][0] - 1] = 51;
							}

							if (ship == 3)		//battleship
							{
								Grid[player][0][i][INTCoordsP[player][1][ship][0] - 1] = 4;

								CharGrid[player][0][i][INTCoordsP[player][1][ship][0] - 1] = 52;
							}

							if (ship == 4)		//carrier
							{
								Grid[player][0][i][INTCoordsP[player][1][ship][0] - 1] = 5;

								CharGrid[player][0][i][INTCoordsP[player][1][ship][0] - 1] = 53;
							}

							//Grid[player][0][i][INTCoordsP[player][1][ship][0] - 1] = 1;		//testing

							//CharGrid[player][0][i][INTCoordsP[player][1][ship][0] - 1] = 49;		//testing
						}
					}
				}


				if (INTCoordsP[player][0][ship][1] == INTCoordsP[player][1][ship][1])				//if the second coordinate of the beginning equals the second coordinate of the ending, 
				{																					//fill the blank spaces (collumns) beewten those coordinates with the apprioprate number (I.e. rows are the same, so we need to operate on collumns)
					for (int i = INTCoordsP[player][0][ship][0]; i < INTCoordsP[player][1][ship][0] - 1; i++)
					{

						if ((Grid[player][0][INTCoordsP[player][1][ship][1] - 1][i] == 1) || (Grid[player][0][INTCoordsP[player][1][ship][1] - 1][i] == 2) || (Grid[player][0][INTCoordsP[player][1][ship][1] - 1][i] == 3) || (Grid[player][0][INTCoordsP[player][1][ship][1] - 1][i] == 4) || (Grid[player][0][INTCoordsP[player][1][ship][1] - 1][i] == 5))

						{

							//In case we needed to terminate the remaining digits

							for (int j = i - 1; j >= INTCoordsP[player][0][ship][0]; j--)
							{
								Grid[player][0][INTCoordsP[player][1][ship][1] - 1][j] = 0;
							}

							Grid[player][0][INTCoordsP[player][0][ship][1] - 1][INTCoordsP[player][0][ship][0] - 1] = 0;

							Grid[player][0][INTCoordsP[player][1][ship][1] - 1][INTCoordsP[player][1][ship][0] - 1] = 0;

							CharGrid[player][0][INTCoordsP[player][0][ship][1] - 1][INTCoordsP[player][0][ship][0] - 1] = 48;

							CharGrid[player][0][INTCoordsP[player][1][ship][1] - 1][INTCoordsP[player][1][ship][0] - 1] = 48;


							//DisplayCurrentGridStatus(Grid);



							cout << "\n\nThe " << ShipName[ship] << " of the player number " << player + 1 << " has overlapped with another ship!\nPlease, redefine the coordinates of the " << ShipName[ship] << "\n";

							cout << "\nThe new first number of the beginning set of coordinates equals: ";
							cin >> INTCoordsP[player][0][ship][0];

							cout << "\nThe new second number of the beginning set of coordinates equals: ";
							cin >> INTCoordsP[player][0][ship][1];

							cout << "\nThe new first number of the terminating set of coordinates equals: ";
							cin >> INTCoordsP[player][1][ship][0];

							cout << "\nThe new second number of the terminating set of coordinates equals: ";
							cin >> INTCoordsP[player][1][ship][1];

							Assessment(INTCoordsP, ShipName);



							ErrorDetector++;


							//DisplayCurrentGridStatus(Grid);

							break;


						}

						if (ship == 0)		//destroyer
						{
							Grid[player][0][INTCoordsP[player][1][ship][1] - 1][i] = 1;

							CharGrid[player][0][INTCoordsP[player][1][ship][1] - 1][i] = 49;
						}

						if (ship == 1)		//submarine
						{
							Grid[player][0][INTCoordsP[player][1][ship][1] - 1][i] = 2;

							CharGrid[player][0][INTCoordsP[player][1][ship][1] - 1][i] = 50;
						}

						if (ship == 2)		//cruiser
						{
							Grid[player][0][INTCoordsP[player][1][ship][1] - 1][i] = 3;

							CharGrid[player][0][INTCoordsP[player][1][ship][1] - 1][i] = 51;
						}

						if (ship == 3)		//battleship
						{
							Grid[player][0][INTCoordsP[player][1][ship][1] - 1][i] = 4;

							CharGrid[player][0][INTCoordsP[player][1][ship][1] - 1][i] = 52;
						}

						if (ship == 4)		//carrier
						{
							Grid[player][0][INTCoordsP[player][1][ship][1] - 1][i] = 5;

							CharGrid[player][0][INTCoordsP[player][1][ship][1] - 1][i] = 53;
						}


					}
				}
			}
			if (ErrorDetector != 0)
			{
				ship--;
				ErrorDetector = 0;
			}
		}
	}

	return 0;
}

int GeneralInfo()		//A function that displays generals rules and information on how to play the game
{
	cout << "						----------------------------------";
	cout << "\n						| Welcome to the battleship game!| ";
	cout << "\n						----------------------------------";

	chrono::milliseconds timespan5(4000);
	chrono::milliseconds timespan6(3000);

	this_thread::sleep_for(timespan5);

	cout << "\n\n							 How to play: \n";
	this_thread::sleep_for(timespan6);
	cout << "\n\n1) Each player's objective is to destroy all of enemy player's ships";
	this_thread::sleep_for(timespan5);
	this_thread::sleep_for(timespan6);

	cout << "\n\n2) Each player has at his/her disposal 5 ships in total: \n";
	this_thread::sleep_for(timespan6);
	cout << "\n - The Destroyer (number 1 on the grid)\n";
	this_thread::sleep_for(timespan6);
	cout << "\n - The Submarine (number 2 on the grid)\n";
	this_thread::sleep_for(timespan6);
	cout << "\n - The Cruiser (number 3 on the grid)\n";
	this_thread::sleep_for(timespan6);
	cout << "\n - The Battleship (number 4 on the grid)\n";
	this_thread::sleep_for(timespan6);
	cout << "\n - The Carrier (number 5 on the grid)\n";
	this_thread::sleep_for(timespan6);

	cout << "\n\n3) The initial and terminating coordinates of each ship are written in the already created file: \n";
	this_thread::sleep_for(timespan5);
	cout << "\nIf one of the players decides to change these coordinates: \n";
	this_thread::sleep_for(timespan5);
	cout << "\n - Either change them directly in the code of this program: \n";
	this_thread::sleep_for(timespan6);
	cout << "\n - or comment (or delete) part of the code that creates it and initialise a new file, which should be positioned in a proper location on the drive: \n";
	this_thread::sleep_for(timespan5);
	this_thread::sleep_for(timespan5);

	cout << "\nThen the content of such file should look like this:\n";
	this_thread::sleep_for(timespan5);

	cout << "\nDestroyer: 2;2-2;3! Submarine: 5;3-7;3! Cruiser: 5;5-5;7! Battleship: 10;5-10;8! Carrier: 4;10-8;10!\n";
	this_thread::sleep_for(timespan5);
	cout << "\nWhere coordinates of each ship before the dash sign are the initial ones, and after it are terminating ones\n";
	this_thread::sleep_for(timespan5);
	this_thread::sleep_for(timespan5);
	cout << "\nFollowing this procedure, only the numbers can be altered in this formula (from 1 to 10)!\n";
	this_thread::sleep_for(timespan5);

	cout << "\n4) Once it is decided which player starts, the initial player writes the coordinates at which he/she would like to shoot\n";
	this_thread::sleep_for(timespan5);
	this_thread::sleep_for(timespan5);
	this_thread::sleep_for(timespan5);
	cout << "\n5) If at the mentioned position enemy player's ship is placed, then the particular part of the vessel is destroyed (aka hit)\n";
	this_thread::sleep_for(timespan5);
	this_thread::sleep_for(timespan5);
	cout << "\n6) The attacking player would then have a character X positioned on his/her grid for the shots, and the second player would have the same sign assigned to the ships' grid\n";
	this_thread::sleep_for(timespan5);
	this_thread::sleep_for(timespan5);
	this_thread::sleep_for(timespan6);
	cout << "\n7) In the case of an unsuccessful shot, the attacking player would have a character '-' put on his/her shots' grid\n";
	this_thread::sleep_for(timespan5);
	this_thread::sleep_for(timespan5);
	cout << "\n8) When one of the players manages to destroy the whole second player's ship, then it is announced to both of the players\n";
	this_thread::sleep_for(timespan5);
	this_thread::sleep_for(timespan5);
	cout << "\n9) Then the whole procedure is repeated, but the players are swapped\n";
	this_thread::sleep_for(timespan5);
	cout << "\nThe game ends once one player destroys all of enemy player's vessels\n";
	this_thread::sleep_for(timespan5);

	this_thread::sleep_for(timespan5);

	cout << "\n\n							 General Rules: \n";
	this_thread::sleep_for(timespan5);


	cout << "\n1) Ships cannot be positioned diagonally\n";
	this_thread::sleep_for(timespan5);
	cout << "\n2) Ships cannot be too long or too short, which means:\n";
	this_thread::sleep_for(timespan5);
	cout << "\n - The Destroyer should take 2 cells\n";
	this_thread::sleep_for(timespan5);
	cout << "\n - The Submarine should take 3 cells\n";
	this_thread::sleep_for(timespan5);
	cout << "\n - The Cruiser should take 3 cells\n";
	this_thread::sleep_for(timespan5);
	cout << "\n - The Battleship should take 4 cells\n";
	this_thread::sleep_for(timespan5);
	cout << "\n - The Carrier should take 5 cells\n";
	this_thread::sleep_for(timespan5);
	cout << "\n3) Ships cannot be placed beyond the 10 x 10 grid\n";
	this_thread::sleep_for(timespan5);
	cout << "\n4) Ships cannot overlap with one another\n";
	this_thread::sleep_for(timespan5);
	cout << "\n5) Ships' beginning coordinates should be defined above or on the left of their terminating coordinates\n";
	this_thread::sleep_for(timespan5);
	this_thread::sleep_for(timespan6);
	cout << "\nI.e. , ships must be placed from top to bottom or from left to right\n";
	this_thread::sleep_for(timespan5);



	cout << "\n			Thank you for your attention and I wish you an entertaining game!";

	this_thread::sleep_for(timespan5);

	return 0;
}

int File(string CoordsP[2])		//The function that generates and reads from files containing the coordinates of ships
{
	//Initiating a file for the first player's grid
	fstream Player1;

	
	Player1.open("First Player's grid.txt", ios::out);  // open a file to perform write operation using file object

	if (Player1.is_open())					//checking whether the file is open
	{
		Player1 << "Destroyer: 2;2-2;3! Submarine: 5;3-7;3! Cruiser: 5;5-5;7! Battleship: 10;5-10;8! Carrier: 4;10-8;10!";   //inserting text
		Player1.close();					 //close the file object
	}


	Player1.open("First Player's grid.txt", ios::in);

	if (Player1.is_open())					//checking whether the file is open
	{
		getline(Player1, CoordsP[0]);		//read data from file object and put it into string.

	}
	Player1.close();					//close the file object.

//Initiating a file for the second player's grid

	fstream Player2;


	Player2.open("Second Player's grid.txt", ios::out);

	if (Player2.is_open())
	{
		Player2 << "Destroyer: 3;3-3;4! Submarine: 8;4-10;4! Cruiser: 8;1-8;3! Battleship: 4;5-4;8! Carrier: 1;9-5;9!";
		Player2.close();
	}


	Player2.open("Second Player's grid.txt", ios::in);

	if (Player2.is_open())
	{
		getline(Player2, CoordsP[1]);

	}
	Player2.close();

	return 0;
}

int ReadingCoords(int INTCoordsP[2][2][5][5], char CharCoordsP[2][2][5][SPACE_FOR_CHAR_ARRAYS], string CoordsP[2])		//A function that reads the coordinates of each ship from the file
{

	//INTCoordsP[2][2][5][5];		//player, initial or terminating coordinates, type of the ship, particular number 
	//(why 5 and not 2? Since each number is read separately and in case the code didn't work for the program not to crash)

	//Destroyer = 0
	//Submarine = 1
	//Cruiser = 2
	//Battleship = 3
	//Carrier = 4
	//Beginning = 0
	//End = 1

	//This is how coordinates should be read by players:
	//(x,y)   
	//x = collumn
	//y = row

	//This is how coordinates are read by grids:
	//(x,y)   
	//x = row
	//y = collumn

	for (int player = 0; player < 2; player++)		//First loop indicates the player
	{

		int Place, EndOfCoords;
		Place = 0;
		EndOfCoords = 0;

		int i1;
		i1 = 0;
		for (int ship = 0; ship < 5; ship++)		//Second loop indicates the ship
		{
			for (i1 = Place; i1 < EndOfCoords + 11; i1++)		//This loop is striclty tied with reading characters from each ship
			{

				if (CoordsP[player][i1] == 58)			//if a character equals ":", then the proper number starts
				{
					i1 = i1 + 2;						//omitting characters ":" and "space"


					for (Place = i1; Place < i1 + 6; Place++)		//Reading the number and putting it into the apprioprate matrix	
					{
						if (CoordsP[player][Place] == 33) break;		//If the character equals "!", then the cooridnates of a specific ship have been already read

						for (int j = 0; j < 6; j++)						//Reading the number and putting it into the apprioprate matrix		
						{
							if (CoordsP[player][Place] == 33) break;		//If the character equals "!", then the cooridnates of a specific ship have been already read

							if (CoordsP[player][Place] == 45)		//If the character equals "-", then the next set of coordinates for a specific ship needs to be read
							{
								Place = Place + 1;

								for (int h = 0; h < 5; h++)
								{
									if (CoordsP[player][Place] == 33) break;			//If "!" character is detected, break the current loop
									CharCoordsP[player][1][ship][h] = CoordsP[player][Place];

									Place++;
								}

							}
							else
							{
								CharCoordsP[player][0][ship][j] = CoordsP[player][Place];

								Place++;
							}

						}


					}
				}

				Place += 1;




			}

			//In case we needed to check if coordinates for each ship were read properly
			/*
			cout << "\n" << Place << "\n";

			for (int i = 0; i < SPACE_FOR_CHAR_ARRAYS; i++)
			{
				cout << CharCoordsP[player][0][ship][i];
			}

			cout << "\n";

			for (int i = 0; i < SPACE_FOR_CHAR_ARRAYS; i++)
			{
				cout << CharCoordsP[player][1][ship][i];
			}
			*/
			EndOfCoords = Place;

		}



		for (int ship = 0; ship < 5; ship++)
		{

			//Beginning
			for (int u = 0; u < 10; u++)		//Converting char to int
			{
				for (int i = 0; i < SPACE_FOR_CHAR_ARRAYS; i++)
				{

					if (CharCoordsP[player][0][ship][i] == 59)			//If a character ";" (semicolon) is detected, then the number from X axis from the initial coordinates have been read
					{
						i += 1;
						if (i > 1)
						{
							for (int i2 = i; i2 < SPACE_FOR_CHAR_ARRAYS; i2++)
							{
								if (CharCoordsP[player][0][ship][i2] == 48 + u) INTCoordsP[player][0][ship][i2 - 1] = 0 + u;		//assigns apprioprate number to the integer 
																																	//array basing on the character array
							}

						}
						break;

					}
					else
					{
						if (CharCoordsP[player][0][ship][i] == 48 + u) INTCoordsP[player][0][ship][i] = 0 + u;						//assigns apprioprate number to the integer 
																																	//array basing on the character array
					}



				}
			}
			//if Beginning coordinates equal 10;10
			if (INTCoordsP[player][0][ship][0] == 1 && INTCoordsP[player][0][ship][1] == 0 && INTCoordsP[player][0][ship][2] == 1 && INTCoordsP[player][0][ship][3] == 0)
			{
				INTCoordsP[player][0][ship][0] = 10;		//the first number of the beginning coordinates is 10		
				INTCoordsP[player][0][ship][1] = 10;		//the second number of the beginning coordinates is also 10
				INTCoordsP[player][0][ship][2] = NULL;
				INTCoordsP[player][0][ship][3] = NULL;
			}
			else
			{
				if (INTCoordsP[player][0][ship][0] == 1 && INTCoordsP[player][0][ship][1] == 0)			//if beginning coordinates equal 10;x, where x is any number between 1 and 10
				{
					INTCoordsP[player][0][ship][0] = 10;		//the first number of the initial coordinates is 10	
					INTCoordsP[player][0][ship][1] = INTCoordsP[player][0][ship][2];	//the second number of the initial coordinates is x
					INTCoordsP[player][0][ship][2] = 0;			//The current second position should equal 0
				}

				if (INTCoordsP[player][0][ship][1] == 1 && INTCoordsP[player][0][ship][2] == 0)			//if //if beginning coordinates equal x;10, where x is any number between 1 and 10
				{
					//the first number of the beginning coordinates stays the same
					INTCoordsP[player][0][ship][1] = 10;		//the second number of the beginning coordinates is 10
					INTCoordsP[player][0][ship][2] = NULL;		//The current second position number should equal 0
				}

			}


			//ending
			for (int u = 0; u < 10; u++)		//Converting char to int
			{
				for (int i = 0; i < SPACE_FOR_CHAR_ARRAYS; i++)
				{

					if (CharCoordsP[player][1][ship][i] == 59)			//If the program comes across ";" then it takes the number after it as terminating set of coordinate
					{
						i += 1;
						if (i > 1)
						{
							for (int i2 = i; i2 < SPACE_FOR_CHAR_ARRAYS; i2++)
							{
								if (CharCoordsP[player][1][ship][i2] == 48 + u) INTCoordsP[player][1][ship][i2 - 1] = 0 + u;	//assigns apprioprate number to the integer 
																																//array basing on the character array
							}

						}
						break;

					}
					else
					{
						if (CharCoordsP[player][1][ship][i] == 48 + u) INTCoordsP[player][1][ship][i] = 0 + u;		//assigns apprioprate number to the integer 
																													//array basing on the character array
					}

				}
			}



			if (INTCoordsP[player][1][ship][0] == 1 && INTCoordsP[player][1][ship][1] == 0
				&& INTCoordsP[player][1][ship][2] == 1 && INTCoordsP[player][1][ship][3] == 0)		//the same procedure with coordinates 10;x and x;10, but for the terminating ones
			{
				INTCoordsP[player][1][ship][0] = 10;
				INTCoordsP[player][1][ship][1] = 10;
				INTCoordsP[player][1][ship][2] = NULL;
				INTCoordsP[player][1][ship][3] = NULL;
			}
			else
			{
				if (INTCoordsP[player][1][ship][0] == 1 && INTCoordsP[player][1][ship][1] == 0)
				{
					INTCoordsP[player][1][ship][0] = 10;
					INTCoordsP[player][1][ship][1] = INTCoordsP[player][1][ship][2];
					INTCoordsP[player][1][ship][2] = NULL;
				}

				if (INTCoordsP[player][1][ship][1] == 1 && INTCoordsP[player][1][ship][2] == 0)
				{

					INTCoordsP[player][1][ship][1] = 10;
					INTCoordsP[player][1][ship][2] = NULL;
				}

			}


		}


	}

	return 0;
}

int FilePrint(char CharGrid[2][2][11][11], int WinningPlayer[1])			//Prints the result in a file
{
	FILE* results;

	fopen_s(&results, "Results.txt", "wt");									//opens a file to write in it

	fprintf(results, "Player number %d has won!", WinningPlayer[0]);

	for (int player = 0; player < 2; player++)								//Basically the same procedure as in the DisplayCurrentCharGridStatus function, 
																			//but with fprintf functions instead of std::cout
	{																		//prints the result in the file
		if ((player + 1) != 0)
		{
			fprintf(results, "\n\nThe Grids of player number %d", player + 1);
		}

		for (int AllGrids = 0; AllGrids < 2; AllGrids++)
		{
			if (AllGrids == 0)
			{
				fprintf(results, "\n\nThe grid for the ships:");
			}
			else
			{
				fprintf(results, "\n\nThe grid for the fired shots:");
			}
			fprintf(results, "\n\n");

			fprintf(results, "  X 1 2 3 4 5 6 7 8 9 10\n Y");
			for (int FirstMatrix = 0; FirstMatrix < 10; FirstMatrix++)
			{
				fprintf(results, "\n");

				if (FirstMatrix == 9)
				{
					fprintf(results, "%d ", FirstMatrix + 1);

				}
				else
				{
					fprintf(results, " %d ", FirstMatrix + 1);
				}


				for (int SecondMatrix = 0; SecondMatrix < 10; SecondMatrix++)
				{



					fprintf(results, " %c", CharGrid[player][AllGrids][FirstMatrix][SecondMatrix]);
				}
			}
		}
	}

	//Part related to the ships' occurrence
	int ShipsOccurrence[2][5];

	for (int player = 0; player < 2; player++)
	{
		for (int p = 0; p < 5; p++)
		{
			ShipsOccurrence[player][p] = 0;				//initially, all ships occurences' are set to 0
		}
	}


	for (int player = 0; player < 2; player++)
	{


		for (int AllGrids = 0; AllGrids < 1; AllGrids++)
		{

			for (int FirstMatrix = 0; FirstMatrix < 10; FirstMatrix++)
			{

				for (int SecondMatrix = 0; SecondMatrix < 10; SecondMatrix++)			//checks every part of ships' grid for both of the players
				{
					//If some part of the ship exists - add a number to ShipsOcurrence
					if (CharGrid[player][0][FirstMatrix][SecondMatrix] == 49) ShipsOccurrence[player][0]++;		//destroyer - 1
					if (CharGrid[player][0][FirstMatrix][SecondMatrix] == 50) ShipsOccurrence[player][1]++;		//submarine - 2
					if (CharGrid[player][0][FirstMatrix][SecondMatrix] == 51) ShipsOccurrence[player][2]++;		//cruiser - 3
					if (CharGrid[player][0][FirstMatrix][SecondMatrix] == 52) ShipsOccurrence[player][3]++;		//battleship - 4
					if (CharGrid[player][0][FirstMatrix][SecondMatrix] == 53) ShipsOccurrence[player][4]++;		//carrier - 5


				}
			}



		}
	}


	fprintf(results, "\n\nSunk ships:");

	for (int player = 0; player < 2; player++)
	{

		//Here the program detects if the occurrence of every ship happened at least once, if not - it means the particular ship no longer exists 
		if (ShipsOccurrence[player][0] == 0)
		{
			fprintf(results, "\n - The Destroyer of the player number %d has been completely destroyed!", player + 1);		//printing the result in a file

			ShipsOccurrence[player][0] = 0;

		}

		if (ShipsOccurrence[player][1] == 0)
		{
			fprintf(results, "\n - The Submarine of the player number %d has been completely destroyed!", player + 1);		//printing the result in a file

			ShipsOccurrence[player][1] = 0;

		}

		if (ShipsOccurrence[player][2] == 0)
		{
			fprintf(results, "\n - The Cruiser of the player number %d has been completely destroyed!", player + 1);		//printing the result in a file

			ShipsOccurrence[player][2] = 0;

		}

		if (ShipsOccurrence[player][3] == 0)
		{
			fprintf(results, "\n - The Battleship of the player number %d has been completely destroyed!", player + 1);		//printing the result in a file

			ShipsOccurrence[player][3] = 0;

		}

		if (ShipsOccurrence[player][4] == 0)
		{
			fprintf(results, "\n - The Carrier of the player number %d has been completely destroyed!", player + 1);		//printing the result in a file

			ShipsOccurrence[player][4] = 0;

		}


	}


	fclose(results);			//closes the file


	return 0;
}


int main()
{

	string CoordsP[2];
	//Player 1 = 0
	//Player 2 = 1

	File(CoordsP);			//Creating and reading information about coordinates from the file

	//GeneralInfo();		//General rules and information about the game

		//Destroyer = 0
		//Submarine = 1
		//Cruiser = 2
		//Battleship = 3
		//Carrier = 4
		//Beginning = 0
		//End = 1

		//This is how coordinates should be read by players:
		//(x,y)   
		//x = collumn
		//y = row

		//This is how coordinates are read by grids:
		//(x,y)   
		//x = row
		//y = collumn

	char CharCoordsP[2][2][5][SPACE_FOR_CHAR_ARRAYS]; //player ,Beginning or end of 1 set of coordinates, type of ship, each number

	int INTCoordsP[2][2][5][5];		//player, beginning or end of 1 set of coordinates, type of ship, each number

	ReadingCoords(INTCoordsP, CharCoordsP, CoordsP);


	//Destroyer = 0
	//Submarine = 1
	//Cruiser = 2
	//Battleship = 3
	//Carrier = 4
	//Beginning = 0
	//End = 1

	string ShipName[5];				//Names of the ships
	ShipName[0] = "Destroyer";
	ShipName[1] = "Submarine";
	ShipName[2] = "Cruiser";
	ShipName[3] = "Battleship";
	ShipName[4] = "Carrier";


	//INTCoordsP[2][2][5][5];		//player, Beginning or end of 1 set of coordinates, type of ship, particular number

	Assessment(INTCoordsP, ShipName);	//Checking if coordinates are determined properly


	//Creating the grids themselves

	//player 1 = 0
	//player 2 = 1
	//grid 0 = ships of the player 
	//grid 1 = shots of the player 


	int Grid[2][2][10][10];			//player, grid for ships or for hits, matrix 10 x 10 - for integers
	char CharGrid[2][2][11][11];	//player, grid for ships or for hits, matrix 10 x 10 - for characters

	//for characters grid:
	//0 - blank space
	//Destroyer = 1
	//Submarine = 2
	//Cruiser = 3
	//Battleship = 4
	//Carrier = 5

	//Previously:
	//Destroyer = 0
	//Submarine = 1
	//Cruiser = 2
	//Battleship = 3
	//Carrier = 4
	//Beginning = 0
	//End = 1

	//Setting each element in each grid to 0

	for (int player = 0; player < 2; player++)
	{

		for (int AllGrids = 0; AllGrids < 2; AllGrids++)
		{

			for (int FirstMatrix = 0; FirstMatrix < 10; FirstMatrix++)
			{

				for (int SecondMatrix = 0; SecondMatrix < 10; SecondMatrix++)
				{
					Grid[player][AllGrids][FirstMatrix][SecondMatrix] = 0;

					CharGrid[player][AllGrids][FirstMatrix][SecondMatrix] = 48;
				}
			}
		}
	}

	//An empty slot = 0
	//Destroyer = 1
	//Submarine = 2
	//Cruiser = 3
	//Battleship = 4
	//Carrier = 5

	PuttingShipsOnGrid(INTCoordsP, Grid, CharGrid, ShipName);			//Putting ships on the grids + checking if they don't overlap one another


	//The proper game begins

	int WinningPlayer[1];
	WinningPlayer[0] = 3;		//The winning player is initially set to 3 - in order not to be mistaken with anybody else

	int StartPlayer = 0;
	int ContPlayer = 1;

	while ((StartPlayer != 1) && (StartPlayer != 2))		//Determining the starting and the next player
	{
		cout << "\n\nWhich player should start?\n";
		cin >> StartPlayer;

		if ((StartPlayer != 1) && (StartPlayer != 2))
		{
			cout << "\n\nThe starting player should be either 1 or 2!";
		}
	}

	system("cls");			//clears the debugger from all of the previous information


	StartPlayer -= 1;

	if (StartPlayer == 0)		//The program reads player 1 as 0, and player 2 as 1
	{
		ContPlayer = 1;
	}

	if (StartPlayer == 1)
	{
		ContPlayer = 0;
	}

	war(StartPlayer, ContPlayer, Grid, CharGrid, WinningPlayer);		//A general war that consists of battles - the number of which depends on how the game plays out


	//Printing results in the file

	FilePrint(CharGrid, WinningPlayer);

	return 0;
}

//The code was created by Ksawery Leœniak in Visual Studio 2019, using c++ language