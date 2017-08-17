/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Gratsiela Gancheva
* @idnumber 45311
* @task 1
* @compiler VC
*
*/

#include <iostream>

using namespace std;

int main()
{
	int num;
	cin >> num;

	if (num <= 0 || num > 3000)
	{
		cout << "Invalid number!\n";
		return 0;
	}

	int firstEl = num % 10;                                        
	int secondEl = (num % 100) - firstEl;					     
	int thirdEl = (num % 1000) - secondEl - firstEl;             
	int fourthEl = (num % 10000) - thirdEl - secondEl - firstEl; 

	//thousand convertion
	if (fourthEl == 1000)
	{
		cout << "M";
	}
	else if (fourthEl == 2000)
	{
		cout << "MM";
	}
	else if (fourthEl == 3000){
		cout << "MMM";
	}

	//hundred convertion
	if (thirdEl == 900)
	{
		cout << "CM";
	}
	else if (thirdEl == 800)
	{
		cout << "DCCC";
	}
	else if (thirdEl == 700)
	{
		cout << "DCC";
	}
	else if (thirdEl == 600)
	{
		cout << "DC";
	}
	else if (thirdEl == 500)
	{
		cout << "D";
	}
	else if (thirdEl == 400)
	{
		cout << "CD";
	}
	else if (thirdEl == 300)
	{
		cout << "CCC";
	}
	else if (thirdEl == 200)
	{
		cout << "CC";
	}
	else if (thirdEl == 100)
	{
		cout << "C";
	}

	//decimal convertion
	if (secondEl == 90)
	{
		cout << "XC";
	}
	else if (secondEl == 80)
	{
		cout << "LXXX";
	}
	else if (secondEl == 70)
	{
		cout << "LXX";
	}
	else if (secondEl == 60)
	{
		cout << "LX";
	}
	else if (secondEl == 50)
	{
		cout << "L";
	}
	else if (secondEl == 40)
	{
		cout << "XL";
	}
	else if (secondEl == 30)
	{
		cout << "XXX";
	}
	else if (secondEl == 20)
	{
		cout << "XX";
	}
	else if (secondEl == 10)
	{
		cout << "X";
	}

	//single number convertion
	if (firstEl == 9)
	{
		cout << "IX\n";
	}
	else if (firstEl == 8)
	{
		cout << "VIII\n";
	}
	else if (firstEl == 7)
	{
		cout << "VII\n";
	}
	else if (firstEl == 6)
	{
		cout << "VI\n";
	}
	else if (firstEl == 5)
	{
		cout << "V\n";
	}
	else if (firstEl == 4)
	{
		cout << "IV\n";
	}
	else if (firstEl == 3)
	{
		cout << "III\n";
	}
	else if (firstEl == 2)
	{
		cout << "II\n";
	}
	else if (firstEl == 1)
	{
		cout << "I\n";
	}
	else if (firstEl == 0)
	{
		cout << "\n";

	}

	return 0;
}