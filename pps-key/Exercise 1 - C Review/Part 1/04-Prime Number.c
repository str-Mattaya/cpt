#include <stdio.h>

int isPrimeNumber(int positive)
{

    int i, timeDivide = 0;
    for(i=1;i<=positive;i++)
    {
        if(positive%i == 0)
        {
            timeDivide++;
        }
    }

    if(timeDivide == 2)
    {
        return 1;
    }

    return 0;
}

int main()
{
    int max_range, i;
    printf("X: "); scanf("%d", &max_range);

    int num=0;
    for(i=1;i<=max_range;i++)
    {
        if(isPrimeNumber(i) == 1)
        {
            num++;
        }
    }

    printf("=%d", num);
    return 0;
}
