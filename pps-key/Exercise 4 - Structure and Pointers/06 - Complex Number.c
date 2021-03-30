#include<stdio.h>
typedef struct {
    int real;
    int img;  //imagine
} Complex;

Complex add_complex(Complex a, Complex b);

int main(){
    Complex a, b, result;
    
    printf("C-A: "); scanf(" %d %d", &a.real, &a.img);
    printf("C-B: "); scanf(" %d %d", &b.real, &b.img);
    
    result = add_complex(a,b);
    
    printf("=%d%+di\n", result.real, result.img);
    return 0;
}

Complex add_complex(Complex a, Complex b)
{
    Complex c;
    c.real = a.real + b.real;
    c.img = a.img + b.img;
    return c;
}
