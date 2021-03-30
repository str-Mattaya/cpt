#include<stdio.h>

char* s_end(char *s)
{
    while(*s != '\0')
    {
        s++;
    }
    
    return s-1;
}


int is_reverse_part(char *s1, char *s2)
{
    char *r_s1 = s_end(s1);
    
    //cba is reverse part of abcd
    while(r_s1 >= s1)
    {
        if(*r_s1 == *s2)
        {
            break;
        }
        r_s1--;
    }
    
    if(r_s1 < s1)
    {
        return 0;
    }
    
    while(*s2 != '\0')
    {
        if(*r_s1 != *s2)
        {
            return 0;
        }
        r_s1--;
        s2++;
    }
    
    return 1;
}

int main(){
   char s1[128], s2[128];

   printf("S1: ");
   scanf(" %[^\n]s", s1);
   printf("S2: ");
   scanf(" %[^\n]s", s2);

   printf("= %s\n", is_reverse_part(s1, s2) ? "Yes" : "No");
   return 0;
}
