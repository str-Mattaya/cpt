#include<stdio.h>
#include<string.h>

void to_cap(char *cptr);

int main(){
    char s[256];
    int len = -1, i;

    printf("Enter: ");
    scanf("%[^\n]s", s);

    len = strlen(s);

    for(i = 0; i < len; i++){
        //your code here
        to_cap(&s[i]);
    }
    
    printf("=%s\n", s);    
    return 0;
}

//define to_cap function here!
void to_cap(char *cptr)
{
    if(*cptr >= 'a' && *cptr <= 'z')
    {
        *cptr = *cptr - 'a' + 'A';
    }
}
