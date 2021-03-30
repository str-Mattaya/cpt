#include <stdio.h>
#include <ctype.h>

char char_twist(char c);

int isAlphabet(char ch)
{
    if(ch >= 'A' && ch <= 'Z')
    {
        return 1;
    }else if(ch >= 'a' && ch <= 'z')
    {
        return 1;
    }
    return 0;
}

int main(){

    char ch;

    while(1)
    {
        printf("Char: ");
        scanf(" %c", &ch);

        if(isAlphabet(ch) == 1)
        {
            printf("=%c\n", char_twist(ch));
        }else{
            printf("End.");
            break;
        }
    }

    return 0;
}

char char_twist(char c)
{
    if(c >= 'A' && c <= 'Z')
    {
        return tolower(c);
    }
    return toupper(c);
}
