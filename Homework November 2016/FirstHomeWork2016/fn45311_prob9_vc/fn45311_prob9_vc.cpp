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

#include <iostream>
using namespace std;

int main(){

	unsigned int num1, num2, a_over, b_over;
	char sign;
	int result = 0;
	cin >> num1 >> sign >> num2;

	//check the overflow
	a_over = num1 / 16;
	b_over = num2 / 16;

	num1 = num1 - (a_over * 16);
	num2 = num2 - (b_over * 16);

	switch (sign)
	{
	case '+':
		result = num1 + num2;
		break;
	case '-':
		result = num1 - num2;
		break;
	case '/':
		if (num2 == 0)
		{
			cout << "Division by zero!\n";
			return 0;
		}
		else{
			result = num1 / num2;
		}
		break;
	case '.':
		result = num1 * num2;
		break;
	case '%':
		if (num1 == 0 || num2 == 0)
		{
			cout << "Division by zero!\n";
			return 0;
		}
		else{
			result = num1 % num2;
		}
		break;
	}

	if (result > 15)
	{
		int result_over = result / 16;
		result = result - (result_over * 16);
	}
	else if (result < 0)
	{
		result = 16 + result;
	}
	cout << result << "\n";

	return 0;
}