#include <stdio.h>

int main()
{
    int i, num;
    //minimum
    int min_num;
    //maximum
    int max_num;

    for(i=1;i<=10;i++)
    {
        printf("N%02d: ", i); scanf("%d", &num);
        if(i == 1)
        {
            min_num = num;
            max_num = num;
        }else{
            if(min_num > num) min_num = num;
            if(max_num < num) max_num = num;
        }
    }

    printf("Max=%d\n", max_num);
    printf("Min=%d\n", min_num);
    return 0;
}
