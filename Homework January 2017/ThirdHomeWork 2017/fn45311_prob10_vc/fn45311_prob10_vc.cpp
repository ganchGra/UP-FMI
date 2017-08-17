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
//TODO
#include<iostream>
bool isValidTable(char table[5][5]){
	int letter[25] = { 0 };
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			int poslett = table[i][j] - 'A';
			letter[poslett]++;
		}
	}
	for (size_t i = 0; i < 25; i++)
	{
		if (letter[i] > 1)
			return false;
		
	}
	return true;
}

int main(){
	char table[5][5];
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			std::cin >> table[i][j];
		}
	}
	char text[10000];
	std::cin.getline(text,10000);
	if (isValidTable(table) == false)
	{
		std::cout << "Bad table!\n";
		return 0;
	}
	return 0;
}