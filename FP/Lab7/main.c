#include <malloc.h>
#include <stdio.h>

int main()
{
    char *s;
    int n;
    char c;
    printf("Caracterul de cautat: ");
    scanf("%c", &c);
    printf("Numarul de caractere este: ");
    scanf("%d", &n);
    s = (char *)malloc(n * sizeof(char));

    if (s == NULL)
    {
        printf("Nu s-a putut aloca memorie");
        return 1;
    }

    printf("Enter a string: ");
    scanf("%s", s);
    printf("The string is: %s", s);

    int i = 0;
    int count = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
            count++;
        i++;
    }

    printf("Numarul de aparitii ale caracterului %c in sirul %s este %d", c, s, count);
    free(s);
    return 0;
}