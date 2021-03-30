#include <stdio.h>

int main()
{
    int base, power;

    printf("base: "); scanf("%d", &base);
    printf("power: "); scanf("%d", &power);

    int i, expo = 1;
    for(i=0;i<power;i++)
    {
        expo *= base;
    }

    printf("= %d", expo);

    return 0;
}
