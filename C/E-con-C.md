# C tricky question
1. `char` store -128 to +178, `unsigned char` stores from 0 to 255. suppose if we attempt to store +129 in `char` it will become -127...
2. switch cannot be used float, ex: case 6.5
3. If there is a nested scope in the program, local variable in that scope will be high priority, and its value will be utilized.
4. Value stored using the register storage class is accessed faster than other storage class, since it is stored in the CPU register. If the CPU register is full it place the value in the memory and variable works as if its storage class is auto
6. 16 Bit Microprocessor cannot hold Flot or Double in the CPU since it take large amount of memory (4byte and 18 byte), suppose you do so, you did not get any error it will work as a auto storage class
Static is always initialized with Zero. Its life ---> value of the variable presists between different function calls.