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
   continue until it finds the next delimeter, then it returns the pointer 
   to that delimeter indicating the start of the next string.*/
char *word_start(char* str,char delim)
{
	while(delim_character(*str, delim))
	 {
		str++;
	 }
	return str;
} 
/* Uses a while loop and a pointer to traverse the string, the while loop
   will continue until it finds a non delimeter character, then it will
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
	int count = 0;
	while(*str)
	 {
	  if(*word_start(str, delim) )
		{
		 count++;
		}
	  *str++;
	 }
	return count;
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
       // printf("%d\n",*word_start(str , *delim));
	
	printf("%d\n", count_tokens(str, *delim));	

	return 0;
}
