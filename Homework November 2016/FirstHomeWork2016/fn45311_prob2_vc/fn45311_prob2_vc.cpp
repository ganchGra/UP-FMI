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

using namespace std;

int main()
{
	long long egn;
	cin >> egn;

	//How to chek if it is 10 numbers, without string?

	int chekNum = (egn % 10); 
	int genderNum = (egn % 100) / 10;
	int regionNum = (egn % 10000) / 100;
	int dateNum = (egn % 1000000) / 10000;
	int month = (egn % 100000000) / 1000000;
	int year = (egn / 100000000);

	if (year < 0  || month <= 0 && month > 52 || dateNum <= 0 && dateNum > 31)
	{
		cout << "Bad input data!\n";
		return 0;
	}
	//chek the last number
	//Position	1	2	3	4	5	6	7	8	9
	//	Weight	2	4	8	5	10	9	7	3	6
	int firstPos = (year / 10);
	int secondPos = (year % 10);
	int thirdPos = month / 10;
	int fourthPos = month % 10;
	int fifthPos = dateNum / 10;
	int sixthPos = dateNum % 10;
	int seventhPos = regionNum / 10;
	int eighthPos = regionNum % 10;
	int ninthPos = genderNum;
	
	int sumWeight = 
		(firstPos * 2) + (secondPos * 4) + (thirdPos * 8) +
		(fourthPos * 5) + (fifthPos * 10) + (sixthPos * 9) +
		(seventhPos * 7) + (eighthPos * 3) + (ninthPos * 6);

	int resultChekNumber = sumWeight % 11;
	if (resultChekNumber >= 10)
	{
		resultChekNumber = 0;
	}
	if (resultChekNumber != chekNum)
	{
		cout << "Bad input data!\n";
		return 0;
	}
	//when the year is between 1900 and 1999
	if (month >=1 && month <=12)
	{
		year = 1900 + year;
	}
	//when the year is between 1800 and 1899
	else if (month >= 21 && month <=22)
	{
		year = 1800 + year;
		month = month - 20;
	}
	//when the year is between 2000 and 2099

	else if (month >= 41 && month <=52)
	{
		year = 2000 + year;
		month = month - 40;
	}

	//gender chek
	char gender = 'F';
	if ((genderNum % 2) == 0)
	{
		gender = 'M';
	}

	//leap year 
	if (month == 2 && ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)))
	{
		month = 13; //february 29 days
	}

	//final output
	
	switch (month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (dateNum >= 1 && dateNum <= 31)
		{	
			if (dateNum >=1 && dateNum <=9 && month <=9)
			{
				cout << "0"<< dateNum << ".0"<< month << "." << year <<" "<< gender << "\n";
			}
			else if (dateNum > 9 && month <= 9)
			{
				cout << dateNum << ".0" << month << "." << year << " " << gender << "\n";
			}
			else if (dateNum >=1 && dateNum <=9 && month > 9)
			{
				cout << "0" << dateNum << "." << month << "." << year << " " << gender << "\n";

			}
			else
			{
				cout << dateNum << "." << month << "." << year << " " << gender << "\n";
			}
		}
		else
		{
			cout << "Bad input data!\n";
		}
		break;

	case 4: case 6: case 9: case 11:
		if (dateNum >= 1 && dateNum <= 30)
		{
			if (dateNum >= 1 && dateNum <= 9 && month <= 9)
			{
				cout << "0" << dateNum << ".0" << month << "." << year << " " << gender << "\n";
			}
			else if (dateNum > 9 && month <= 9)
			{
				cout << dateNum << ".0" << month << "." << year << " " << gender << "\n";
			}
			else if (dateNum >= 1 && dateNum <= 9 && month > 9)
			{
				cout << "0" << dateNum << "." << month << "." << year << " " << gender << "\n";

			}
			else
			{
				cout << dateNum << "." << month << "." << year << " " << gender << "\n";
			}
		}
		else
		{
			cout << "Bad input data!\n";
		}
		break;
	case 2:
		if (dateNum >= 1 && dateNum <= 28)
		{
			if (dateNum >= 1 && dateNum <= 9)
			{
				cout << "0" << dateNum << ".02." << year << " " << gender << "\n";
			}
			else
			{
				cout << dateNum << ".02." << year << " " << gender << "\n";
			}
		}
		else
		{
			cout << "Bad input data!\n";
		}
		break;
		
	case 13:
		if (dateNum >= 1 && dateNum <= 29)
		{
			if (dateNum >= 1 && dateNum <= 9)
			{
				cout << "0" << dateNum << ".02." << year << " " << gender << "\n";
			}
			else
			{
				cout << dateNum << ".02." << year << " " << gender << "\n";
			}
		}
		else
		{
			cout << "Bad input data!\n";
		}
		break;
	default:
		cout << "Bad input data!\n";
		break;
	}
	
	return 0;
}