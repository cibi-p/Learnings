
1. Write a program to print helloworld without using semicolon
```C
#include<stdio.h>
int main(){
    if(printf("hello world")){
    }
    return 0;
}
```
```Output
hello world
```

2. Swap a two number using only 2 variables
```C
#include<stdio.h>
int main(){
    int a=5, b=3;
    printf("Before swap a=%d,b=%d\n",a,b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("After swap a=%x, b=%x\n",a,b);
}
```
```Output
output
Before swap a=5, b=3
After swap a=3, b=5
```

3.a.fibinacci series
```C
#include<stdio.h>
int main(){
    int n1=0,n2=1, n3,n;
    n=4 //we need to print 4 series of fibinocci number
    printf("%d, %d, ",n1,n2);
    for (int i=0; i<n-2; i++)
    {
        n3=n1+n2;
        printf("%d, ",n3);
        n1=n2;
        n2=n3;
    }
}
```
```Output
output:
0, 1, 1, 2,
```


3.b. fibonacci series with recursion
```C
#include<stdio.h>
int fibo(int n)
{
    static int n1=0, n2=1, n3;
    if(n!=0)
    {
        n3=n1+n2;
        n1=n2;
        n2=n3;
        printf("%d, ",n3);
        fibo(n-1);
    }
}
int main(){
    printf("%d, %d, ",0,1);
    int N=15;
    fibo(N-2);
}
```
```Output
output:
0, 1, 1, 2, 3, 5, 8 ,13, 21, 34, 55, 89, 144, 233, 377
```

4)prime number

```C
#include<stdio.h>
int main(){
    int flag=0;
    int N=23;
    for(int i=2; i<N/2;i++)
    {
        if(N%i==0){
            printf("not a prime number");
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("prime number");
    return 0;
}
```
```Output
output:
prime number
```
<details><summary>click me</summary>
<p>
other efficiency algorithmn will updated soon
</p>
</details>

