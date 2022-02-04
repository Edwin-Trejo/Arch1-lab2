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
char *world_start(char* str,char delim)
{
	while(delim_character(*str, delim))
	 {
		str++;
	 }
	return str;
} 
/* Uses a while lo*/
char *end_word(char* str, char delim)
{
	while(non_delim_character(*str, delim))
	 {
		str++;
	 }
	return str;
}

int main()
{

	char delim[50];
	char str[50];
	printf("Welcome! Select a delimeter char\n");
	fgets(delim,50,stdin);
	printf("Selected delimeter: %s", delim);
	printf("Enter the input string\n");
	fgets(str,50,stdin);
	printf("Input string: %s", str);
	
	return 0;
}
