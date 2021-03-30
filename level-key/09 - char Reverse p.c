#include<stdio.h>
char* str_end(char *s)
{
    while(*s != '\0')
    {
        s++;
    }
    
    return s;
}

void print_reverse(char *s, char *end)
{
    if(end != NULL && s != NULL)
    {
        while(end != s)
        {
            end--;
            printf("%c", *end);
        }
    }
}

int main(){
    char s[128];
    char *end = NULL;

    printf("Enter: ");
    scanf("%[^\n]s", s);
    
    //call str_end appropriately
    end = str_end(s);
    
    printf("= ");
    print_reverse(s, end);

    return 0;
}
