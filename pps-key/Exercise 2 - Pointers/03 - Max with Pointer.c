#include <stdio.h>
#define NUM 5

int* max(int* a, int *b);

int main(){
    
    int i, num, max_num = 0;

    for(i = 0; i < NUM; i++){
        printf("N%d: ", i+1);
        scanf(" %d", &num);
        
        if(i == 0)
        {
            max_num = num;
            continue;
        }
        
        max_num = *max(&num, &max_num);
    }

    printf("=%d", max_num);
    return 0;
}

int* max(int* a, int *b){
    
    if(*a > *b)
    {
        return a;
    }
    
    return b;
}