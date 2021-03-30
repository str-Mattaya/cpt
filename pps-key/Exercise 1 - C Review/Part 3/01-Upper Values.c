#include <stdio.h>

int main()
{
    
    int arr[10], i;
    float avg = 0;
    
    for(i=0;i<10;i++)
    {
        printf("N%02d: ", i+1);
        scanf("%d", &arr[i]);
        avg += arr[i];
    }
    avg /= 10;
    printf("=");
    for(i=0;i<10;i++)
    {
        if(arr[i] > avg)
        {
            printf("%d ", arr[i]);
        }
    }
    
    return 0;
}
