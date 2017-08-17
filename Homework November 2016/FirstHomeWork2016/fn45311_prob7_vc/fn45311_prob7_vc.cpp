/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Gratsiela Gancheva
* @idnumber 45311
* @task 7
* @compiler VC
*
*/

#include <iostream>

using namespace std;

int main()
{
	float x, y,diagonal, rBig = 6, rMed = 3;
	float CsmallBlackX = 0, CsmallBlackY = 3, RsmallBlack = 1;
	float CsmallWhiteX = 0, CsmallWhiteY = -3, RsmallWhite = 1;

	cin >> x >> y;

	//small black
	if (x >= -1 && x <= 1 && y >= 2 && y <= 4)
	{
		diagonal = (CsmallBlackX - x)*(CsmallBlackX - x) + (CsmallBlackY - y)*(CsmallBlackY - y);
		if (diagonal > (RsmallBlack*RsmallBlack))
		{
			cout << "Good\n";
		}
		else if (diagonal < (RsmallBlack*RsmallBlack))
		{
			cout << "Evil\n";
		}
		else
		{
			cout << "Neutral\n";
		}
	}
	//small white
	else if (x >= -1 && x <= 1 && y >= -4 && y <= -2)
	{
		diagonal = (CsmallWhiteX - x)*(CsmallWhiteX - x) + (CsmallWhiteY - y)*(CsmallWhiteY - y);
		if (diagonal > (RsmallWhite*RsmallWhite))
		{
			cout << "Evil\n";
		}
		else if (diagonal < (RsmallWhite*RsmallWhite))
		{
			cout << "Good\n";
		}
		else
		{
			cout << "Neutral\n";
		}
	}
	//II quadrant
	else if (x >= -6 && x <= 0 && y >= 0 && y <= 6)
	{
		diagonal = (x*x) + (y*y);
		if (diagonal < (rBig*rBig))
		{
			cout << "Good\n";
		}
		else{
			cout << "Neutral\n";
		}
	}
	//IV quadrant
	else if (x >= 0 && x <= 6 && y >= -6 && y <= 0)
	{
		diagonal = (x*x) + (y*y);
		if (diagonal < (rBig*rBig))
		{
			cout << "Evil\n";
		}
		else{
			cout << "Neutral\n";
		}
	}
	//I quadrant
	else if (x >= 0 && x <= 6 && y >= 0 && y <= 6)
	{
		diagonal = (x - CsmallBlackX)*(x - CsmallBlackX) + (y - CsmallBlackY)*(y - CsmallBlackY);
		if (diagonal > (rMed*rMed))
		{
			cout << "Evil\n";
		}
		else if (diagonal < (rMed*rMed))
		{
			cout << "Good\n";
		}
		else
		{
			cout << "Neutral\n";
		}
	}
	//III quadrant
	else if (x >= -6 && x <= 0 && y >= -6 && y <= 0)
	{
		diagonal = (x - CsmallWhiteX)*(x - CsmallWhiteX) + (y - CsmallWhiteY)*(y - CsmallWhiteY);
		if (diagonal < (rMed*rMed))
		{
			cout << "Evil\n";
		}
		else if (diagonal > (rMed*rMed))
		{
			cout << "Good\n";
		}
		else
		{
			cout << "Neutral\n";
		}
	}
	else{
		cout << "Neutral\n";
	}
	return 0;
}