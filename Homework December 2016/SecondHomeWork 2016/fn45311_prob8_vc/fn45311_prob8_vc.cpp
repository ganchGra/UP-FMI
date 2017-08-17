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

//************ALL FUNCTION************//
int calc_power(int n, int power);
bool isInThisSystem(int number, const int systemType);
void printResult_In_K_System(int num, const int k);
int convertInDecimal(int n, int kSystem);
void calculator(const int n, const int m, const int k);
//************************************//
int calc_power(int n, int power){
	int result=1;
	for (int i = 0; i < power; i++)
	{
		result *= n;
	}
	return result;
}

bool isInThisSystem(int number, const int systemType){
	bool result = true;
	while (number)
	{
		int singleNum = number % 10;
		if (singleNum >= systemType)
			result = false;

		number /= 10;
	}

	return result;
}

void printResult_In_K_System(int num, const int k){
	if (num == 0)
	{
		return;
	}
	int numToPrint = num % k;
	printResult_In_K_System(num / k, k);
	std::cout << numToPrint;
}

int convertInDecimal(int n, int kSystem){
	int decimalNumber = 0;
	int cntpow = 0;
	while (n)
	{
		int num = n % 10;
		decimalNumber += num * calc_power(kSystem, cntpow);
		cntpow++;
		n /= 10;
	}
	return decimalNumber;
}

void calculator(const int n,const int m,const int k){
	if (k < 2 || k > 10 ||
		n < 0 || n > 500000 ||
		m < 0 || m > 500000)
	{
		std::cout << "Bad input data!\n";
		return;
	}

	bool firstNum = isInThisSystem(n, k);
	bool secondNum = isInThisSystem(m, k);
	if (firstNum == false || secondNum == false)
	{
		std::cout << "Bad input data!\n";
		return;
	}
	int firstNumDecimal = convertInDecimal(n,k);
	int secondNumDecimal = convertInDecimal(m,k);
	int sum = firstNumDecimal + secondNumDecimal;
	printResult_In_K_System(sum, k);
	std::cout << "\n";
}

int main(){
	int n, m, k;
	std::cin >> n >> m >> k;
	calculator(n, m, k);

	return 0;
}