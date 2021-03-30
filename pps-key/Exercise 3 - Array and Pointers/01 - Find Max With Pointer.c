#include<stdio.h>
#define LEN 5

int* find_max(int *p, int len);

int main(){
    int d[LEN], i;
    int *max_ptr;

    for(i = 0; i < LEN; i++){
        printf("N%02d: ", i + 1);
        scanf("%d", &d[i]);
    }

    //use find max appropriately
    max_ptr = find_max(d, LEN);

    printf("=%d\n", *max_ptr);
    return 0;
}

//define find max here!
int* find_max(int *p, int len){
    
    int *ptr, *max = p;
    for(ptr = p; ptr < p+len; ptr++)
    {
        if(*ptr > *max)
        {
            max = ptr;
        }
    }
    return max;
}
