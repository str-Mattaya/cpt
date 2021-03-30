#include<stdio.h>
void adding(int *pos_ptr, int *neg_ptr, int v);

int main(){
    int pos = 0, neg = 0;
    
    int i=1, num;
    do
    {
        printf("N%02d: ", i); scanf(" %d", &num);
        adding(&pos, &neg, num);
        i++;
    }while(num != 0);
    
    return 0;
}

void adding(int *pos_ptr, int *neg_ptr, int v)
{
    if(v == 0)
    {
        
        printf("%d-%d=%d", *pos_ptr, -(*neg_ptr), (*pos_ptr)+(*neg_ptr));
        
    }else{
        
        if(v > 0)
        {
            *pos_ptr += v;
        }else{
            *neg_ptr += v;
        }
        
        printf("=%d/%d\n", *pos_ptr, *neg_ptr);
    }
}
