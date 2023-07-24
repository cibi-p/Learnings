#include<stdio.h>
#include<string.h>

int max(int c, int d)
{
    if (c<d)
        return d;
    else 
        return c;
}
int main(){
    char a[1000];
    char b[1000];
    int result[101];
    int res_count=0;
    int remainder =0;
    scanf("%s %s",a,b);

    // we need to add the number from last, as wee do in the normal addition.
    for(int i=max(strlen(a),strlen(b))-1;i>=0;i--)
    {
        //adding the remainder + a[i]+b[i];
        //Note: '0' char is represented as 48 in integer, so we subtract 48, to convert char to int;
        int add=remainder+(a[i]-48)+(b[i]-48);

        //ex: remainder = 22/10=2, so 2 will be in remainder and it added to the next summazation
        remainder=add/10;

        // ex: 23%10 =3, which is added to the result array
        result[res_count++]=add%10;

        //if i=0, then we need to add remainder to the array
        if(i==0 && remainder!=0)
         result[res_count++]=remainder;
    }

    //we need to print the array in reverse to get the answer.
    for(int i=res_count-1; i>=0;i--)
    {
        printf("%d",result[i]);
    }
    return 0;
}