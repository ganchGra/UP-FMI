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

#include<iostream>

bool isNaturalNum(const unsigned n, unsigned pow, const unsigned m, const unsigned y){
	long long num = n;
	long long x = 1;
	while (pow > 1){
		if (pow % 2 == 1)
		{
			x = (x*num) % m;
			pow -= 1;
		}
		else{
			num = (num *num) % m;
			pow /= 2;
		}
	}
	num = (num * x) % m;
	bool isNatural = (num == y) ? true : false;
	
	return isNatural;
}
void naturalNum(const unsigned n,const unsigned m,const unsigned y){
	if (n == 0 || n >= 1000001 ||
		m <= 1 || m >= 100001 ||
		y == 0 || y > m )
	{
		return;
	}
	bool existNatNum = false;
	int count = 0;
	for (int i = 1; i <= m; i++)
	{
		existNatNum = isNaturalNum(i, n, m, y);
		if (existNatNum) count++;

		if (existNatNum && count > 1)
			std::cout<<" "<< i;
		else if (existNatNum && count ==1)
		std::cout << i;
		
	}

	if (count == 0)
		std::cout << "-1\n";
	else
		std::cout << "\n"; 

}

int main(){
	unsigned int n, m, y;
	std::cin >> n >> m >> y;
	naturalNum(n, m, y);

	return 0;
}

