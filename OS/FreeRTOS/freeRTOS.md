# FreeRTOS Learnings

[Digikey youtube Course](https://www.youtube.com/playlist?list=PLEBQazB0HUyQ4hAPU1cJED6t3DU0h34bz)
# Source
1. https://github.com/FreeRTOS/FreeRTOS
2. https://www.freertos.org/Documentation/02-Kernel/07-Books-and-manual/01-RTOS_book (while reading book version is 1.1.0) (This Book is great... Refer this side by side)


### Basic Defination
**Task**: set of program instructions loaded in memory  
**Thread**: unit of CPU utilization with its own program counter and stack
Process: instance of a computer program


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
