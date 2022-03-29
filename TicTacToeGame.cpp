

#include <iostream>
#include <string>
using namespace std;

char board[9] = { '1','2','3','4', '5','6','7','8','9'};

void printBoard(); //function to print the board
int gameStatus();//function to determine the status of the game 

int main()
{
	string choice; // players choice in the game
	
	int player = 1; // player 1 or 2
	char mark; // X or O
	int spottaken = 0; // keeps track fo whether or not the spot has been played

	do //loop to keep the game going
	{

		do { // do while loop that validates users choice on the board

			printBoard();

			//determines which mark to use
			if (player == 1)
			{
				mark = 'X';
			}
			else
				mark = 'O';


			//to validate user input to make sure they enter 1-9 
			do {
				cout << "\nPlayer " << player << ", enter a spot on the board (an integer from 1-9)";
				cin >> choice;

			} while (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6" && choice != "7" && choice != "8" && choice != "9");


			char choice_char = choice[0]; //since we know its a single digit string that was entered by the user, we take the array position 0

			spottaken = 0; // we make spot taken=0 to assume the users choice is right and then enter the switch
			switch (choice_char)
			{
			case '1':
				if (board[0] == '1') // the choice hasnt been played, so we assign the correct mark to it
					board[0] = mark;

				else // if the spot on the board isnt 1, it means its x or o , which means the spot is taken
				{
					spottaken = 1; // change the value
					cout << "\nThis spot has been taken.Please review the board and choose another spot ";
				}
				break;

			case '2':
				if (board[1] == '2')
					board[1] = mark;
				else
				{
					spottaken = 1;
					cout << "\nThis spot has been taken.Please review the board and choose another spot ";
				}
				break;

			case '3':
				if (board[2] == '3')
					board[2] = mark;
				else
				{
					spottaken = 1;
					cout << "\nThis spot has been taken.Please review the board and choose another spot ";
				}
				break;

			case '4':
				if (board[3] == '4')
					board[3] = mark;
				else
				{
					spottaken = 1;
					cout << "\nThis spot has been taken.Please review the board and choose another spot ";
				}
				break;

			case '5':
				if (board[4] == '5')
					board[4] = mark;
				else
				{
					spottaken = 1;
					cout << "\nThis spot has been taken.Please review the board and choose another spot ";
				}
				break;

			case '6':
				if (board[5] == '6')
					board[5] = mark;
				else
				{
					spottaken = 1;
					cout << "\nThis spot has been taken.Please review the board and choose another spot ";
				}
				break;

			case '7':
				if (board[6] == '7')
					board[6] = mark;
				else
				{
					spottaken = 1;
					cout << "\nThis spot has been taken.Please review the board and choose another spot ";
				}
				break;

			case '8':
				if (board[7] == '8')
					board[7] = mark;
				else
				{
					spottaken = 1;
					cout << "\nThis spot has been taken.Please review the board and choose another spot ";
				}
				break;

			case '9':
				if (board[8] == '9')
					board[8] = mark;
				else
				{
					spottaken = 1;
					cout << "\nThis spot has been taken.Please review the board and choose another spot ";
				}
				break;
			}

			
		} while (spottaken == 1); // keep looping and asking the player to re enter the position it wants until they enter a spot that hasnt been played yet

		//we only change the players turn if they play a valid turn (chose a position from 1-9 that hasnt been played)
			if (player == 1)
			{
				player=2;
			}
			else
				player=1;

			
			
	} while (gameStatus() == 0); // keep looping until the game is a win or tie
	
	printBoard(); // print the board to show final results



//print statement to end the game

	if (gameStatus() == 1)
	{
		if (player == 2)
		{
			cout << " Player 1 Won!!";
		}
		else if (player == 1)
		{
			cout << " Player  2 Won!!";
		}
	}
	else
		cout << "Its a tie, you both lose!";
}


void printBoard()
{
	cout << "\n";
	cout << "Player 1 (X)    -    Player 2 (O)";
	cout << "\n";


	cout << "    |    |    " << endl;
	cout << "  " << board[0] << " | " << board[1] << "  |  " << board[2] << endl;
	cout << "____|____|____" << endl;
	cout << "    |    |    " << endl;
	cout << " " << board[3] << "  | " << board[4] << "  |  " << board[5] << endl;
	cout << "____|____|____" << endl;
	cout << "    |    |    " << endl;
	cout << " " << board[6] << "  | " << board[7] << "  |  " << board[8] << endl;
	cout << "    |    |    " << endl;

}


int gameStatus()
{
	//using the patterns of tic tac toe, we check if the player won
		//we will return 1 if the user won the game
		//we will return -1 if no one has won
		//we will return 0 if neither of the above has happened(the game is still going)

		//first we check if all the rows are equal to each other (horizontal win)

	if (board[0] == board[1] && board[1] == board[2]) //row 1
		return 1;

	else if (board[3] == board[4] && board[4] == board[5]) //row 2
		return 1;

	else if (board[6] == board[7] && board[7] == board[8]) //row 3
		return 1;

	//now we check if columns are equal (vertical wins)
	else if (board[0] == board[3] && board[3] == board[6]) //column 1
		return 1;

	else if (board[1] == board[4] && board[4] == board[7]) //column 2
		return 1;

	else if (board[2] == board[5] && board[5] == board[8]) //row 1
		return 1;

	//now we check for diagonal wins
	else if (board[0] == board[4] && board[4] == board[8]) //diagonal 1
		return 1;

	else if (board[2] == board[4] && board[4] == board[6]) //diagonal 2
		return 1;

	//now we check if all of the positions have been played, but theres no win

	else if (board[0] != '1' && board[1] != '2' && board[2] != '3' && board[3] != '4'
		&& board[4] != '5' && board[5] != '6' && board[6] != '7' && board[7] != '8' && board[8] != '9')
		return -1;

	else
		return 0;

}

