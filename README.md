# Arch1-lab2

### 32-bit RISC-V interpreter in C
This interpreter receives, parses and executes RISC-V instructions as strings by reading the string, interpreting the instruction and then executing the given command, and if needed, storing the data in the memory.

This interpreter works using and Oracle VM which uses Linux operating system.
Is able to read and execute Arithmetic commands such as Add and Add immediate.

#### Tokenize the string
The first step is to tokenize the provided string, if we have a string such as " ADDI X6 X0 9 " we would need to tokenize it and have 4 different tokens such as "ADD", "X6", "X0", "9".
Then we can begin to read each token, and from there know what the next step is:

#### Find needed instruction: ADDI-Add Immediate
In this case, the first token is ADDI, which is the instruction of Adding Immediate

#### Find destination register X6
The next token will tell us where are we storing the values, in this case X6 is the destination register.

#### Find the source register x0
The next token is X0, which is the source register in this case

#### Add immediate
Lastly, we add the immediate which in this case is 9

Finaly, the destination register X6 will be updated with the data of X0 plus the immediate 9.
