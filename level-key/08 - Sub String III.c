#include<stdio.h>

char* substr(char *s, char from, int len)
{
    char *a = NULL;
    while(*s != '\0')
    {
        if(*s == from && a == NULL)
        {
            a = s;
        }
        s++;
    }
    
    if(a == NULL)
        return NULL;
    
    if(a + len < s)
    {
        *(a+len) = '\0';
    }
    return a;
}

int main(){
    char in[128];
    char *out = NULL;
    char from;
    int len;

    printf("Enter: ");
    gets(in);
    
    printf("From: ");
    scanf(" %c", &from);

    printf("Len: ");
    scanf(" %d", &len);

    //call substr appropriately
    out = substr(in, from, len);
    
    if(out !=NULL)
        printf("= %s\n", out);
    else
        printf("--empty string--\n");
   
    return 0;
}