#include<stdio.h>
#include<stdlib.h>

#define NUM 5

typedef struct {
    char name[128];
    int salary;
} Employee;

Employee *input_employee();
int find_total(Employee *e[], int len);

int main(){
    Employee *employees[NUM];
    int i;
    
    for(i=0;i<NUM;i++)
    {
        printf("E%02d: ", i+1);
        employees[i] = input_employee();
    }
    
    printf("Total=%d", find_total(employees, NUM));

    //free employees
    for(i=0;i<NUM;i++)
    {
        free(employees[i]);
    }
    
    return 0;
}

Employee *input_employee(){
    Employee *e;
    e = (Employee*)malloc(sizeof(Employee));
    
    scanf(" %[^/]s", e->name);
    getchar();
    scanf(" %d",&e->salary);
    return e;
}

int find_total(Employee *e[], int len){
    int i, sum=0;
    for(i=0;i<len;i++)
    {
        sum += e[i]->salary;
    }
    
    return sum;
}
