#include <malloc.h>
#include <stdio.h>

int main()
{
    int m, n;
    printf("Introduceti numarul de linii si numarul de coloane");
    scanf("%d %d", &m, &n);
    int **a = (int **)malloc(m * sizeof(int *));

    if (a == NULL)
    {
        printf("Eroare la alocarea memoriei");
        return 1;
    }

    for (int i = 0; i < m; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int));
        if (a[i] == NULL)
        {
            printf("Eroare la alocarea memoriei");
            return 1;
        }
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    for (int i = 0; i < m; ++i)
        free(a[i]);
    free(a);
    return 0;
}