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

#include <iostream>
using namespace std;

//function for the 5 numbers
float roundF(float num) {
	float result;
	if (int(num) < 10)
	{
		result = (((float)((int)(num * 10000)) / 10000));
	}
	else if (int(num) < 100){
		result = (((float)((int)(num * 1000)) / 1000));
	}
	else if (int(num) < 1000){
		result = (((float)((int)(num * 100)) / 100));
	}
	else if (int(num) < 10000){
		result = (((float)((int)(num * 10)) / 10));
	}
	else if (int(num) >9999 && int(num) < 100000)
	{
		result = int(num);
	}

	return result;
}

int main()
{
	float a1, a2, b1, b2, c1, c2, x, y;

	cin >> a1 >> b1 >> c1 
		>> a2 >> b2 >> c2;
	a1 = roundF(a1);
	a2 = roundF(a2);
	b1 = roundF(b1);
	b2 = roundF(b2);
	c1 = roundF(c1);
	c2 = roundF(c2);

	if ((a1 == 0 && b1 == 0 && c1 != 0) || (a2 == 0 && b2 == 0 && c2 != 0)) {
		cout << "No solution\n";
		return 0;
	}
	//|a1*x + b1*y = c1
	//|a2*x + b2*y = c2
	
	
	x = roundF(b1*c2 - b2*c1) / roundF(b1*a2 - b2*a1);
	//y = roundF(roundF(c1 - (a1*roundF(x))) / b1);
	y = roundF(roundF(c2*a1 - a2*c1) / roundF(a1*b2 - a2*b1));
	
	if (roundF(b1*c2 - b2*c1) == 0 && roundF(b1*a2 - b2*a1) == 0)
	{
		cout << "Many solutions\n";
	}
	else if (roundF(b1*a2 - b2*a1) == 0){
		cout << "No solution\n";
	}
	else{ 
		cout << roundF(x) << " " << roundF(y) <<"\n";
	}
	
	return 0;
}