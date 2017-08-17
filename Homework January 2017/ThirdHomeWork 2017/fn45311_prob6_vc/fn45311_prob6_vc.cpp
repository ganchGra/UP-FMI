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
void SelectionSort(double **arr,unsigned size){
	double tempFN, tempN, tempP;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j][0] < arr[i][0])
			{
				tempFN = arr[j][0];
				tempN = arr[j][1];
				tempP = arr[j][2];
				arr[j][0] = arr[i][0];
				arr[j][1] = arr[i][1];
				arr[j][2] = arr[i][2];

				arr[i][0] = tempFN;
				arr[i][1] = tempN;
				arr[i][2] = tempP;
			}
			else if (arr[i][0] == arr[j][0] && (arr[j][1] < arr[i][1]))
			{
				tempN = arr[j][1];
				tempP = arr[j][2];
				arr[j][1] = arr[i][1];
				arr[j][2] = arr[i][2];

				arr[i][1] = tempN;
				arr[i][2] = tempP;
			}
		}
	}
}
void freeMemory(double ** arr,unsigned size){
	for (int i = 0; i < size; i++)
	{
		delete[] arr[i];
	}
	delete[]arr;
}

int main(){
	unsigned line;

	std::cin >> line;

	double **arr = new (std::nothrow) double *[line];
	if (arr == NULL)
	{
		std::cout << "MEMORY FULL\n";
		return -1;
	}

	for (int i = 0; i < line; i++)
	{
		arr[i] = new (std::nothrow) double[3];
		if (arr[i] == NULL)
		{
			std::cout << "MEMORY FULL\n";
			freeMemory(arr, i);
			return -1;
		}
		std::cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

    //***********ORDER LINE**************//
	SelectionSort(arr, line);
	//**********************************//
	for (int i = 0; i < line; i++)
	{
		std::cout << arr[i][0] << " " << arr[i][1] << " " << arr[i][2] << "\n";
	}
	freeMemory(arr, line);
	return 0;

}