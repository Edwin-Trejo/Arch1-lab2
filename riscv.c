#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // malloc & free
#include <stdint.h> // use guaranteed 64-bit integers
#include "tokenizer.h" // Create header file and reference that
#include "memory.h" // built-in functions to read and write to a specific file
#include <string.h>

int32_t* reg; // Array of 32 32-bit registers

void init_regs();
bool interpret(char* instr);
void write_read_demo();
long int stringToInt(char* str);
//char** tokenize(char* str, const char delim);

/**
 * Initialize register array for usage.
 * Malloc space for each 32-bit register then initializes each register to 0.
 * Do not alter this function!
 */
void init_regs(){
	int reg_amount = 32;
	reg = malloc(reg_amount * sizeof(int32_t)); // 32 * 4 bytes
	for(int i = 0; i < 32; i++)
		reg[i] = i;
}



/**
 * Fill out this function and use it to read interpret user input to execute RV64 instructions.
 * You may expect that a single, properly formatted RISC-V instruction string will be passed
 * as a parameter to this function.
 */
bool interpret(char* instr){
//	const char delim[2] = " ";
	char* token = strtok(instr," "); 
	char* add = "ADD";
	char* addi = "ADDI";
	printf("reg3: %d\n",reg[3]);
	if(*token == *add){
		long int destination;
		long int data1;
		long int data2;
		printf("this is add: %s\n", token);
		token = strtok(NULL, " ");
		token++;
		printf("this is destination: %s\n", token);
		destination = stringToInt(token);

		token = strtok(NULL, " ");
		token++;
		printf("this is source: %s\n", token);
		data1 = stringToInt(token);

		token = strtok(NULL, " ");
		token++;
		printf("this is immediate: %s\n", token);
		data2 = stringToInt(token);
		
		printf("data1: %ld\n",data1);
		printf("data2: %ld\n",data2);
		long int result = reg[data1] + reg[data2];
		reg[destination] += result;
		printf("total sum: %ld",result);

		return true;

	}
	 else if(*token == *addi){
		long int destination;
		long int source;
		long int immediate;
		printf("this is addi: %s\n", token);

		token = strtok(NULL, " ");
		token++;
		printf("this is destination: %s\n", token);
		destination = stringToInt(token);

		token = strtok(NULL, " ");
		token++;
		printf("this is source: %s\n", token);
		source = stringToInt(token);

		//token = strtok(NULL, " ");
		token--;
		printf("this is immediate: %s\n", token);
		immediate = stringToInt(token);

		long int result = reg[source] + immediate;
		reg[destination] += result;

		return true;
	}

	if(*instr == 0)
	 {
		return false;
	 }
	return true;
}

long int stringToInt(char* str)
{
	long int num = 0;
	int i = 0;

	int sign = 1; //number sign, starts as positive
	if(str[0] == '-'){	//if the first char is a negative sign, then
		sign = -1;	//sign = -1;
		i++;		//move to the next char
	}

	while (str[i] && (str[i] >= '0' && str[i] <= '9')) //iterates until str == false, or char is a non number
	{
		num = num * 10 + (str[i] - '0'); //get numerical value with '0'
		i++;				//multiply num * 10 to shuffle digits left to update total
	}
	return num * sign; //multiply num by sign depending on its value -1(negative) or 1(positive)
}


/**
 * Simple demo program to show the usage of read_address() and write_address() found in memory.c
 * Before and after running this program, look at mem.txt to see how the values change.
 * Feel free to change "data_to_write" and "address" variables to see how these affect mem.txt
 * Use 0x before an int in C to hardcode it as text, but you may enter base 10 as you see fit.
 */
void write_read_demo(){
	int32_t data_to_write = 0xFFF; // equal to 4095
	int32_t address = 0x98; // equal to 152
	char* mem_file = "mem.txt";

	// Write 4095 (or "0000000 00000FFF") in the 20th address (address 152 == 0x98)
	int32_t write = write_address(data_to_write, address, mem_file);
	if(write == (int32_t) NULL)
		printf("ERROR: Unsucessful write to address %0X\n", 0x40);
	int32_t read = read_address(address, mem_file);

	printf("Read address %lu (0x%lX): %lu (0x%lX)\n", address, address, read, read); // %lu -> format as an long-unsigned
}

/**
 * Prints all 32 registers in column-format
 */
void print_regs(){
	int col_size = 10;
	for(int i = 0; i < 8; i++){
		printf("X%02i:%.*lld", i, col_size, (long long int) reg[i]);
		printf(" X%02i:%.*lld", i+8, col_size, (long long int) reg[i+8]);
		printf(" X%02i:%.*lld", i+16, col_size, (long long int) reg[i+16]);
		printf(" X%02i:%.*lld\n", i+24, col_size, (long long int) reg[i+24]);
	}
}

/**
 * Your code goes in the main
 *
 */
int main(){
	// Do not write any code between init_regs
	init_regs(); // DO NOT REMOVE THIS LINE

	print_regs();

	
	// Below is a sample program to a write-read. Overwrite this with your own code.
//	write_read_demo();

	printf(" RV32 Interpreter.\nType RV32 instructions. Use upper-case letters and space as a delimiter.\nEnter 'EOF' character to end program\n");


	char* instruction = malloc(1000 * sizeof(char));
	bool is_null = false;
	// fgets() returns null if EOF is reached.
	is_null = fgets(instruction, 1000, stdin) == NULL;
	while(!is_null){
		interpret(instruction);
		printf("\n");
		print_regs();
		printf("\n");

		is_null = fgets(instruction, 1000, stdin) == NULL;
	}

	printf("Good bye!\n");

	return 0;
}
