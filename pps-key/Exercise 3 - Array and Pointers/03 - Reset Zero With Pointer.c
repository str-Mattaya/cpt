#include<stdio.h>
#define LEN 10

int* find_neg(int *p, int *q);

int main(){
    int d[LEN], i;

    for(i = 0; i < LEN; i++){
        printf("N%02d: ", i + 1);
        scanf("%d", &d[i]);
    }
    
    //use find_neg appropriately
    while(find_neg(&d[0], &d[LEN-1]) != NULL)
    {
        *find_neg(&d[0], &d[LEN-1]) = 0;
    }

    printf("= ");
    for(i = 0; i < LEN; i++){
        printf("%d ", d[i]);       
    }
    printf("\n");
    return 0;
}


int* find_neg(int *p, int *q){
    
    while(p <= q)
    {
        if(*p < 0)
        {
            return p;
        }
        p++;
    }
    return NULL;
}
