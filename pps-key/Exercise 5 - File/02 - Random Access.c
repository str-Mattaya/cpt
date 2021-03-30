#include<stdio.h>

int main(){
    
    FILE *fp = fopen("num.dat", "rb");
    int d;
    int result;
    
    if(fp == NULL)
    {
        //No File
        return 1;
    }
    
    do
    {
        printf("Enter: ");
        scanf(" %d", &d);
        
        if(d > 0)
        {
            fseek(fp, (d-1) * sizeof(int), SEEK_SET);
            fread(&result, sizeof(int), 1, fp);
            printf("= %d\n", result);
            rewind(fp);
        }
        
    } while(d > 0);
    
    printf("Done.\n");
    
    fclose(fp);
    return 0;
}
