#include <stdio.h>
#include <string.h>

int main()
{
    
    char str[128];
    int i;
    
    printf("Enter: ");
    scanf("%[^\n]s", str);
    
    printf("=");
    for(i=strlen(str)-1;i>=0;i--)
    {
        printf("%c", str[i]);
    }

    return 0;
}
