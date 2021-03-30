#include<stdio.h>

void psum(int* m, int* data)
{
    *m += *data;
}

int main()
{
    int sum = 0, data;
    
    do
    {
        printf("N: ");
        scanf(" %d", &data);
        
        psum(&sum, &data);
    }while(data != 0);
    
    printf("= %d", sum);
    return 0;
}