#include <stdio.h>

void array_adding(int a[], int b[], int len);
void array_input(int a[], int len, int set);

int main()
{
    int num[3][5];
    
    array_input(num[0], 5, 1);
    array_input(num[1], 5, 2);
    array_input(num[2], 5, 3);
    
    array_adding(num[0], num[1], 5);
    array_adding(num[0], num[2], 5);
    
    int i;
    printf("=");
    for(i=0;i<5;i++)
    {
        printf(" %d", num[0][i]);
    }
    
    return 0;
}

void array_input(int a[], int len, int set)
{
    int i;
    for(i = 0; i < len; i++){
        printf("S%d-%02d: ", set, i + 1);
        scanf("%d", &a[i]);
    }
}

void array_adding(int a[], int b[], int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        a[i] += b[i];
    }
}
