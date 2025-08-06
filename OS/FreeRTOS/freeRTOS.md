# FreeRTOS Learnings

[Digikey youtube Course](https://www.youtube.com/playlist?list=PLEBQazB0HUyQ4hAPU1cJED6t3DU0h34bz)
# Source
1. https://github.com/FreeRTOS/FreeRTOS
2. https://www.freertos.org/Documentation/02-Kernel/07-Books-and-manual/01-RTOS_book (while reading book version is 1.1.0) (This Book is great... Refer this side by side)


### Basic Defination
#### What is an RTOS?
Most operating systems appear to allow multiple programs to execute at the same time. This is called multi-tasking. In reality, each processor core can only be running a single thread of execution at any given point in time. A part of the operating system called the scheduler is responsible for deciding which program to run when, and provides the illusion of simultaneous execution by rapidly switching between each program.   

The type of an operating system is defined by how the scheduler decides which program to run when. For example, the scheduler used in a multi user operating system (such as Unix) will ensure each user gets a fair amount of the processing time. As another example, the scheduler in a desk top operating system (such as Windows) will try and ensure the computer remains responsive to its user. (Note: FreeRTOS is not a big operating system, nor is it designed to run on a desktop computer class processor, I use these examples purely because they are systems readers will be familiar with.)

**The scheduler in a Real Time Operating System is designed to provide a predictable (normally described as deterministic) execution pattern. This is particularly of interest to embedded systems as embedded systems often have real time requirements. A real time requirements is one that specifies that the embedded system must respond to a certain event within a strictly defined time (the deadline). A guarantee to meet real time requirements can only be made if the behaviour of the operating system's scheduler can be predicted (and is therefore deterministic).**

Traditional small real time schedulers, such as the scheduler used in FreeRTOS, achieve determinism by allowing the user to assign a priority to each thread of execution. The scheduler then uses the priority to know which thread of execution to run next. In FreeRTOS, a thread of execution is called a task.  



#### Definations
**Task**: set of program instructions loaded in memory  
**Thread**: unit of CPU utilization with its own program counter and stack  
**Process**: instance of a computer program


In FreeRTOS, the term Task is used to mean Thread some times.


### Directory Structure
```
FreeRTOS
│ │
│ ├─Source Contains the FreeRTOS kernel source files
│ │
│ └─Demo
Contains pre-configured and port specific FreeRTOS kernel demo
projects
│
FreeRTOS-Plus
│
├─Source
Contains source code for other FreeRTOS and ecosystem libraries
│
└─Demo
Contains demo projects for other FreeRTOS and ecosystem libraries
```

FreeRTOSConfig.h file the configuration file of the RTOS 

Do not explicitly include any other FreeRTOS header files—FreeRTOS.h
automatically includes FreeRTOSConfig.h

FreeRTOSConfig.h reference page [link](https://www.freertos.org/Documentation/02-Kernel/03-Supported-devices/02-Customization)


### Task
1. FreeRTOS Website Documentation [link](https://www.freertos.org/Documentation/02-Kernel/02-Kernel-features/01-Tasks-and-co-routines/01-Tasks-overview)
2. Step by Step Detailed Example [link](https://www.freertos.org/Documentation/02-Kernel/05-RTOS-implementation-tutorial/03-Detailed-example/01-Putting-it-all-together)


**Task Scheduling** [link](https://www.freertos.org/Documentation/02-Kernel/02-Kernel-features/01-Tasks-and-co-routines/04-Task-scheduling)
