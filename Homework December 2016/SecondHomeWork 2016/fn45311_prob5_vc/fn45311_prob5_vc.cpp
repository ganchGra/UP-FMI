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

#include<iostream>
#include<iomanip>

double acceleration = 0;

double intermediateDistance(const double time,const double measurements){

	double intermedDistance = acceleration * time + 0.5 * measurements * time * time;
	
	//********CALCULATE THE ACCELERATION**********//
	acceleration = acceleration + measurements * time;
	acceleration = (acceleration < 0) ? 0 : acceleration;

	return intermedDistance;
}

int main(){
	unsigned n;
	double time, measurements, distance = 0;
	std::cin >> n >> time;

	for (int i = 0; i < n; i++)
	{
		std::cin >> measurements;
		distance += intermediateDistance(time, measurements);
	}
	//**********TAKING FIVE NUMBER AFTER THE DECIMAL POINT**********//
	std::cout 
		<< std::fixed 
		<< std::setprecision(5) 
		<<std::setfill('0')
		<< std::setw(5)
		<< distance << "\n";

	return 0;
}

