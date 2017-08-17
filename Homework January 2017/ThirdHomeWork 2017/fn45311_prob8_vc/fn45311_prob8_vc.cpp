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

#include<iostream>

void FillTheArray(int * nums, unsigned size){
	if (nums==NULL)
	{
		return;
	}
	for (unsigned i = 0; i < size; i++)
	{
		std::cin >> nums[i];
	}
}

//************CALCULATE VERIFICATION*******************//
unsigned whiteSpase = 0;

void DivisibleByThree(int * num, unsigned size){
	for (unsigned i = 0; i < size; i++)
	{
		if (num[i] % 3 == 0 && whiteSpase == 0){
			std::cout << num[i];
			whiteSpase++;
		}
		else if (num[i] % 3 == 0 && whiteSpase > 0)
		{
			std::cout << " " << num[i];
		}
	}
}
void ModThreeEqualtoOne(int * num, unsigned size){
	for (unsigned i = 0; i < size; i++)
	{
		if (num[i] % 3 == 1 && whiteSpase == 0){
			std::cout << num[i];
			whiteSpase++;
		}
		else if (num[i] % 3 == 1 && whiteSpase > 0)
		{
			std::cout << " " << num[i];
		}
	}
}
void NotDivisibleByThree(int * num, unsigned size){
	unsigned newPosition = 0;
	for (unsigned i = 0; i < size; i++)
	{
		if (num[i] % 3 != 0 && num[i] % 3 != 1){
			num[newPosition] = num[i];
			newPosition++;
		}
	}
	if (newPosition > 0)
	{
		for (unsigned k = 0; k < newPosition; k++)
		{
			if (whiteSpase == 0 && newPosition >1){
				std::cout << num[k];
				whiteSpase++;
			}
			else
			{
				std::cout << " " << num[k];
			}
		}
	}
	

}
//**********************END***************************//
int main(){
	unsigned N;
	std::cin >> N;
	if (N <= 0 || N >= 100000)
	{
		return -1;
	}
	int *nums = new (std::nothrow) int[N];

	if (*nums == NULL)
	{
		std::cout << "MEMORY FULL\n";
		return -1;
	}

	FillTheArray(nums, N);
	//*****************PRINT RESULT**************//
	DivisibleByThree(nums,N);
	ModThreeEqualtoOne(nums, N);
	NotDivisibleByThree(nums, N);
	std::cout << "\n";
	//*******************END****************//

	delete[] nums;
	return 0;
}