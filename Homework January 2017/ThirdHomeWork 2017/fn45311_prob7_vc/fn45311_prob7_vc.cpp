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
//****************ALL FUNCTION******************//
void splitText(const char * text);
size_t textlen(const char *arr);
char touppercase(char symbol);
char tolowercase(char symbol);
bool isvowel(const char letter);
void ShiftLeft(char* pArr, size_t StartFrom, size_t Positions);
void printPigWord(char * word);
void  strCat(char* str1, const char* str2);
void ConvertConsonants(char *word);
//*********************************************//

size_t textlen(const char *arr){
	size_t len = 0;
	while (arr[len])
	{
		len++;
	}
	return len;
}
char touppercase(char symbol){
	if (symbol >='a' && symbol <='z')
	{
		symbol = symbol - ('a' - 'A');
	}
	return symbol;
}
char tolowercase(char symbol){
	if (symbol >= 'A' && symbol <= 'Z')
	{
		symbol = symbol - ('A' - 'a');
	}
	return symbol;
}
bool isvowel(const char letter){
	if (letter == 'a' || letter == 'A' || letter == 'o' ||
		letter == 'O' || letter == 'e' || letter == 'E' || letter == 'y' ||
		letter == 'Y' || letter == 'i' || letter == 'I' || letter == 'u' ||
		letter == 'U')
	{
		return true;
	}
	return false;
}
void ShiftLeft(char* pArr, size_t StartFrom, size_t Positions){
	size_t Size = textlen(pArr);
	size_t write = StartFrom;
	size_t read = StartFrom + Positions;
	while (read < Size)
	{
		pArr[write++] = pArr[read++];
	}
	pArr[write] = '\0';
}
void  strCat(char* str1, const char* str2){
	while (*str1)
	{
		str1++;
	}
	while (*str1 = *str2){
		str1++, str2++;
	}
}
void ConvertConsonants(char *word){
	if (word[0] =='\0')
	{
		return;
	}
	char arr1[10000];
	arr1[0] = word[0];
	int i;
	for (i = 1; word[i] != '\0'; i++)
	{
		if (!isvowel(word[i]))
		{
			arr1[i] = word[i];
		}
		else{
			arr1[i] = '\0';
			break;
		}
	}
	ShiftLeft(word, 0, i);
	strCat(word, arr1);
}
bool isALLUpperCase(const char *word){
	if (word[0] == '\0')
	{
		return -1;
	}
	size_t size = textlen(word);
	bool isUpper = true;
	for (size_t i = 0; i < size; i++)
	{
		if (word[i] >='a' && word[i] <='z')
		{
			return false;
		}
	}
	return isUpper;
}
void printPigWord(char * word){
	size_t sizeArr = textlen(word);
	if (word[0] == '\0')
		return;
	
	if (isALLUpperCase(word) && sizeArr > 1)
	{
		if (isvowel(word[0]))
		{
			strCat(word, "WAY");
		}
		else{
			ConvertConsonants(word);
			strCat(word, "AY");
		}
	}
	else{
		if (isvowel(word[0]))
		{
			strCat(word, "way");
		}
		else{
			if (word[0] >= 'A' && word[0] <= 'Z')
			{
				word[0] = tolowercase(word[0]);
				ConvertConsonants(word);
				strCat(word, "ay");
				word[0] = touppercase(word[0]);
			}
			else{
				ConvertConsonants(word);
				strCat(word, "ay");
			}
		}
	}
	
	std::cout << word;
}

//**************SPLIT TEXT****************//
void splitText(const char * text){
	if (text[0]=='\0')
	{
		return;
	}
	char word[10000];
	size_t pos = 0;
	size_t len = textlen(text);

	for (size_t i = 0;i <= len ; i++)
	{
		if ((text[i] >= 'a' && text[i] <= 'z') || 
			(text[i] >= 'A' && text[i] <= 'Z'))
		{
			word[pos] = text[i];
			pos++;
		}
		else{
			word[pos] = '\0';
			printPigWord(word);
			pos = 0;
			if (text[i] != '\0')
			{
				std::cout << text[i];
			}
		}
	}
	std::cout << "\n";
}
//**********************************************//
int main(){

	char text[10000];
	std::cin.getline(text, 10000);
	splitText(text);

	return 0;
}