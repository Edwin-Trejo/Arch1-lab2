#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool delim_character(char c, char delim)
{
	if(c == delim) {
		return true;
	 }
	return false;
}

bool non_delim_character(char c, char delim)
{
	if(c != delim) {
		return true;
	 }
	return false;
}

char *world_start(char* str,char delim)
{
	while(delim_character(*str, delim))
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
