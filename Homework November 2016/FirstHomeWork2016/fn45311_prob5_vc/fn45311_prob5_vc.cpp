/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Gratsiela Gancheva
* @idnumber 45311
* @task 5
* @compiler VC
*
*/

#include <iostream>

using namespace std;

int main(){

	float x, y, u, v, xReal, yReal, diagonal;
	//rBig = 8 
	//rMed = 3
	//rSmall = 1

	float rBigSq = 64.001, rMedSq = 9.001, rSmallSq = 1.001;
	int point;

	cin >> x >> y >> u >> v;
	 
	xReal = x + u;
	yReal = y + v;

	diagonal = (xReal * xReal) + (yReal * yReal);
	if (diagonal == 64 || diagonal == 9 || diagonal == 1)
	{
		point = 0;
		cout << point << "\n";
		return 0;
	}
	else if (diagonal > rBigSq)
	{
		point = 0;
	}
	else if (diagonal < (rBigSq) && diagonal >(rMedSq))
	{
		point = 10;
	}
	else if (diagonal < (rMedSq) && diagonal >(rSmallSq))
	{
		point = 20;
	}
	else if (diagonal < (rSmallSq))
	{
		point = 60;
	} 
	cout << point << "\n";

	return 0;
}