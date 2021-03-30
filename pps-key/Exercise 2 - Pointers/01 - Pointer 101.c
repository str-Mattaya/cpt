#include<stdio.h>

int sq(int *data)
{
    *data *= *data;
    return *data;
}

int main()
{
    int a;
    printf("Enter: ");
    scanf(" %d", &a);
    
    sq(&a);
    printf("= %d", a);
    return 0;
}
