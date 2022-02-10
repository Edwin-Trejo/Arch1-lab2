#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* If c is equal to the delimeter (delim) it will return true*/
bool delim_character(char c, char delim)
{
	if(c == delim) {
		return true;
	 }
	return false;
}

/* If c is not equal to the delimeter (delim) it will return true*/
bool non_delim_character(char c, char delim)
{
	if(c != delim) {
		return true;
	 }
	return false;
}

/* Uses a while loop and a pointer to traverse the string, the while loop will 
   continue until it finds a non delimeter char, then it returns the pointer 
   to that char  indicating the start of the string.*/
char *word_start(char* str,char delim)
{
	while(delim_character(*str, delim))
	 {
		str++;
	 }
//	printf("first char %c", *str);
	return str;
} 
/* Uses a while loop and a pointer to traverse the string, the while loop
   will continue until it finds a delimeter character, then it will
   return the pointer, indicating the end of a word*/
char *end_word(char* str, char delim)
{
	while(non_delim_character(*str, delim))
	 {
		str++;
	 }
	return str;
}

int count_tokens(char* str, char delim)
{
	if(str[1] == '\0'){return 0;}
	int count = 1;
	*str +=1;
	while(*str)
	{
		if(delim_character(*str, delim))
		 {
	    		count++;
			str++;
		 }
		else
	 	 {
			str++;
		 }
	}

	return count;
}

char *copy_str(char *inStr, short len, char delim)
{
	char *copy = (char*)malloc((len+1) * sizeof(char));

	for(int i = 0; i < len; i++)
	 {
		copy[i] = inStr[i];
	 }

	copy[len] = '\0';
	return copy;
}
/*
char** tokenize(char* str, char delim)
{
	
}
*/
void print_all_tokens(char** tokens)
{
}

int main()
{

	char delim[50];
	char str[50];
	//int *p = str;
	printf("Welcome! Select a delimeter char\n");
	fgets(delim,50,stdin);
	printf("Selected delimeter: %s", delim);
	printf("Enter the input string\n");
	fgets(str,50,stdin);
	printf("Input string: %s", str);
	
	//Testing
//        *word_start(str , *delim);
	
	printf("count: %d\n", count_tokens(str, *delim));

	return 0;
}
