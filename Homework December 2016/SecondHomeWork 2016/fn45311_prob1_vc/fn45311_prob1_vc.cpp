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

#include <iostream>
#include <iomanip>

double distanceBetweenPoints(double x1, double y1, double x2, double y2){
	//***** ALL VARIABLES ************//
	double functionArg = 0;
	double result = 0;
	double slope = 0;
	double b = 0;

	double cross_x1, cross_x2;
	double cross_y1, cross_y2;

	bool flag_x1, flag_x2;
	bool flag_y1, flag_y2;

	double y, x;
	bool A = (x1 >= -5.01 && x1 <= 5.01 && y1 >= -2.01 && y1 <= 2.01);
	bool B = (x2 >= -5.01 && x2 <= 5.01 && y2 >= -2.01 && y2 <= 2.01);
	//************************************//

	//*********** CALCULATE INTERSECTION FOR ALL OTHER POINTS *******************//    
	slope = (y2 - y1) / (x2 - x1);
	if ((y2 - y1) == 0 || (x2 - x1) == 0)  
		slope = 0; 

	b = y2 - slope*x2;
	x = (slope == 0) ? 0 : ((2 - b) / slope);

	if (x < 5.01 && x > -5.01) {
		cross_x1 = x;
		flag_x1 = true;
	}
	else {
		flag_x1 = false;
	}
	x = (slope == 0) ? 0 : ((-2 - b) / slope);

	if (x < 5.01 && x > -5.01) {
		cross_x2 = x;
		flag_x2 = true;
	}
	else {
		flag_x2 = false;
	}

	y = slope * 5 + b;

	if (y > -2.01 && y < 2.01) {
		cross_y1 = y;
		flag_y1 = true;
	}
	else {
		flag_y1 = false;
	}

	y = slope*-5 + b;

	if (y > -2.01 && y < 2.01) {
		cross_y2 = y;
		flag_y2 = true;
	}
	else {
		flag_y2 = false;
	}
	//***********************************************//   

	// both are in
	if (A && B) {
		functionArg = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
		result = (((3.14 * functionArg) / 2.) + functionArg) / 2.;
		return result;
	}
	// both are out
	else if (!A && !B){
		return result = 0;
	}

	// A is in; B is out
	else if (A && !B){
		if (flag_x1) { x2 = cross_x1; y2 = 2; }
		else if (flag_x2) { x2 = cross_x2; y2 = -2; }
		else if (flag_y1) { x2 = 5; y2 = cross_y1; }
		else if (flag_y2) { x2 = -5; y2 = cross_y2; }
	}

	// B is in; A is out	
	else if (!A && B){
		if (flag_x1) { x1 = cross_x1; y1 = 2; }
		else if (flag_x2) { x1 = cross_x2; y1 = -2; }
		else if (flag_y1) { x1 = 5; y1 = cross_y1; }
		else if (flag_y2) { x1 = -5; y1 = cross_y2; }
	}

	//********* FINALE CALCULATIONS ***********//
	functionArg = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	result = (((3.14 * functionArg) / 2.) + functionArg) / 2.;

	return result;

	//****************************************//
}

int main(){
	int n;
	double x1, y1;
	double x2, y2;
	double totalDistance = 0.;

	std::cin >> n;
	if (n >= 1 && n < 2000000000)
	{
		std::cin >> x1 >> y1;

		for (int i = 1; i < n; i++)
		{
			std::cin >> x2 >> y2;
			totalDistance += distanceBetweenPoints(x1, y1, x2, y2);
			x1 = x2;
			y1 = y2;
		}
	}
	else{
		return 0;
	}
	std::cout << std::fixed << std::setprecision(3) << totalDistance << "\n";

	return 0;
}