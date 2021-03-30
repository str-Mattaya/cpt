#include<stdio.h>

typedef struct {
    char name[128];
    int salary;
} Employee;

Employee input_employee();
int find_max(Employee e[], int len);
int find_total(Employee e[], int len);

int main(){
    
    Employee e[5];
    int i;
    
    for(i=0;i<5;i++)
    {
        printf("E%02d: ", i+1);
        e[i] = input_employee();
    }
    
    int max_index = find_max(e, 5);
    
    printf("Max=%s/%d\n", e[max_index].name, e[max_index].salary);
    printf("Total=%d", find_total(e, 5));
    return 0;
}

Employee input_employee(){
    Employee e;
    scanf(" %[^/]s", e.name);
    getchar();
    scanf(" %d", &e.salary);
    return e;
}

int find_max(Employee e[], int len)
{
    int i, max_index = 0;
    
    for(i=0;i<len;i++)
    {
        if(e[i].salary > e[max_index].salary)
        {
            max_index = i;
        }
    }
    
    return max_index;
}

int find_total(Employee e[], int len)
{
    int i, sum = 0;
    
    for(i=0;i<len;i++)
    {
        sum += e[i].salary;
    }
    
    return sum;
}