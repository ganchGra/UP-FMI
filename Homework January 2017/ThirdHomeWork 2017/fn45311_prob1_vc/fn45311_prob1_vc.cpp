/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Gratsiela Gancheva
* @idnumber 45311
* @task 1
* @compiler VC
*
*/

#include<iostream>

void printaN(unsigned short n){
	if (n == 1){
		std::cout<<1;
		return;
	}
	printaN(n - 1);
	std::cout << n;
	printaN(n - 1);
}

int main(){
	unsigned short n;
	std::cin >> n;

	if (n > 0 && n < 20){
		printaN(n);
		std::cout << "\n";
	}
	else{
		return 1;
	}

	return 0;
}