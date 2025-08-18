# Computer Architecture Essentials on ARM (Course from ARM via edx)
1. [ARM University edx Course](https://www.arm.com/resources/education/online-courses)
2. [Introduction to Computer Architecture Education kit](https://github.com/arm-university/Introduction-to-Computer-Architecture-Education-Kit?tab=readme-ov-file)

## Basic Computer Architecture?
#### Level of Abstraction
**Architecture**  
1. A set of specifications that allows developers to write software and firmware
2. These include the instruction set.
3. Instruction Set Architecture  

**Microarchitecture**  
1. The logical organization of the inner structure of the computer  

**Hardware or Implementation**  
1. The realization or the physical structure, i.e., logic design and chip packaging


**Instruction cycle**  
1. **Fetch** : fetch the instruction from memory
2. **Decode**: Decode the instruction
3. **Execute**: Execute the instruction

![Execution flow diagram](./img/AC_basicExecutionFlow.png)

ALU Means Arithmetic and logic Unit

Modern Microprocessor has nearly 1000 to 100billion transistor, which is operated on logic one and zero

![Microprocessor Transistor](./img/AC_transistor.png)

The transistor are used to Make Latch(single bit memory), Multiplexer, HalfAdder, etc...
![Basic Transistor Circuit](./img/AC_Transisotr_cir.png)
![Transistor Circuit Block](./img/AC_Transisotr_cir_block.png)


![Transistor Blocks](./img/AC_Block.png)

In order to synchronise all the blocks we use the `clock signal` to the processor. We measure it using the Hz.
The maximum speed of the clock signal is determined by the longest, and therefore slowest,
path in the circuit between 2 clocked flip-flops.
This is referred to as the "Critical Path."
The signal must have time to propagate all the way along the critical path
before the clock cycle completes.


#### Microprocessor Components
1. **ALU**:  A microprocessor needs to do many types of arithmetic. For this, we build an "Arithmetic Logic Unit" or "ALU." This circuit receives 2 numbers as input, as well as an indication of what operation to perform, for example, addition or subtraction. 
2. **Memory**: In addition to logic, a microprocessor needs memory. Memory is organized as arrays of memory cells that are able to store many "Words" of data.A specific word, commonly 32 bits in length, can be accessed by specifying its "Address." Each address is a number that indicates the location in the memory that should be read or written.
Memory cells range from hundreds of bits to millions of bits in size,
but larger ones are slower to access, as signals and their long internal wires take longer to propagate. For that reason, almost all microprocessors include at least two types for storing data:
    1. `Data Memory` : Big Slow Memory (In reality, the "Data Memory" may be implemented using many different sizes of memory,)
    2. `Register File`: Small and Fast Memory
    3. Apart from the above we need a memory to store the Instruction
3. **Program Counter**: A way to keep track of which instruction we will fetch next
4. **Instruction Decoder**: Since instructions are encoded in binary, we also have "Instruction Decode Logic", that converts that binary to the various signals needed to control the microprocessor.

#### How do you tell a Microprocessor what to do?

**Instructions**  

```ASM
ADD X1, X2, X3
```

```
ADD - Mnemonic
X1  - Output
X2, X3 - Operands
```
We use the assembler to encode the instruction in binary.


**ARM Instruction Set A64**

The A64 instruction set is used when executing in the AArch64 Execution state. It is a fixed-length 32-bit instruction set. The 64 in the name refers to the use of this instruction by the AArch64 Execution state. It does not refer to the size of the instructions in memory.

The A32 and T32 instruction sets are also referred to as Arm and Thumb, respectively. These instruction sets are used when executing in the AArch32 Execution state.

[A64 Instruction Set Link](https://developer.arm.com/documentation/102374/latest/)

##### Instructions

**Arithmetic Instructions**
```ASM
ADD X1, X2, X3           ; x1 = x2 + x3
MUL X0, X0, X4           ; x0 = x0 * x4
NEG X30, X20             ; x30 = -x20
AND X2, X1, X2           ; x2 = x1 & x2
ADD X5, X19, #4          ; x5 = x19 + 4
```
**Branch Instructions**  

Normally the microprocessor executes instructions in sequential order but branches change that, and explicitly tell the microprocessor the address of the instruction to run next.
This is done by giving the address of the next instruction in the instruction memory.

Always occur branches ex.: `B, BR, BL` and some branches are conditional branches ex.:`BNE`

```ASM
B   #1024                ; Branch to 1024
BNE #4                   ; Branch to 4 if "not equal" in CMP compare instruction
BEQ #7                   ; Branch to 7 if "equal" in CMP compare instruction
BLT #5                   ; Branch to 5 if "less than" in compare instruction
BR  X15                  ; Branch to X15
BL  #78                  ; Function call branch to 78
                         ;   (copies return addrss to X30)
```
The conditional instructions are preceded by the comparision instruction to calculate the condition ex.: 
```ASM
CMP X5, #6               ; compare x5 to 6`
BNE #4                   ; if the above is not ture branch to 4
```

**Load and Store Instruction**

1. Loads and stores are the instructions for accessing the data memory.
Loads copy values from memory to the register file. Stores do the opposite.  
2. In both cases, the instruction needs to know the address in the data memory
and the location in the register file to copy between.
3. For data memory, loads and stores read an address from a base register.

```ASM 
LDR X3,  [X4,X5]         ; Set X3 tp value of data memory addressed by value of X4 to X5
STR X17, [X5, #6]        ; Set data memory addressed by X5 + 6 to value of X17
```

**Example program to do GCD**   
Euclid's greatest common division algorithm in ARM A64 instrcution set

| ADDR | Instruction       | Description |
| ---- | -------------     |  ----------- |
| 0:   | CMP   X1, X2      | ; Compare X1 And X2 register inputs |
| 1:   | BEQ   #7          | ; If the above comparision is true got to address 7 |
| 2:   | BLT   #5          | ; Branch less than in the previous comparision of x1 and x2 |
| 3:   | SUB   X1, X1, X2  | ; x1 = x1 - x2 |
| 4:   | B     #0          | ; Branch to address 0 |
| 5:   | SUB   X2, X2, X1  | ; x2 = x2 - x1 |
| 6:   | B     #0          | ; Branch to address 0 |


##### **Registers in AArch64 General Purpose Register**  
Most A64 instructions operate on registers. The architecture provides 31 general purpose registers.
Each register can be used as a 64-bit X register (X0..X30), or as a 32-bit W register (W0..W30).
These are two separate ways of looking at the same register. For example, W0 is the bottom 32 bits of X0, and W1 is the bottom 32 bits of X1

```ASM
ADD W0, W1, W2     ; 32 bit addition
ADD X0, X1, X2     ; 64 bit addition
```

When a W register is written, as seen in the example above, the top 32 bits of the 64-bit register are zeroed.

There is a separate set of 32 registers used for floating point and vector operations. These registers are 128-bit, but like the general-purpose registers, can be accessed in several ways. Bx is 8 bits, Hx is 16 bits and so on (Sx is 32 bit, Dx is 64 bit) to Qx which is 128 bits.

```ASM
FADD S0, S1, S2      ; Floating point addition of 32 bit
FADD D0, D1, D2      ; Floating point addition of 64 bit
```
These registers can also be referred to as V registers. When the V form is used, the register is treated as being a vector. This means that it is treated as though it contains multiple independent values, instead of a single value. This example performs vector floating point addition:
```ASM
FADD V0.2D, V1.2D, V2.2D
```
This example performs vector integer addition:
```ASM
ADD V0.2D, V1.2D, V2.2D
```

## Pipelining
GK: **Pointer Authentication feature in ARM**: What this feature is trying to do is protect against a form of attack called ROP and JOP. These are Return Orientated and Jump Orientated Programming, and it's where an attacker tries to subvert things like the call stack to run legitimate code, but in ways that weren't expected by the programmer or the compiler.
PAC or Pointer Authentication tries to defend against this kind of attack by using part of an address to provide an encrypted signature. So we can check the signature and the address match and if they don't, we can spot an attack in progress. So why is this a trade-off? Well, because to add security, we want that signature to be as big as possible.
The bigger the signature, the more bits we use for that, the stronger cryptographically that signature is. The trade-off is: the more bits we use for the signature, the fewer bits we have available for other things, such as the address. So you can have a big signature with a small address, but if you want the address to get bigger, then you get a smaller signature, and that's then cryptographically weaker.
So the trade-off we have to make when designing a technology like that is: What's the right amount of bits for the signature? What's the strength of cryptography we need from that signature in order to get the design goal,


### The Processor Performance Equation

 let's find out how long a program takes to execute.  
```
Time taken per instruction = (Average clock cycles per instruction) x (Clock period)
```

```
Time taken per program = (Number of instructions in program) x (Average clock cycles per instruction) x (Clock period)
```

**From the above equation we can reduce the program time by:**  
1. Either Reduces the number of instructions (ex: loading the two values at the same time could reduce the instructions) (The downside to this approach, is that adding more instructions will require extra circuitry in the processor and therefore we likely increase the clock period. f the extra instructions are rarely used this could even mean an overall decrease in performance. We see this theme often in computer architecture trade-offs that we have to carefully balance.)
2. Either using the faster transistors (perhaps constructed from a more recent fabrication technology. This would reduce the clock period but may increase costs.)

The rest of this module focuses on an optimization to reduce the clock period called pipelining. This is the most important optimization we use when designing processors.

It uses a similar concept to an assembly line in a factory where work can start on the next item before the previous one finishes.

**Let's take a closer look.** Imagine that each instruction has to go through four circuits in a processor.  If we attempt to do all of these in one clock cycle this means our clock period is the latency of all four circuits added together. If we were to pipeline this, we would add a pipeline register in the middle. This divides the circuit into two sections called stages. Notice that although each instruction takes a similar amount of time to travel down the whole pipeline, the pipeline design can execute nearly twice as many instructions per second. The throughput has doubled. This is because we can set the clock period much shorter. It's now the maximum latency of the two stages. We can pipeline into many stages and this allows for much faster execution of programs. Unfortunately, though, pipelining a real microprocessor design is not quite as simple because the processor has various feedback signals and loops in the circuit.
