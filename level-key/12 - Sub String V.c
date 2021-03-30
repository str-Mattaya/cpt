#include<stdio.h>

char* find_ch(char *s, char key)
{
    while(*s != '\0')
    {
        if(*s == key)
        {
            return s;
        }
        s++;
    }
    
    if(s != NULL)
        return s;
    return NULL;
}

char* substr(char *s, char *from, int len)
{
    char *tmp = find_ch(s, '\n'), *a = find_ch(s, *from);
    if(a != NULL)
    {
        if(a+len < tmp)
        {
            *(a+len) = '\0';
        }
        
        if(a == tmp)
            return NULL;
        return a;
    }
    return NULL;
}

int main(){
    char in[128];
    char *out = NULL;
    char from;
    int len;

    printf("Enter: ");
    scanf("%[^\n]s", in);
    
    printf("From: ");
    scanf(" %c", &from);

    printf("Len: ");
    scanf(" %d", &len);

    //call substr appropriately
    out = substr(in, &from, len);
    
    if(out != NULL)
        printf("= %s\n", out);
    else
        printf("--empty string--\n");
   
    return 0;
}