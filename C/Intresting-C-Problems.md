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