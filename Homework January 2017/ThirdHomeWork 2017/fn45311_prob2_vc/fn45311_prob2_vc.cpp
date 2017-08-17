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

#include<iostream>
void printNcombination(short num , short *arr, short index, const short original){// const unsigned original){
	if (num == 0)
	{
		std::cout << original << " = ";
		for (short i = 0; i < index; i++)
		{
			if (i != 0)
				std::cout << " + ";
			
			std::cout << arr[i];
		}
		std::cout << "\n";
		return;
	}

	for (short i = num; i > 0; i--)
	{
		if (index == 0 || i <=arr[index - 1])
		{
			arr[index] = i;
			printNcombination(num - i, arr, index + 1, original);
		}
	}
}

int main(){
    short n;
	std::cin >> n;
	short arr[36] = { 0 };

	if (n > 0 && n <=32)
	{
		printNcombination(n,arr,0,n);
	}
	else{
		return 1;
	}
	return 0;
}