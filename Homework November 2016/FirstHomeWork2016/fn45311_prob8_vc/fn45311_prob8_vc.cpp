/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Gratsiela Gancheva
* @idnumber 45311
* @task 8
* @compiler VC
*
*/

#include <iostream>
using namespace std;

int main(){

	unsigned int cash;
	int fifties, twenties, tens, fifts, twos, ones;
	cin >> cash;
	int originalSum = cash;

	cout << originalSum << " = ";
	if (cash/50 != 0)
	{
		fifties = cash / 50;
		cash =  cash - (fifties * 50);
		cout << fifties << "*50";
	}
	if (cash/20 !=0)
	{
		twenties = cash / 20;
		cash = cash - (twenties * 20);
		if (originalSum >= 50)
		{
			cout << " + ";
		}
		cout << twenties << "*20";
	}
	if (cash/10 !=0)
	{
		tens = cash / 10;
		cash = cash - (tens * 10);
		if (originalSum >=20)
		{
			cout << " + ";
		}
		cout << tens << "*10";
	}
	if (cash/5 != 0)
	{
		fifts = cash / 5;
		cash = cash - (fifts * 5);
		if (originalSum >= 10)
		{
			cout << " + ";
		}
		cout << fifts << "*5";
	}
	if (cash/2 != 0)
	{
		twos = cash / 2;
		cash = cash - (twos * 2);
		if (originalSum >= 5)
		{
			cout << " + ";
		}
		cout << twos << "*2";
	}
	if (cash/1 != 0)
	{
		ones = cash / 1;
		if (originalSum >= 5)
		{
			cout << " + ";
		}
		cout << ones << "*1";

	}
	cout << "\n";
	return 0;
}