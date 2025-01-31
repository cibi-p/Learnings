# GPU Architectures and programming - Prof soumayjit Dey
(  
    while reading thise read along with
        IIT khargpur book;  
        Computer Arhitecture a quantative analysis book;  
)  

course link: https://www.youtube.com/playlist?list=PLbRMhDVUMngfj_NXI7jqMYLnhcRhRKAGq 

IIT khargpur book: https://drive.google.com/file/d/11_cmuSzpdXhdx1mvtHBGQvOwyaZ_Px0H/view 

NPTEL link: https://nptel.ac.in/courses/106105220 

Computer Arhitecture a quantative analysis book: https://acs.pub.ro/~cpop/SMPA/Computer%20Architecture%20A%20Quantitative%20Approach%20(5th%20edition).pdf 

Reference

[Nvidia Geforce 8800 Architecture link]: https://www.nvidia.co.uk/content/PDF/Geforce_8800/GeForce_8800_GPU_Architecture_Technical_Brief.pdf 

[other cibi found Nvidia Ampere GPU (for embedded platform) architecture]: https://www.nvidia.com/content/PDF/nvidia-ampere-ga-102-gpu-architecture-whitepaper-v2.pdf

## Introduction

1. Fifteen years ago, graphics on a PC were performed by a video graphics array controller.
2. VGAs evolved to more complex hardwares: accelerating Graphics functions
3. Early GPUS and their associated drivers implemented the OpenGL and DirectX models (APIS) of graphics processing
4. With the time, HW functionality evolved as programmable
5. GPU seen with the more usecase called GPGPU's

![VGA](./img/VGA_GPU_intro.png)

## Review of Basic COA w.r.t performance

**BASIC RISC Architecture**
1. The operation of a processor is characterized by a fetch decode execute cycle.
2. RISC CISC two different philosophies of computing hardware design. 
3. RISC/CISC-Reduced/Complex Instruction Set.
4. Computing CISC approach-complete a task with as few instructions (instrs) as possible
5. A CISC instruction: MUL addr, addry addry 
6. Equivalent RISC LOAD R2 addiy; LOAD 83 addry; MUL R1 R2 R3; STORE addy RI

