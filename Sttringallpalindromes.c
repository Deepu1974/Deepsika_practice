#include <stdio.h>
#include <string.h>

int isPalindrome(char str[],int start,int end)
{
    while(start<end)
    {
        if(str[start]!=str[end])
            return 0;

        start++;
        end--;
    }
    return 1;
}
int main()
{
    char str[100];
    int n;
    scanf("%s", str);
    n = strlen(str);
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(isPalindrome(str,i,j))
            {
                for(int k=i;k<=j;k++)
                {
                    printf("%c",str[k]);
                }
                printf("\n");
            }
        }
    }

    return 0;
}
