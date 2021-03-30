#include<stdio.h>

char* str_end(char *s)
{
    while(*s != '\0')
    {
        s++;
    }
    return s;
}

int count_numeric(char *s, char *end)
{
    int count = 0;
    
    while(s < end)
    {
        if(*s >= '0' && *s <= '9')
        {
            count++;
        }
        s++;
    }
    
    return count;
}

int main(){
    char s[128];
    char *end = NULL;

    printf("Enter: ");
    scanf("%[^\n]s", s);
    
    //call str_end and count_numeric appropriately
    end = str_end(s);
    int count = count_numeric(s, end);
    
    printf("= %d\n", count);
   
    return 0;
}
