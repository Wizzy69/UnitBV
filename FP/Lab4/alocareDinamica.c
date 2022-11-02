#include <malloc.h>
#include <stdio.h>

int maxim(int *a, int n);

int main()
{
    int n;
    printf("n = ");
    scanf("%d", &n);

    if (n == 0)
    {
        printf("Nu exista elemente in vector");
        return 1; // exit(1)
    }

    int *a = (int *)malloc(sizeof(int) * n);
    if (a == NULL)
    {
        perror("Eroare la alocarea memoriei");
        return 1; // exit(1)
    }

    for (int i = 0; i < n; i++)
    {
        printf("a[%d] =", i);
        scanf("%d", &a[i]);
    }

    int m = maxim(a, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nMaximul este %d", m);

    printf("\n");
    free(a);
    return 0;
}

int maxim(int *a, int n)
{
    int m = a[0];

    for (int i = 1; i < n; ++i)
        if (m < a[i])
            m = a[i];
    return m;
}