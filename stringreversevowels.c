#include <stdio.h>
#include <string.h>

int Vowel(char ch)
{
    if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
    {
        return 1;
    }

    return 0;
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    int left = 0;
    int right = strlen(str) - 1;

    while (left < right)
    {
        while (left < right && !Vowel(str[left]))
        {
            left++;
        }
        while (left < right && !Vowel(str[right]))
        {
            right--;
        }
        if (left < right)
        {
            char temp = str[left];
            str[left] = str[right];
            str[right] = temp;

            left++;
            right--;
        }
    }

    printf("String after reversing vowels: %s\n", str);

    return 0;
}
