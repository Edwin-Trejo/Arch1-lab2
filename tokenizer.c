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

/*This method first checks if the string is empty, if it is it returns 0, if
  its NOT empty it uses a while loop to go through the string looking for
  delim characters, if it finds one it adds one to the count, meaning a word
  ended there, therefore there is one more word to count.*/

int count_tokens(char* str, char delim)
{
	if(str[0] == '\0'){return 0;} //checks if string is empty
	int count = 1;
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
/*First it  allocates memory using malloc, it needs to know the lenght of the
  string in order to know how much memory will be needed. After that, it uses
  a for loop to copy each char of the string. Lastly it makes the last element
  the zero terminator. 
*/

char *copy_str(char *inStr, short len, char delim)
{
	char *copy = (char*)malloc((len+1) * sizeof(char));

	for(int i = 0; i < len; i++)
	 {
		copy[i] = inStr[i];
	 }

	copy[len] = '\0'; //zero terminator last element
	return copy;
}

char** tokenize(char* str, char delim)
{
	int words = count_tokens(str, delim);
	char **tokens = (char**)malloc((words + 1) * sizeof(char*));

	for(int i = 0; i < words; i++)
	 {
		char* start = word_start(str,delim); //start pointing to the start of the word
		str = end_word(start,delim); //str pointing to the end of the word

		tokens[i] = copy_str(start, str - start, delim); //start of the pointer, size of the word, delimeter
	 }
//	tokens[words] = '\0'; //last element zero terminator
	return tokens;
}

void print_all_tokens(char** tokens)
{
	int count = 0;
	char **temp = tokens;
	if(*tokens == 0)
	 {
		printf("String is empty\n");
	 }
	while(*temp)
	 {
		//printf("Tokens[%d]:",count);
		printf("%s\n", *temp);
		//count++;
	 	temp++;
	 }
}

int main()
{

	char delim[1] = {' '};
	char str[50];

//	printf("Welcome! Select a delimeter char\n");
//	fgets(delim,50,stdin);
//	printf("Selected delimeter: %s", delim);
	printf("Enter the input string\n");
	fgets(str,50,stdin);
//	printf("Input string: %s", str);

	//Testing
	
	print_all_tokens(tokenize(str,*delim));

	return 0;
}
