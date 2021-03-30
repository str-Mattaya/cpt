#include <stdio.h>

int main()
{
    int num, counter = 1;
    //positive
    int pos_num = 0;
    //negative
    int neg_num = 0;

    while(1)
    {
        printf("N%02d: ", counter++);
        scanf("%d", &num);

        if(num > 0)
        {
            pos_num++;
        }else if(num < 0)
        {
            neg_num++;
        }else{
            break;
        }

    }

    printf("Positive=%d\n", pos_num);
    printf("Negative=%d", neg_num);

    return 0;
}
