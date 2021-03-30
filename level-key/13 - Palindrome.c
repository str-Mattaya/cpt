#include<stdio.h>

char* s_end(char *s);
int palin(char *s, char *f);

int main(){
   char s[128];
   char *f;

   printf("Enter: ");
   scanf("%s", s);
   
   f = s_end(s);
   
   printf("= %s\n", palin(s, f) ? "Yes" : "No");
   return 0;
}

char* s_end(char *s)
{
    while(*s != '\0')
    {
        s++;
    }
    
    return s-1;
}

int palin(char *s, char *f)
{
    while(s < f)
    {
        if(*s != *f)
        {
            return 0;
        }
        s++;
        f--;
    }
    return 1;
}