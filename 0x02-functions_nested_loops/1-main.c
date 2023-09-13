#include <stdio.h>
int main(void)
{
    char str[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int i;
    for (i = 0; i < 26; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
    return (0);
}
