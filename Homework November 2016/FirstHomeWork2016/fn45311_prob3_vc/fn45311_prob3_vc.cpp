/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Gratsiela Gancheva
* @idnumber 45311
* @task 3
* @compiler VC
*
*/

#include <iostream>

using namespace std;

int main()
{
   unsigned int num;
	cin >> num;

	unsigned int mirror;
	unsigned int x = num;

	//take 4 bites
	x = (x << 28);
	x = (x >> 28);

	if ((num >> 4) == 0)
	{
		mirror = x;
		if (num == mirror){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
	else if ((num >> 8) == 0)
	{
		mirror = x | (x << 4);
		if (num == mirror){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
	else if ((num >> 12) == 0)
	{
		mirror = x | x << 4| x << 8;
		if (num == mirror){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
	else if ((num >> 16) == 0)
	{
		mirror = x | (x << 4) | (x << 8) | (x << 12);
		if (num == mirror){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
	else if ((num >> 20) == 0)
	{
		mirror = x | (x << 4) | (x << 8) | (x << 12) | (x << 16);
		if (num == mirror){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
	else if ((num >> 24) == 0)
	{
		mirror = x | (x << 4) | (x << 8) | (x << 12) | (x << 16) | (x << 20);
		if (num == mirror){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
	else if ((num >> 28) == 0)
	{
		mirror = x | (x << 4) | (x << 8) | (x << 12) | (x << 16) | (x << 20) | (x << 24);
		if (num == mirror){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}

	return 0;
}