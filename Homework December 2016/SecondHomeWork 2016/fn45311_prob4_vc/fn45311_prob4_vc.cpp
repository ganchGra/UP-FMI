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

#include<iostream>

bool isInTo(int num, int inTo){
	int firstNumToCheck, secNumToCheck;
	bool result = false;

	while (num)
	{
		firstNumToCheck = num % 10;
		while (inTo)
		{
			secNumToCheck = inTo % 10;
			if (firstNumToCheck == secNumToCheck)
				result = true;
			
			inTo /= 10;
		}

		if (result == false) 
			return false;

		num /= 10;
	}

	return result;
}

void identicalSets( int firstNum, int secondNum){
	firstNum = abs(firstNum);
	secondNum = abs(secondNum);
	bool aInb = isInTo(firstNum, secondNum);
	bool bIna = isInTo(secondNum, firstNum);
	
	if (aInb && bIna)
		std::cout << "Yes\n";
	else
		std::cout << "No\n";

}

int main(){
	int first, second;
	std::cin >> first >> second;

	identicalSets(first, second);

	return 0;
}