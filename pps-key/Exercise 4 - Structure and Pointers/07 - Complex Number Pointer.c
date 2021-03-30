#include<stdio.h>
typedef struct {
    int real;
    int img;  //imagine
} Complex;

void add_complex(Complex *rptr, Complex *aptr, Complex *bptr);

int main(){
    Complex a, b, result;
    
    printf("C-A: "); scanf(" %d %d", &a.real, &a.img);
    printf("C-B: "); scanf(" %d %d", &b.real, &b.img);
    
    add_complex(&result, &a, &b);
    
    printf("=%d%+di\n", result.real, result.img);
    return 0;
}

void add_complex(Complex *rptr, Complex *aptr, Complex *bptr)
{
    rptr->real = aptr->real + bptr->real;
    rptr->img = aptr->img + bptr->img;
}