**CISC vs RISC**
![CISC_vs_RISC](https://microcontrollerslab.com/wp-content/uploads/2019/08/RISC-vs-CISC.png)

**Elementardy CPU Datapath**

![CPU Data path diagram](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQm5z9nVhWo6dvnoKMR7ript5IsahMGCf23Ig&s)

in CISC, some instraction can execute and lower time, while other takes large time, we can't warry the clock, so we are forced to give the clock with works with give enough time form larger execution instruction also. ( to do so in the case of smaler execution instruction we are wasting the time by using the lower frequency clock)

suppose if we divide the single larger instruction into multiple we can able to increase the clock frequency. It will increase the performance

**execution cycle**
( please find the more instruction in the NPTEL provied book given in starting of this page, below overview only explained )

![Multi-cycle datapath architecture](https://slideplayer.com/slide/14759970/90/images/3/Multicycle+Datapath+Basic+multicycle+MIPS+datapath+handles+R-type+instructions+and+load%2Fstores%3A.jpg)

![multi-cycle cpu instruction timing diagram](https://d2vlcm61l7u1fs.cloudfront.net/media%2F993%2F993ffaca-897a-4cbf-b6e0-e5792bf21f59%2FphpeHlEH9.png) 

MIPS Architecture:  
MIPS (Microprocessor without Interlocked Pipelined Stages) is a family of reduced instruction set computer (RISC) instruction set architectures (ISA) developed by MIPS Computer Systems, now MIPS Technologies, based in the United States. MIPS

![MIPS Architecture](https://upload.wikimedia.org/wikipedia/commons/thumb/e/ea/MIPS_Architecture_%28Pipelined%29.svg/800px-MIPS_Architecture_%28Pipelined%29.svg.png)

in the above image data access means memory


### Hazard
* Structural Hazard
    - Consider a sequence of 4 lw (load-word) instructions 
    - When the first instruction fetches data from memory, the fourth instruction itself is to be fetched from memory 
    - This is structural hazard as the pipeline needs to stall due to lack of resources, if the hardware cannot support multiple reads in parallel
* Data Hazard
    - sub $2, $1, $3; and $12, $2, $5 Read after Write (RAW) 
    - if 'sub' is in IF stage in i + 1-th clock cycle, $2 is updated in (i + 5)-th cycle
    - 'and' is in EX stage in i + 4-th cycle, updated value of $2 is not yet ready 
    - Solution: 'sub' computes the value for $2 in (i + 3)-th stage, 
    - this may be forwarded directly to execution of 'and' 
    - need suitable logic to detect hazard and forwarding requirement
* Control Hazard
    - Branch decisions: the branch condition needs evaluation (beq $1, $2, offset) 
    - The branch decision is inferred only in MEM stage 
    - Optimization assume branch not taken, operate pipeline normally, 
    - Execute branch when decision is evaluated as true (taken) and flush intermediate instructions from pipeline 
    - Sophisticated schemes use branch prediction HW (predict a branch decision based on branch history table content)

### The Memory Hierarchy
```
CPU -> CACHE -> PRIMARY MEMORY -> SECONDARY MEMORY

---------------> Cost decreases, memory increases
```

#### Cache Mapping  

Cache mapping refers to the technique used to determine how data is stored and retrieved in cache memory. It establishes the mapping between memory addresses and cache locations

**Principle of locality** 

* Temporal locality: If an item is referenced, it will tend to be referenced again soon
* Spatial locality: If an item is referenced, items at nearby addresses will be referenced soon 
* Hence, computer memory is hierarchically organized 
* Register file provides fastest access, 
* Cache memory uses (fast) SRAM (static random access memory) 
* Main memory uses (slow) DRAM (dynamic random access memory): is less costly per bit than SRA

**Direct Cache-memory mapping**  
![Direct Mapping](https://edurev.gumlet.io/ApplicationImages/Temp/02ba00c8-69c3-4b76-9884-cc4eb813216d_lg.jpg?w=360&dpr=2.6)

actually it caculated the which location to load to chache using modulo operation in direct mapping.

![more on direct mapping](https://www.baeldung.com/cs/cache-direct-mapping)

**CACHE Blocks**
* With larger blocks we have lower miss rates due to spatial locality, large blocks lead to large miss penalty I 
* Nothing is free with very big block sizes, we have too small no of blocks in cache, eventually the miss rate goes up
* Handling Cache Miss: 
* Send the PC value (current PC-4) to the memory 
* Read access from main memory, write updated cache entry

**Cache write policy**

* Handling consistency: always write the data into both the memory and the cache (write-through) 
* Conservative policy, slows things down 
* Use write buffer to perform writes only when buffer is full. Buffer size can be decided by memory speed 
* Alternative policy write-back: Writes are updated only in cache. Main memory is update only during cache block replacement 
* Write-back offers better performance in case of frequent writes, is more complex to implement

**Memory System**
* Memory chips are designed to read/write more than one word in parallel (hiding latency) 
* Use a wide bus allow parallel access to all words in a block 
* OR - keep bus of standard width (= memory word length = register size) and connect bus with multiple memory units in parallel (memory banks) 
* WHY? bus transmission is fast, memory read/write is slow

**Cache Mapping : Alterating Maping**
* `Fully associative`: a block can be placed in any location in the cache. (Large HW requirement for fast parallel search) 
* Practical only for cache with small number of blocks 
* Optimizing in the middle: `set associative cache` 
* An n-way set-associative cache consists of a number of sets, each of which consists of n blocks. 
* Set number = (Memory Block number) modulo (Number of sets in the cache) 
* Inside a set, all the tags of all the elements must be searched 
* Increasing associativity decreases miss rate up to a point, but increases hit time

**CACHE REPLACEMENT POLICY**

* In direct mapped cache, a new block can go to exactly one location 
* In fully associative cache, a new block can potentially replace any existing block - how to resolve ? 
* In set associative cache, a new block can potentially replace any existing block inside a matching set - how to resolve ? 
* Least Recently Used (LRU) policy The block replaced is the one that has been unused for the longest time. 

## INSTRUCTION LEVEL PARALLELISIM

### Actual Pipeline CPI ( Cycles Per Instruction 
Pipeline Cycles per instruction (CPI) = Ideal pipeline CPI + Structural stalls + Data hazard stalls + Control stalls 
* Handling hazards require both architectural and compiler techniques
* Data hazard types while executing instruction i followed by j in a pipeline 
    * RAW ( Read After Write ) - j tries to read a source before i writes it, so j incorrectly gets the old value 
    * WAW (Write After Write)  - j tries to write an operand before it is written by i. Will not happen in simple RISC, but in pipelines that write in more than one basic stage or allow an instruction to proceed even when a previous instruction is stalled 
    * WAR (Write After Read) - j tries to write a destination before it is read by i, can happen in case instructions are reordered 
    * RAR not a hazard)

### Compiler Techniques for ILP ( INSTRCTION LEVEL PARALLELIAIM )

need to add for loop optimzation by compiler,...

To keep a pipeline full, a compiler can find sequences of unrelated instructions that can be overlapped 
```c
for (i=100; 1>=0; i=1-1) 
   x[i] = x[i] + s;
```

 Unoptimized MIPs 
 ```c
 Loop: L.D F0,0(R1); FO=array element
 ADD.D F4,F0, F2; add scalar in F2 
 S.D F4,0(R1); store result 
 DADDUI R1, R1, #-8; decrement pointer //loop overhead ;8 bytes (per DW) 
 BNE R1, R2, Loop; branch R1!-R2//branch decision
```

Unrolling: eliminated three branches and decrements of R1 (Hen Pat etl. al.) 
```c
Loop: L.D F0,0(R1) 
ADD.D F4,F0, F2 
S.D F4,0(R1) 
L.D F6,-8(R1) 
ADD.D F8,F6,F2 
S.D F8,-8(R1) //Code size increase more instr cache miss 
L.D F10,-16(R1) //more no. of live values increased register pressure 
ADD.D F12, F10,F2 
S.D F12,-16(R1) 
L.D F14,-24(R1) 
ADD.D F16, F14, F2 
S.D F16,-24(R1) 
DADDUI R1, R1, #-32 
BNE R1, R2, Loop
```

Advantage it avoids the unneccessary use of the last 2 instruction for multiple times

disadvantage of above, if for loop has branch instruction it this optimization will not work in that case and it uses more registers



#### Branch Prediction and ILP
It is perdict wheter the branch are going to happen or not, based on previous branching condition,... Based on that it may load the instruction ( on my understanding )


![2 bit branch pridictor](https://www.researchgate.net/publication/221340182/figure/fig1/AS:670012062842887@1536754732340/Saturating-two-bit-predictor-counter.png)
2-bit branch pridictor image

**Hierarchical predictiion**

How about generalizing the idea of prediction with larger branch histories. 
* store m length history of a branch - 2 possibilities 
* for each possibility use an n-bit predictor (m, n) prediction scheme 
* a two-level predictor with m-bit history can predict any repetitive sequence with any period if all m-bit sub-sequences are different.

Branch prediction example : https://www.geeksforgeeks.org/correlating-branch-prediction/ 

more types branch prediction: https://www.cs.umd.edu/~meesh/411/CA-online/chapter/dynamic-branch-prediction/index.html


### Dynamic Scheduling for ILP

Simple pipelines execute instructions in-order

```c
 DIV.D F0, F2,F4 
 ADD.D F10, F0,F8 
 SUB.D F12, F8,F14 
 ```
 * SUB.D suffers as ADD.D stalls due to dependence 
 * different ordering will avoid stall in this case 
 * Out of order execution brings in the possibility of WAR and WAW hazards 
Robert Tomasulo: developed algorithm to minimize WAW and WAR hazards while allowing out of order execution (tracks when operands for instructions are available to minimize RAW hazards and uses register renaming to minimize WAW and WAR )

#### Register Renaming

before renaming 
```c
DIV F0, F2, F4 
ADD F6,F0,F8 //(RAW for DIV: FO) 
S F6,0(R1) //(RAW for ADD: F6) 
SUB F8, F10, F14 //(WAR for ADD F8) 
MUL F6, F10, F8 // (WAR for S, WAW for ADD) //(RAW for SUB: F8)
```

after renaming
```c
DIV F0, F2, F4 A
DD S, F0, F8 
S S,0(R1) 
SUB T, F10, F14 
MUL F6, F10, T
```

* RAW is due to data dependency, stalls in-order pipeline 
* WAR/WAW constrains out-of-order execution
* S removes WAR of MUL, 
* S removes WAW of MUL,
* T removes WAR of SUB,

### ILP USING MUTIPLE AND SCHEDULING

Multiple-issue processors allow multiple instructions to be issued in a clock cycle 

► VLIW (very long instruction word) - Parallel instructions statically scheduled by compiler; issue a fixed number of instructions formatted as one large instruction  
► Statically scheduled superscalar issue a varying rather than a fixed number of instructions (compiler decided) per clock, in-order execution  
► Dynamically scheduled superscalar issue a varying rather than a fixed number of instructions (hardware decided) per clock, out-of-order execution For large issue width VLIW (with multiple independent FUs) is preferred w.r.t statically scheduled superscalar


## Intro to GPU architectures

[ kindly refer computer organisatio book chapter 4 for more info, link given in start of this page]

Handling Data Level Parallelism 1 Data parallel algorithms handle multiple data points in each basic step (single thread of control) 
► Vector Processors: early style of data parallel compute   
► Single Instruction Multiple Data (SIMD) in x86: MMX (Multimedia Extensions), AVX (Advanced Vector Extensions)   
► GPUs: have their own distinguishing characteristics


{Thought about vector processor, example Y=aX+Y, GPU architecture}

![Gefore 8800 architecture](https://tatourian.blog/wp-content/uploads/2013/09/image_thumb32.png?w=698&h=438) 

( for more refere reference in above )

##### kindly refer GPU inter lecture 2 in the NPTEL lecture Notes.

