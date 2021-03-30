#include<stdio.h>
#define SYM_NUM 5

char* find_ch(char *s, char v)
{
    while(*s != '\0')
    {
        if(*s == v)
        {
            return  s;
        }
        s++;
    }
    return NULL;
}

char symbols[SYM_NUM] = {'*', '+', '-', '%', ','};

int main(){
    char s[128];
    int count = 0;
    

    printf("Enter: ");
    scanf("%[^\n]s", s);
    
    char *scan_ptr = s;
    int i;
    
    for(i = 0; i < SYM_NUM; i++)
    {
        scan_ptr = find_ch(s, symbols[i]);
        while(scan_ptr != NULL)
        {
            count++;
            scan_ptr = find_ch(scan_ptr+1, symbols[i]);
        }
    }
    
    printf("= %d\n", count);
   
    return 0;
}