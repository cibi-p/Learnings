# C programs

1. **A positive integer is entered through the keyboard. Write a function
to obtain the prime factors of this number.
For example, prime factors of 24 are 2, 2, 2 and 3, whereas prime
factors of 35 are 5 and 7.**\
<sub>tag: prime factor, basic</sub>

    ```C
    #include<stdio.h>

    void prime(int);
    int main()
    {
        int num;
        printf("Enter number:");
        scanf("%d", &num);
        prime(num); /* Function call */
        return 0;
    }

    void prime(int num)
    {
    int i = 2;
    printf("Prime factors of %d are\n", num);
    while (num != 1)
    {
        if (num % i == 0)
            printf("%d\n", i);
        else{
            i++;
            continue;

        }
        num/=i;
    }
    }
    ```
2. **Write a general-purpose function to convert any given year into its
Roman equivalent. Use these Roman equivalents for decimal
numbers: 1 – I, 5 – V, 10 – X, 50 – L, 100 – C, 500 – D, 1000 – M.\
Example:\
Roman equivalent of 1988 is mdcccclxxxviii.\
Roman equivalent of 1525 is mdxxv.**\
<sub>tags: roman number conversion, basic</sub>
    ```c
    /* Convert given year into its roman equivalent */
    # include <stdio.h>
    int romanise ( int, int, char);
    int main()
    {
        int yr;
        printf ("\nEnter year:");
        scanf ("%d", &yr ) ;
        yr=romanise (yr, 1000, 'm'); 
        yr=romanise (yr, 500, 'd');
        yr=romanise (yr, 100, 'c'); 
        yr=romanise (yr, 50, 'l');
        yr=romanise (yr, 10, 'x');
        yr= romanise (yr, 5, 'v'); 
        yr= romanise (yr, 1, 'i');
        return 0;
    }
    int romanise (int y, int k, char ch) 
    {
        int i,j;
        if (y==9)
        {
            printf("ix");
            return (y %9);
        }
        if (y==4)
        {
            printf("iv");
            return (y %4);
        }
        j=y/k;
        for (i=1;i<=j;i++) 
            printf("%c", ch);
        return (y-k*j);
    }
    ```
1. **Write a program to produce the following output:**
    ```
    A B C D E F G F E D C B A
    A B C D E F   F E D C B A
    A B C D E       E D C B A
    A B C D           D C B A
    A B C               C B A
    A B                   B A
    A                       A
    ```

    ```c
    /* Produce the given pattern */
    # include <stdio.h>
    int main()
    {
        int i= 1, x = 71, blanks = 0, j, val, k;
        while (i<=7)
        {
            j=65;
            val=x;
            while(j<=val)
            {
                printf("%c",j);
                j++;
            }
            if(i==1)
                val--;
            k=1;
            while(k<=blanks)
            {
                printf(" ");
                k++;
            }
            blanks=2*i-1;
            while(val>=65)
            {
                printf("%c",val);
                val--;
            }
            printf("\n");
            x--;
            i++;
        }
        return 0;
    }
    ```

1. **Write a program to produce the following output:**
    ```
        1
       1 1
      1 2 1
     1 3 3 1
    1 4 6 4 1
    ```

    ```c
    /* Produce the given pattern */ 
    #include <stdio.h> 
    int main() 
    { 
        int i, j, k, t, f1, f2, f3, z, sp;
        sp=20; 
        for (i=0;i<= 4; i++) 
        { 
            for (k=0; k<sp-i; k++) 
                printf (" "); 
            sp-=1; 
            for(j=0; j<=i; j++) 
            { 
                f1=f2=f3= 1; 
                t=i; 
                while (t!=0) 
                { 
                    f1 = f1 *t; 
                    t--;
                }
                t=j; 
                while (t!=0) 
                { 
                    f2=f2*t;
                    t--;
                }
                t=i-j;
                while(t!=0)
                {
                    f3=f3*t;
                    t--;
                }
                z=f1/(f2*f3);
                printf("%3d",z);
            }
            printf("\n");
        }
        return 0;
    }
    ```
1. **According to the Gregorian calendar, it was Monday on the date 01/01/01. If any year is input through the keyboard write a program to find out what is the day on 1 January of this year.**
    ```c
    # include <stdio.h>

    int main()
    {
        int leapdays, firstday, yr;
        long int normaldays, totaldays;
        printf("Enter year");
        scanf( "%d", &yr );
        normaldays = (yr - 1)*365L;
        leapdays = (yr -1)/4-(yr - 1) / 100 + (yr - 1) / 400 ;
        totaldays = normaldays + leapdays;
        firstday = totaldays % 7 ;
        if (firstday == 0 )
            printf ( "Monday\n" );
        if (firstday == 1 )
            printf ( "Tuesday\n");
        if (firstday == 2)
            printf ( "Wednesday\n");
        if (firstday == 3)
            printf ( "Thursday\n" );
        if (firstday == 4 )
            printf ( "Friday\n");
        if (firstday == 5 )
            printf ( "Saturday\n");
        if (firstday == 6 )
            printf ( "Sunday\n" );
        return 0;
    }
    ```

**N to 1, without using '-', similary we can do for 1 to N without using '+'. It is a Kind of Backtrack problem**  
<sub>tag: recurssion, backtrack</sub>
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
``````