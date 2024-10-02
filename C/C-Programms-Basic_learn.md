# C-Program

Operators in c: [Link](https://www.programiz.com/c-programming/c-operators)

**1. print numbers between a to b using for loop**
```c
#include <stdio.h>
int main()
{
    int a,b;
    printf("enter the starting value");
    scanf("%d",&a);
    printf("last number");
    scanf("%d",&b);
 V   
    for(int i=a;i<b; i++)
    {
        printf("%d \n",i);
    }
}
```
output:
```output
enter the starting value20
last number30
20 
21 
22 
23 
24 
25 
26 
27 
28 
29
```

**2. Biggest number using if, else if, else**
```c
#include <stdio.h>

int main()

{
    int a,b;
    printf("1st num:\t");
    scanf("%d",&a);
    printf("2nd num:\t");
    scanf("%d",&b);
    if(a>b)
    {
        printf("1st num is the Biggest Number");
    }
    else if(a==b)
    {
        printf("Both numbers are equal");
    }
    else
    {
        printf("2nd num is the Biggest Number");
    }
}
```
Output:
```output
1st num:        54
2nd num:        63
2nd num is the Biggest Number
```
## Recurssion

**N to 1, without using '-', similary we can do for 1 to N without using '+'. It is a Kind of Backtrack problem**

```c
#include <stdio.h>

void func(int j,int k)
{
    if(j>k)
        return;
    func(j+1,k);
    printf("%d ",j);
}
int main()
{
   int i=5;
   func(1,5);
    return 0;
}
```
-
**recurrsion addition**
```c
// using paramerization
#include <stdio.h>

void func(int j,int k)
{
    if(j<=0){
        printf("%d",k);
        return;
    }
        
    func(j-1,k+j);
}
int main()
{
   int i=5;
   func(5,0);
    return 0;
}
```

using fuctional recurssion below
```c
#include <stdio.h>

int func(int j)
{
    if(j<=0){
        return 0;
    }
        
    return j+func(j-1);
}
int main()
{
   int i=5;
   i=func(5);
   printf("%d",i);
    return 0;
}
```

**Revrsing array using recursion**
```c
#include <stdio.h>

void func(int j[],int k, int c)
{
    if(k>=c){
        return;
    }
    int temp =j[k];
    j[k]=j[c];
    j[c]=temp;
    
    func(j,k+1,c-1);
    
}
int main()
{
   int i[5]={3,2,4,5,2};
   func(i,0,sizeof(i)/sizeof(i[0])-1);
   for(int j=0; j<5;j++)
    printf("%d ",i[j]);
    return 0;
}
```

**Palindrom String**
```c
#include <stdio.h>
#include<stdbool.h>
#include<string.h>

bool func(char *j, int k, int c)
{
    if(j[k]!=j[c])
        return false;
    if(k>=c/2)
        return true;
    return func(j,k+1,c-1);
}
int main()
{
   char *a ="MeleM";
   bool c= func(a,0,strlen(a)-1);
    printf("%d ",c);
    return 0;
}
```

**nth Fibanocci Series**
```c
#include <stdio.h>

int fib(int a){
    if (a<=1)
        return a;
    return fib(a-1)+fib(a-2);
}

int main()
{
    printf("%d",fib(6));
    return 0;
}
```

**Continuous subsequence of the array**
```c
#include <stdio.h>

int main()
{
    int a[]={1,2,3,4};
    int count=0;
    for(int i=0; i<4;i++)
    {
        for(int j=i; j<4;j++)
        {
            for(int k=i; k<=j; k++)
            {
              printf("%d ",a[k]);
            }
            count++;
            printf("\n");
        }
    }
    
    printf("Total count = %d",count);

    return 0;
}
```
```
1 
1 2 
1 2 3 
1 2 3 4 
2 
2 3 
2 3 4 
3 
3 4 
4 
Total count = 10
```
**subsequence in non-continuous but only increse order of index**  
<sub>tag: subsequence, non-continuous</sub> 

```c
#include <stdio.h>
#include <math.h>

int main()
{
    int a[]={1,2,3,4,};
    int count=0;
    int s=4;
    int power_set_size=pow(2,s);
    for(int counter=0;counter<power_set_size; counter++){
        for(int j=0; j<s; j++)
        {
            if(counter & 1<<j){
                printf("%d ", a[j]);
            }
        }
        printf("\n");
        count++;
    }
    printf("\nThe total count = %d",count-1);
    return 0;
}
```

1 
2 
1 2 
3 
1 3 
2 3 
1 2 3 
4 
1 4 
2 4 
1 2 4 
3 4 
1 3 4 
2 3 4 
1 2 3 4 

The total count = 15 // always total count is (2^n -1)
# File

```c
FILE *fp;
fp=fopen("PRI.c", "r" or "w"); // r- read, w - write, a- append, r+ -read and write and modify existing data, w+ - read and write modify existing data, a+ - cannot modify existing data, wb - write binary, rb - read binary
fclose(fp);

fgets(localstringvariable, size, filepointer);
fscanf ( fp, "%s %d %f", e.name, &e.age, &e.bs );

fwrite ( &e, sizeof ( e ), 1, fp ) ; //&e is struct contains name, age, bs. 1 ->rpresents number of such structures that we want to write at one time
fread ( &e, sizeof ( e ), 1, fp ); //return 1 ir it 9is success

fseek(filepointer, offset, SEEK_CUR or SEEK_END or SEEK_SET/*SEEK_start*/)
//Here, -recsize moves the pointer back by recsize bytes from the current position. SEEK_CUR is a macro defined in “stdio.h”.


//The C library function void rewind(FILE *stream) sets the file position to the beginning of the file of the given stream.

//If we wish to know where the pointer is positioned right now, we can
//use the function ftell( ). It returns this position as a long int which is an
//offset from the beginning of the file. The value returned by ftell( ) can be
//used in subsequent calls to fseek( ). A sample call to ftell( ) is shown
//below.
position = ftell ( fp ) ;
```