#include<stdio.h>
char* find_ch(char *s, char v)
{
    while(*s != '\0')
    {
        if(*s == v)
        {
            return s;
        }
        s++;
    }
    return NULL;
}

int main(){
    char s[128];
    char from, to;
    char *cptr = NULL;

    printf("string: ");
    scanf("%[^\n]s", s);

    printf("from: ");
    scanf(" %c", &from);
    printf("to: ");
    scanf(" %c", &to);
    
    //use find_ch to process the text
    cptr = find_ch(s, from);
    while(cptr != NULL)
    {
        *cptr = to;
        cptr = find_ch(cptr+1, from);
    }
    
    printf("= %s\n", s);
    return 0;
}