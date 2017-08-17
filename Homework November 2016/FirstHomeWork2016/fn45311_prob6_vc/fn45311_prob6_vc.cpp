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

#include <iostream>

using namespace std;

int main(){	

	int Ax1, Ay1, Ah, Aw, Bx1, By1, Bh, Bw,
		Ax2, Ay2, Bx2, By2,
		result;

	cin >> Ax1 >> Ay1 >> Ah >> Aw
		>> Bx1 >> By1 >> Bh >> Bw;

	Ax2 = Ax1 + Aw;
	Ay2 = Ay1 + Ah;
	Bx2 = Bx1 + Bw;
	By2 = By1 + Bh;
	//A=B
	if (Ax1 == Bx1 && Ax2==Bx2 && Ay1 == By2)
	{
		result = (Ax2 - Ax1) * (Ay2 - Ay2);
	}
	//B is in the left side
	else if (Ax1 >= Bx1 && Ax2 >= Bx2)
	{
		if (Ay1 <= By1 && Ay2 <= By2){
			result = (Bx2 - Ax1)*(Ay2 - By1);
		}
		else if (Ay1 >= By1 && Ay2 >= By2)
		{
			result = (Bx2 - Ax1)*(By2 - Ay1);
		}
		else if (Ay1 <= By1 && Ay2 >= By2)
		{
			result = (Bx2 - Ax1) * (By2 - By1);
		}
		else if (Ay1 >= By1 && Ay2 <= By2)
		{
			result = (Bx2 - Ax1) * (By2 - By1);
		}
	}
	//A is in the left side
	else if (Ax1 <= Bx1 && Ax2 <= Bx2)
	{
		if (By1 <= Ay1 && By2 <= Ay2){
			result = (Ax2 - Bx1)*(By2 - Ay1);
		}
		else if (By1 >= Ay1 && By2 >= Ay2)
		{
			result = (Ax2 - Bx1)*(Ay2 - By1);
		}
		else if (By1 <= Ay1 && By2 >= Ay2)
		{
			result = (Ax2 - Bx1) * (Ay2 - Ay1);
		}
		else if (By1 >= Ay1 && By2 <= Ay2)
		{
			result = (Ax2 - Bx1) * (Ay2 - Ay1);
		}
	}
	//B is in the center
	else if (Ax1 <= Bx1 && Ax2 >= Bx2)
	{
		if (Ay1 <= By1 && Ay2 <= By2)
		{
			result = (Bx2 - Bx1) * (Ay2 - By1);
		}
		else if (Ay1 >= By1 && Ay2 >= By2)
		{
			result = (Bx2 - Bx1) * (By2 - Ay1);
		}
		else if (Ay1 <= By1 && Ay2 >= By2)
		{
			result = (Bx2 - Bx1) * (By2 - By1);
		}
		else if (Ay1 >= By1 && Ay2 <= By2)
		{
			result = (Bx2 - Bx1) * (Ay2 - Ay1);
		}
	}
	//A is in the center
	else if (Ax1 >= Bx1 && Ax2 <= Bx2)
	{
		if (By1 <= Ay1 && By2 <= Ay2)
		{
			result = (Ax2 - Ax1) * (By2 - Ay1);
		}
		else if (By1 >= Ay1 && By2 >= Ay2)
		{
			result = (Ax2 - Ax1) * (Ay2 - By1);
		}
		else if (By1 <= Ay1 && By2 >= Ay2)
		{
			result = (Ax2 - Ax1) * (Ay2 - Ay1);
		}
		else if (By1 >= Ay1 && By2 <= Ay2)
		{
			result = (Ax2 - Ax1) * (By2 - By1);
		}
	}

	if (result < 0)
	{
		result = 0;
	}
	cout << result << "\n";
	return 0;
}