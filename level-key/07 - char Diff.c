#include<stdio.h>

int char_diff(char *sa, char *sb)
{
    int diff = 0;
    while(*sa != '\0' || *sb != '\0')
    {
        
        if(*sa != *sb)
        {
            diff++;
        }
        
        if(*sa != '\0')
        {
            sa++;
        }
        
        if(*sb != '\0')
        {
            sb++;
        }
    }
    
    return diff;
}

int main(){
   char sa[128];
   char sb[128];

   printf("Enter SA: ");
   scanf("%s", sa);

   printf("Enter SB: ");
   scanf("%s", sb);

   printf("= %d\n", char_diff(sa, sb));
   return 0;
}
