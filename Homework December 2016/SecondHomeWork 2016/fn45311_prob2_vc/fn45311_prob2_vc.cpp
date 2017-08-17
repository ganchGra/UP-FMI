/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Gratsiela Gancheva
* @idnumber 45311
* @task 2
* @compiler VC
*
*/
#include <iostream>

bool isPrime(const int num){
	if (num == 0 || num == 1 || num == 2) return false;
	
	int sqrtN = sqrt(num);
	for (int i = 3; i <= sqrtN; i+=2)
	{
		if (num%i == 0)	return false;
	}
	return true;
}

void twinsNumber(const int n){
	if (n >= 100000) return;
	
	int primeP = 3;
	int primeQ = 5;
	bool checkP = false;
	bool checkQ = false;
	for (int i = 1; i <= n; i++)
	{
		std::cout << primeP << " " << primeQ << "\n";
		while (checkP==false)
		{
			primeP += 2;
			primeQ = primeP + 2;
			checkP = isPrime(primeP);
			checkQ = isPrime(primeQ);
			if (checkP && checkQ)
			{
				checkP = false;
				checkQ = false;
				break;
			}
			else{
				checkP = false;
				checkQ = false;
			}
		}
	}
}
int main(){
	int n;
	std::cin >> n;
	twinsNumber(n);

	return 0;
}