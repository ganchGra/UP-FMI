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
#include<iostream>

int TotalInvolve(const int a,const int b){
	int total = 0;
	int numOfDigit = 0;
	int firstNum = a;
	int secondNum = b;
	
	while (firstNum > 0)
	{
		numOfDigit++;
		firstNum = firstNum / 10;
	}
	int tenPower = 1;
	while (numOfDigit > 0)
	{
		tenPower *= 10;
		numOfDigit--;
	}
	while (secondNum)
	{
		int numToCheck = secondNum % tenPower;
		if (a == numToCheck)
		{
			total++;
		}
		secondNum /= 10;
	}
	return total;
}

int main(){
	unsigned int a, b;
	std::cin >> a >> b;
	if (a <= 4000000000 && b <= 4000000000)
	{
		std::cout << TotalInvolve(a, b) << "\n";
	}
	return 0;
}