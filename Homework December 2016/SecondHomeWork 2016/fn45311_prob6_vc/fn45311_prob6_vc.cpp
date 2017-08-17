/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Gratsiela Gancheva
* @idnumber 45311
* @task 6
* @compiler VC
*
*/

#include<iostream>

void binomialCoefficent(const unsigned n){
	unsigned k = 0;
	unsigned long long binomial_Coef = 1;
	std::cout << binomial_Coef << " ";  //print the first element

	while (k < n)
	{
		binomial_Coef = binomial_Coef * (n - k ) / (k + 1);
		if (k == n-1)
			std::cout << binomial_Coef << "\n";
		else
			std::cout << binomial_Coef << " ";

		k++;
	}
}
int main(){
	unsigned n;
	std::cin >> n;
	binomialCoefficent(n);

	return 0;
}