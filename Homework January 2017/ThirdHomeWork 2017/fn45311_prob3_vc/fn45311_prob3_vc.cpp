/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Gratsiela Gancheva
* @idnumber 45311
* @task 3
* @compiler VC
*
*/

#include<iostream>
short textlen(const char *arr){
	short len = 0;
	while (arr[len])
	{
		len++;
	}
	return len;
}

void ShiftRight(char* pArr, short size){
	short write = size-1;
	short read = size - 2;;
	while (size > 0 )
	{
		pArr[write--] = pArr[read--];
		size--;
	}
}
void PrintPuns(char * word, unsigned pass, short wordlen){
	if ((word[0] >= 'a' && word[0] <= 'z') ||
		(word[0] >= 'A' && word[0] <= 'Z')){
		for (int i = 0; i < pass; i++)
		{
			char letter = word[wordlen - 1];
			ShiftRight(word, wordlen);
			word[0] = letter;
		}
		std::cout << word;
	}
	

}

//*******************SPLIT TEXT**********************//
void splitText(const char * text, const unsigned pass){
	
	if (text[0] == '\0')
	{
		return;
	}
	char word[10000];
	int pos = 0;
	short len = textlen(text);

	for (short i = 0; i <= len; i++)
	{
		if ((text[i] >= 'a' && text[i] <= 'z') ||
			(text[i] >= 'A' && text[i] <= 'Z'))
		{	
				word[pos] = text[i];
				pos++;
		}
		else if ((pos > 0 && text[i] == '-') &&
				((word[i - 1] >= 'a' && word[i - 1] <= 'z') ||
				(word[i - 1] >= 'A' && word[i - 1] <= 'Z')) && 
				((text[i + 1] >= 'a' && text[i + 1] <= 'z') ||
				(text[i + 1] >= 'A' && text[i + 1] <= 'Z' )))
			{
				word[pos] = text[i];
				pos++;
			}
		else{
			word[pos] = '\0';

			PrintPuns(word, pass,pos);
			pos = 0;
			if (text[i] != '\0')
			{
				std::cout << text[i];
			}
		}
	}
	std::cout << "\n";
}
//***************************************************//
int main(){
	char text[10000];
	unsigned pass;
	std::cin.getline(text, 10000);
	std::cin >> pass;
	splitText(text, pass);
	return 0;
}