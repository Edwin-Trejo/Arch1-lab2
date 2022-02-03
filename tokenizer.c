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


        
int main()
{

	char delim[50];
	printf("Welcome! Select a delimeter\n");
	fgets(delim,50,stdin);
	printf("Selected delimeter: %s", delim);

	return 0;
}
