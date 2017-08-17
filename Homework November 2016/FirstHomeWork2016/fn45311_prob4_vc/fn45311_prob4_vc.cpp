/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Gratsiela Gancheva
* @idnumber 45311
* @task 4
* @compiler VC
*
*/

#include <iostream>

using namespace std;

int main()
{
	char attacher;

	char attCol, kingCol;
	int attRow, kingRow;

	cin >> attacher;
	cin >> attCol >> attRow;
	cin >> kingCol >> kingRow;

	switch (attacher)
	{
	case 'Q':
		//+
		if (attCol == kingCol || attRow == kingRow)
		{
			cout << "Yes\n";
		}
		//up-right
		else if ((attCol + 1 == kingCol && attRow + 1 == kingRow) || (attCol + 2 == kingCol && attRow + 2 == kingRow) ||
			(attCol + 3 == kingCol && attRow + 3 == kingRow) || (attCol + 4 == kingCol && attRow + 4 == kingRow) ||
			(attCol + 5 == kingCol && attRow + 5 == kingRow) || (attCol + 6 == kingCol && attRow + 6 == kingRow) ||
			(attCol + 7 == kingCol && attRow + 7 == kingRow))
		{
			cout << "Yes\n";
		}
		//up-left
		else if ((attCol - 1 == kingCol && attRow + 1 == kingRow) || (attCol - 2 == kingCol && attRow + 2 == kingRow) ||
			(attCol - 3 == kingCol && attRow + 3 == kingRow) || (attCol - 4 == kingCol && attRow + 4 == kingRow) ||
			(attCol - 5 == kingCol && attRow + 5 == kingRow) || (attCol - 6 == kingCol && attRow + 6 == kingRow) ||
			(attCol - 7 == kingCol && attRow + 7 == kingRow))
		{
			cout << "Yes\n";
		}
		//down-left
		else if ((attCol - 1 == kingCol && attRow - 1 == kingRow) || (attCol - 2 == kingCol && attRow - 2 == kingRow) ||
			(attCol - 3 == kingCol && attRow - 3 == kingRow) || (attCol - 4 == kingCol && attRow - 4 == kingRow) ||
			(attCol - 5 == kingCol && attRow - 5 == kingRow) || (attCol - 6 == kingCol && attRow - 6 == kingRow) ||
			(attCol - 7 == kingCol && attRow - 7 == kingRow))
		{
			cout << "Yes\n";
		}
		//down-right
		else if ((attCol + 1 == kingCol && attRow - 1 == kingRow) || (attCol + 2 == kingCol && attRow - 2 == kingRow) ||
			(attCol + 3 == kingCol && attRow - 3 == kingRow) || (attCol + 4 == kingCol && attRow - 4 == kingRow) ||
			(attCol + 5 == kingCol && attRow - 5 == kingRow) || (attCol + 6 == kingCol && attRow - 6 == kingRow) ||
			(attCol + 7 == kingCol && attRow - 7 == kingRow))
		{
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
		break;
	case'B':
		//up-right
		if ((attCol + 1 == kingCol && attRow + 1 == kingRow) || (attCol + 2 == kingCol && attRow + 2 == kingRow) ||
			(attCol + 3 == kingCol && attRow + 3 == kingRow) || (attCol + 4 == kingCol && attRow + 4 == kingRow) ||
			(attCol + 5 == kingCol && attRow + 5 == kingRow) || (attCol + 6 == kingCol && attRow + 6 == kingRow) ||
			(attCol + 7 == kingCol && attRow + 7 == kingRow))
		{
			cout << "Yes\n";
		}
		//up-left
		else if ((attCol - 1 == kingCol && attRow + 1 == kingRow) || (attCol - 2 == kingCol && attRow + 2 == kingRow) ||
			(attCol - 3 == kingCol && attRow + 3 == kingRow) || (attCol - 4 == kingCol && attRow + 4 == kingRow) ||
			(attCol - 5 == kingCol && attRow + 5 == kingRow) || (attCol - 6 == kingCol && attRow + 6 == kingRow) ||
			(attCol - 7 == kingCol && attRow + 7 == kingRow))
		{
			cout << "Yes\n";
		}
		//down-left
		else if ((attCol - 1 == kingCol && attRow - 1 == kingRow) || (attCol - 2 == kingCol && attRow - 2 == kingRow) ||
			(attCol - 3 == kingCol && attRow - 3 == kingRow) || (attCol - 4 == kingCol && attRow - 4 == kingRow) ||
			(attCol - 5 == kingCol && attRow - 5 == kingRow) || (attCol - 6 == kingCol && attRow - 6 == kingRow) ||
			(attCol - 7 == kingCol && attRow - 7 == kingRow))
		{
			cout << "Yes\n";
		}
		//down-right
		else if ((attCol + 1 == kingCol && attRow - 1 == kingRow) || (attCol + 2 == kingCol && attRow - 2 == kingRow) ||
			(attCol + 3 == kingCol && attRow - 3 == kingRow) || (attCol + 4 == kingCol && attRow - 4 == kingRow) ||
			(attCol + 5 == kingCol && attRow - 5 == kingRow) || (attCol + 6 == kingCol && attRow - 6 == kingRow) ||
			(attCol + 7 == kingCol && attRow - 7 == kingRow))
		{
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}

		break;
	case 'N':
		if (attCol + 2 == kingCol && attRow + 1 == kingRow)
		{
			cout << "Yes\n";
		}
		else if (attCol + 2 == kingCol && attRow - 1 == kingRow)
		{
			cout << "Yes\n";
		}
		else if (attCol + 1 == kingCol && attRow + 2 == kingRow)
		{
			cout << "Yes\n";
		}
		else if (attCol + 1 == kingCol && attRow - 2 == kingRow)
		{
			cout << "Yes\n";
		}
		else if (attCol - 2 == kingCol && attRow + 1 == kingRow)
		{
			cout << "Yes\n";
		}
		else if (attCol - 2 == kingCol && attRow - 1 == kingRow)
		{
			cout << "Yes\n";
		}
		else if (attCol - 1 == kingCol && attRow + 2 == kingRow)
		{
			cout << "Yes\n";
		}
		else if (attCol - 1 == kingCol && attRow - 2 == kingRow)
		{
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
		break;
	case'R':
		if (attCol == kingCol || attRow == kingRow)
		{
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
		break;
	default:
		cout << "No\n";
		break;
	}
	
	return 0;
}