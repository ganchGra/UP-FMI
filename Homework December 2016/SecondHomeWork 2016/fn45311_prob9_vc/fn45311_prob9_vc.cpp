/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Gratsiela Gancheva
* @idnumber 45311
* @task 9
* @compiler VC
*
*/

#include<iostream>

void isTheSame(unsigned firstNum, unsigned secondNum){
	bool result = true;
	bool checkB = true;
	int num1, num2;
	
	while (firstNum)
	{
		num1 = firstNum % 10;
		num2 = secondNum % 10;
		if (num1 != num2)
		{
			firstNum /= 10;
			num1 = firstNum % 10;
			if (num1 != num2)
			{
				std::cout << "No\n";
				return;
			}
		}
		firstNum /= 10;
		secondNum /= 10;
	}
	std::cout << "Yes\n";
}
int main(){
	unsigned firstNum, secondNum;
	std::cin >> firstNum >> secondNum;
	isTheSame(firstNum, secondNum);

	return 0;
}