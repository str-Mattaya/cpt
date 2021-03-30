#include<stdio.h>
#define LEN 5

typedef struct {
    int real;
    int img;  //imagine
} Complex;

void input_complex(Complex *cptr);
void top_complex(Complex *rptr, Complex *cptr);
void sum_complex(Complex *rptr, Complex cs[], int len);

int main(){
    Complex a[LEN], result = {0,0};
    int i;
    
    for(i=0;i<LEN;i++)
    {
        printf("C%02d: ", i+1);
        input_complex(&a[i]);
    }
    
    sum_complex(&result, a, LEN);
    
    printf("=%d%+di\n", result.real, result.img);
    return 0;
}

void input_complex(Complex *cptr)
{
    scanf(" %d %d", &cptr->real, &cptr->img);
}

void top_complex(Complex *rptr, Complex *cptr)
{
    rptr->real += cptr->real;
    rptr->img += cptr->img;
}

void sum_complex(Complex *rptr, Complex cs[], int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        top_complex(rptr, &cs[i]);
    }
}
