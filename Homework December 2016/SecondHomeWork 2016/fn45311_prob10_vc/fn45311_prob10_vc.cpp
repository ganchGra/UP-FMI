/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Gratsiela Gancheva
* @idnumber 45311
* @task 10
* @compiler VC
*
*/

#include<iostream>
//**********ALL FUNCTION************//
bool isPrime(const unsigned num);
int numberDivision(const unsigned n, const unsigned divisor);
void pAdicOrder(const unsigned p1, const unsigned n, const unsigned p2);
//**********************************//

bool isPrime(const unsigned num){
	if (num == 0 || num == 1) return false;

	int sqrtN = sqrt(num);
	for (int i = 2; i <= sqrtN; i += 2)
	{
		if (num%i == 0)	return false;
	}
	return true;
}

int numberDivision(const unsigned n,const unsigned divisor){
	unsigned num = n;
	int totDiv = 0;

	while (num / divisor != 0 && num % divisor ==0)
	{	
		totDiv++;
		num /= divisor;
	}
	return totDiv;
}
void pAdicOrder(const unsigned p1,const unsigned n,const unsigned p2){
	
	if (p1 <= 1 || p1 > 100000007 || 
		p2 <= 1 || p2 > 100000007 ||
		n > 100000007)
	{
		return;
	}
	if (isPrime(p1) == false || isPrime(p2) == false)
		return;
	
	int numDivionp1 = numberDivision(n, p1);
	int numDivionp2 = numberDivision(n, p2);
	
	if (numDivionp1 == 0 && numDivionp2 == 0)
		std::cout << "infinity\n";
	else if (numDivionp1 >= numDivionp2)
		std::cout << numDivionp1 << "\n";
	else
		std::cout << numDivionp2 << "\n";
}

int main(){
	unsigned nq,p1,p2,n;
	std::cin >> nq;
	if (nq < 0 || nq > 1000000){ return 1; }

	for (int i = 0; i<nq; i++)
	{
		std::cin >> p1 >> n >> p2;
		pAdicOrder(p1, n, p2);
	}

	return 0;
}