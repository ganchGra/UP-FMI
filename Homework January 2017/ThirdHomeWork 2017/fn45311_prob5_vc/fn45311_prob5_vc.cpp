/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Gratsiela Gancheva
* @idcharnumber 45311
* @task 5
* @compiler VC
*
*/

#include<iostream>
//*******************ALL FUNCTION********************//
size_t textlen(const char *arr);
void splitText(const char * text, size_t len);
char TypeSystem(char * charnum, size_t size);
unsigned long long textValue(char * charnum, size_t size);
unsigned long long ConvertInDecimal(unsigned long long num, int system);
unsigned long long CalcPow(unsigned long long n, int power);
unsigned long long ConvertFromCharToNum(char * charnum, size_t size, unsigned StartPosition, unsigned powSize);
//***********************END*************************//

size_t textlen(const char *arr){
	size_t len = 0;
	while (arr[len])
	{
		len++;
	}
	return len;
}
void splitText(const char * text,size_t len){
	unsigned long long  value = 0;
	if (text[0] == '\0')
	{
		return;
	}
	char charnum[1000];
	size_t pos = 0;

	for (size_t i = 0; i <= len; i++)
	{
		if ((text[i] >= '0' && text[i] <= '9') ||
			(text[i] >= 'A' && text[i] <= 'F' ||
			text[i] == 'b' || text[i] == 'x'))
		{
			charnum[pos] = text[i];
			pos++;
		}
		else{
			charnum[pos] = '\0';
			if (charnum[0] !='\0')
			{
				value += textValue(charnum, pos);
			}
			pos = 0;
		}
	}
	std::cout<<value << "\n";
}

char TypeSystem(char * charnum, size_t size){
	if (charnum == NULL)
	{
		return 'E';
	}
	for (size_t i = 0; i < size; i++)
	{
		if (charnum[i] == '0' && charnum[i + 1] == 'b') //binary	
			return 'b';

		else if (charnum[i] == '0' && charnum[i + 1] == 'x') // hex
			return 'h';

		else if (charnum[i] == '0' && charnum[i + 1] != '0' &&
			(charnum[i + 1] != 'b' || charnum[i + 1] != 'x')) //oct
			return 'o';

		else if (charnum[i] == '0' && charnum[i + 1] == '0')
			continue;

		else
			return 'd';
	}
	return 'E';
}

unsigned long long CalcPow(unsigned long long n, int power){
	unsigned long long result = 1;
	for (int i = 0; i < power; i++)
	{
		result *= n;
	}
	return result;
}
unsigned long long ConvertInDecimal(unsigned long long num, int system){
	unsigned long long decimalNumber = 0;
	int cntpow = 0;
	int mask;
	while (num)
	{
		if (system == 16 && num >=10)
		{
			mask = num % 100;
			decimalNumber += mask * CalcPow(system, cntpow);
			num /= 100;
		}
		else{
			mask = num % 10;
			decimalNumber += mask * CalcPow(system, cntpow);
			num /= 10;
		}
		
		cntpow++;
	}
	return decimalNumber;
}
unsigned long long ConvertFromCharToNum(char * charnum, size_t size, unsigned StartPosition, unsigned powSize){
	unsigned long long num = 0;
	for (size_t i = StartPosition; i < size; i++)
	{
		num += (charnum[i] - '0')* CalcPow(10, powSize);
		powSize--;
	}
	return num;
}
unsigned long long textValue(char * charnum,size_t size){
	if (charnum == NULL)
	{
		return 0;
	}
	unsigned long long num = 0;
	char type = TypeSystem(charnum, size);
	unsigned startPosition = 0;
	unsigned powSize = size-1;

	switch (type)
	{
	case 'b':
		do
		{
			startPosition++;

		} while (charnum[startPosition] != 'b');
		startPosition++;
		powSize -= startPosition;
		num = ConvertFromCharToNum(charnum, size, startPosition, powSize);
		num = ConvertInDecimal(num, 2);
		break;
	case 'h':
		int hexnum;
		do
		{
			startPosition++;

		} while (charnum[startPosition] != 'x');
		startPosition++;
		powSize = 0;

		for (size_t i = size-1; i >= startPosition; i--)
		{
			if (charnum[i] >='A' && charnum[i] <= 'F')
			{
				num += (charnum[i] - 'A' + 10) * CalcPow(16,powSize);
				powSize++;
			}
			else{
				num += (charnum[i] - '0') * CalcPow(16, powSize);
				powSize++;
			}
		}
		break;
	case 'o':
		num = ConvertFromCharToNum(charnum, size, startPosition, powSize);
		num = ConvertInDecimal(num, 8);
		break;
	case 'd':
		num = ConvertFromCharToNum(charnum, size, startPosition, powSize);
		break;
	case 'E':
		return num;
	}
	
	return num;
}

int main(){
	char text[1000];
	std::cin.getline(text, 1000);
	size_t sizeText = textlen(text);
	splitText(text, sizeText);
	//std::cout << textValue(text, sizeText) << "\n";

	return 0;
}
