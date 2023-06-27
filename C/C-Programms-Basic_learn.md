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
