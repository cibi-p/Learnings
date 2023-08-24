# C tricky question
1. `char` store -128 to +178, `unsigned char` stores from 0 to 255. suppose if we attempt to store +129 in `char` it will become -127...
2. switch cannot be used float, ex: case 6.5
3. If there is a nested scope in the program, local variable in that scope will be high priority, and its value will be utilized.
4. Value stored using the register storage class is accessed faster than other storage class, since it is stored in the CPU register. If the CPU register is full it place the value in the memory and variable works as if its storage class is auto
6. 16 Bit Microprocessor cannot hold Flot or Double in the CPU since it take large amount of memory (4byte and 18 byte), suppose you do so, you did not get any error it will work as a auto storage class
7. Static is always initialized with Zero. Its life ---> value of the variable presists between different function calls.
8. Variables that are defined inside a function are normally creted in stack. for static variable, they are stored in a memory called Data Segment.
9. Use Register for only those variables that are being used very often in a program. ex: loop counters, which get used a number of times in a program.
10. use Extern variable viesly became it will take lot of memory.


## Formulas or tricks for exam problems

1. GrossSalary = BasicPay + DearnessAllowance + HRA
2. 1Kilometer =1000Meter
3. 1Meter = 100centimeter
4. 1inch = 2.54cm
5. 1feet =  12inch
6. centigrade = 5.0/9.0 *(farhenheit-32)
7. Area of rect. A=l*b
8. Perimeter =2l+2b
9. Area of circ. A=3.14*r*r
10. Circum. =2*3.14*r