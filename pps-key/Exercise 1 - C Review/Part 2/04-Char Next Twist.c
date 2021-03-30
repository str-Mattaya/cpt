#include <stdio.h>
#include <string.h>
#include <ctype.h>

char char_next(char c);
char char_twist(char c);

void input(char ch[])
{
    int i=0;
    while((ch[i] = getchar()) != '\n')
    {
        if(i > 254)
            break;
        if(ch[i] == EOF)
        {
            ch[i] = '\0';
            break;
        }
        i++;
    }

    ch[i] = '\0';
}

int main(){

    char ch[255];
    int i;
    while(1)
    {
        input(ch);
        if(ch[strlen(ch)-1] == '\0') break;

        for(i=0;i<strlen(ch);i++)
        {
            putchar( char_next(char_twist(ch[i])) );
        }
        putchar('\n');
    }

    return 0;
}

char char_next(char c)
{
    if(c >= 'A' && c < 'Z')
    {
        return c+1;
    }else if(c >= 'a' && c < 'z')
    {
        return c+1;
    }else if(c == 'Z')
    {
        return 'A';
    }else if(c == 'z')
    {
        return 'a';
    }
    return c;
}

char char_twist(char c)
{
    if(c >= 'A' && c <= 'Z')
    {
        return tolower(c);
    }else if(c >= 'a' && c <= 'z')
    {
        return toupper(c);
    }
    return c;
}
