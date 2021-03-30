#include <stdio.h>

struct employee {
    char name[128];
    float salary;
};

typedef struct employee Employee;

int main() {
    int num;
    Employee e;
    float total = 0.0;
    FILE *fp = fopen("employee.bin", "rb");
    
    if(fp == NULL)
    {
        //No File
        return 1;
    }
    
    if(!fread(&num, sizeof(int), 1, fp))
    {
        //Error
        return 1;
    }
    
    while(fread(&e, sizeof(Employee), 1, fp))
    {
        printf("%s:%.1f\n", e.name, e.salary);
        total += e.salary;
    }
    printf("=%.1f\n", total);
    
    fclose(fp);
    return 0;	
}
