# Assembly and architectures

# Resources
1. https://cs.lmu.edu/~ray/notes/x86overview/
2. https://hackaday.io/course/172292/logs
3. [Introduction to 64Bit Intel Assembly Language Programming for Linux](http://library.bagrintsev.me/ASM/Introduction%20to%2064bit%20Intel%20Assembly%20Language%20Programming%20for%20Linux.2011.pdf) - (Book, Great)

# Linux Assembly 
Note: from book `Introduction to 64Bit Intel Assembly Language Programming` 

The below program executed in the Linux, which exit with the status return value 5.

  ```ASM
; Program : exit
; Exe cutes the exit system call
; No input
; Output : only the exit status ($? in the shell)
;
segment . t ext
global _start
_start :
mov eax,1             ; 1 is the exit syscall number
mov ebx,5             ; the status value to return
int 0x80              ; execute a system call
```

Assembling and linking

```sh
# -g dwarf2 is for debugging, -l exit.lst is to see the generated hexa decimal file
yasm -f elf64 -g dwarf2 -1 exit.lst exit.asm 
ld -o exit exit.o
gcc -o exit exit.o

# to Run the program
./exit

# to check the return status
echo $?
```

Example output of the .lst file
```sh 
     1                                 %line 1+1 test.asm
     2                                 
     3                                 
     4                                 
     5                                 
     6                                 
     7                                 [segment .text]
     8                                 [global _start]
     9                                 _start :
    10 00000000 B801000000             mov eax,1
    11 00000005 BB05000000             mov ebx,5
    12 0000000A CD80                   int 0x80
    13                                 
    14                                 
```

Note: i have change the _start to main, it will linked using with ld as below 
```
❯ ld -o test2 test.o 
ld: warning: cannot find entry symbol _start; defaulting to 0000000000401000
```

in gcc it is compiling
```sh 
gcc -o test3 test.o
```

but size of the binary compiled using the gcc is more ( gcc is not compiling the _start )

```
-rwxrwxr-x 1 hari hari     5168 Aug  1 08:14 test2* (linked using ld)
-rwxrwxr-x 1 hari hari    16304 Aug  1 08:24 test3* (linked using gcc)
```

## Memory mapping
1. The hardware mapping registers on an x86-64 CPU can map pages of
2 different sizes - 4096 bytes and 2 megabytes. Linux uses 2 MB pages
for the kernel and 4 KB pages for most other uses. In some of the more
recent CPUs there is also support for 1 GB pages.
