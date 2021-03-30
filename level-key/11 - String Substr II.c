#include<stdio.h>

char* substr(char *s, char from, char to)
{
    char *a = NULL, *b = NULL;
    while(*s != '\0')
    {
        if(*s == from && a == NULL)
        {
            a = s;
        }
        else if(*s == to)
        {
            b = s;
        }
        s++;
    }
    
    if(b != NULL)
        *(b+1) = '\0';

    return a;
}

int main(){
    char in[128];
    char *out = NULL;
    char from, to;

    printf("Enter: ");
    scanf("%[^\n]s", in);
    
    printf("From: ");
    scanf(" %c", &from);

    printf("To: ");
    scanf(" %c", &to);

    //call substr appropriately
    out = substr(in, from, to);
    
    if(out != NULL)
        printf("= %s\n", out);
    else
        printf("--empty string--\n");
   
    return 0;
}