/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Gratsiela Gancheva
* @idnumber 45311
* @task 9
* @compiler VC
*
*/

#include<iostream>
//**********************-SORT PLANS-************************//
void SortPlans(unsigned ** plan, size_t size){
	unsigned tempCash, tempMin, tempMB, tempSms;

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (plan[i][0] < plan[j][0])
			{
				tempCash = plan[j][0];
				tempMin = plan[j][1];
				tempMB = plan[j][2];
				tempSms = plan[j][3];

				plan[j][0] = plan[i][0];
				plan[j][1] = plan[i][1];
				plan[j][2] = plan[i][2];
				plan[j][3] = plan[i][3];

				plan[i][0] = tempCash;
				plan[i][1] = tempMin;
				plan[i][2] = tempMB;
				plan[i][3] = tempSms;
			}
		}
	}
}
//**************************-END-***************************//

//*************************-PRINT-**************************//
void PrintPlans(unsigned ** plan, size_t numOfPlan){
	if (*plan == NULL)
		return;

	if (numOfPlan == 0)
	{
		std::cout << "No solution\n";
		return;
	}
	for (size_t i = 0; i < numOfPlan; i++)
	{
		std::cout << plan[i][0] << " " << plan[i][1] << " " << plan[i][2] << " " << plan[i][3] << "\n";
	}
}
//**************************-END-***************************//

//********-MOVING THE POSSIBLE PLAN on the top position-****//
size_t PossiblePlans(unsigned **plan,size_t NumPlans, 
	const unsigned min, const unsigned MB, const unsigned sms){
	if (*plan == NULL)
		return -1;
	size_t position = 0;
	for (size_t i = 0; i < NumPlans; i++)
	{
		if (plan[i][1] >= min && plan[i][2] >= MB && plan[i][3] >= sms){
			plan[position][0] = plan[i][0];
			plan[position][1] = plan[i][1];
			plan[position][2] = plan[i][2];
			plan[position][3] = plan[i][3];
			position++;
		}
	}
	
	for (size_t i = position; i < NumPlans; i++)
	{
		delete[] plan[i];
	}
	
	NumPlans = position;
	
	return NumPlans;
}
//************-END and RETURN REST LINE-********************//

//***************-DELETE DOUBLE DINAMIC ARRAY-**************//
void FreeMemory(unsigned ** arr, const size_t size){
	if (*arr==NULL)
		return;
	
	for (size_t i = 0; i < size; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
//**************************-END-***************************//

int main(){
	size_t N;

	std::cin >> N;
	if ( N >= 100000)
	{
		std::cout << "INVALID INPUT\n";
		return -1;
	}

	//***************CREATE DINAMIC DOUBLE array*********************//
	unsigned ** plans = new (std::nothrow) unsigned *[N];
	
	if (plans == NULL)
	{
		std::cout << "MEMORY FULL\n";
		return -1;
	}

	for (size_t i = 0; i < N; i++)
	{
		//******CREATE DINAMIC array****//
		plans[i] = new (std::nothrow) unsigned[4];
		if (plans[i] == NULL)
		{
			std::cout << "MEMORY FULL\n";
			FreeMemory(plans, i);
			return -1;
		}

		std::cin >> plans[i][0] >> plans[i][1] >> plans[i][2] >> plans[i][3];

		if (plans[i][0] > 1000 || plans[i][1] > 100000 || plans[i][2] > 100000 || plans[i][3] > 100000)
		{
			std::cout << "INVALID INPUT\n";
			FreeMemory(plans, i);
			return -1;
		}
	}
	//****************************END*******************************//

	//**********************GRANDMA INFO****************************//
	unsigned min, MB, sms;
	std::cin >> min >> MB >> sms;
	//***************************END*******************************//

	//---------------------CALC SOLUTION--------------------------//
	N = PossiblePlans(plans,N,min,MB,sms);
	SortPlans(plans, N);
	PrintPlans(plans, N);
	//-----------------------END--------------------------------//

	//***DELETE dinamic double array****//
	FreeMemory(plans, N);
	//*************END***************//

	return 0;
}