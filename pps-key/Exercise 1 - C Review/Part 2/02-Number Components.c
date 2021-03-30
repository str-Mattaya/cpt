#include<stdio.h>

void display_components(int n);

int main(){

    int num;

    printf("Enter:");
    scanf("%d", &num);

    if(num < 100000)
        display_components(num);

    return 0;
}

int print_first_index(int n)
{
    if(n/10000 > 0)
    {
        printf("=%d0000", n/10000);
        n = n%10000;
    }else if(n/1000 > 0)
    {
        printf("=%d000", n/1000);
        n = n%1000;
    }else if(n/100 > 0)
    {
        printf("=%d00", n/100);
        n = n%100;
    }else if(n/10 > 0)
    {
        printf("=%d0", n/10);
        n = n%10;
    }else if(n > 0)
    {
        printf("%d", n);
        n = 0;
    }
    return n;
}

void display_components(int n)
{
    //find first-index;
    n = print_first_index(n);

    if(n/1000 > 0)
    {
        printf("+%d000", n/1000);
    }
    n = n%1000;
    if(n/100 > 0)
    {
        printf("+%d00", n/100);
    }
    n = n%100;
    if(n/10 > 0)
    {
        printf("+%d0", n/10);
    }
    n = n%10;
    if(n>0)
    {
        printf("+%d", n);
    }
}
