#include<stdio.h>

int print_minus(int a[], int len);

int main(){
    
    int arr[8], i;
    
    for(i=0;i<8;i++)
    {
        printf("N%02d: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    printf("=\n");
    for(i=0;i<8;i++)
    {
        arr[print_minus(arr, 8)] *= -1;
    }
    
    return 0;
}

int print_minus(int a[], int len){
    int i;
    for(i = 0; i < len; i++){
        if(a[i] < 0){
            printf("%d\n", a[i]);
            return i;
        }
    }
    return -1;
}
