#include <malloc.h>
#include <stdio.h>

void freeMemory(float **matrix, const int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int main()
{
    int m, n;
    printf("Introduceti numarul de linii si numarul de coloane");
    scanf("%d %d", &m, &n);

    float **a = (float **)malloc(m * sizeof(float *));
    if (a == NULL)
    {
        perror("Eroare la alocarea memoriei");
        return 1; // exit(1)
    }

    for (int i = 0; i < m; i++)
    {
        a[i] = (float *)malloc(n * sizeof(float));
        if (a[i] == NULL)
        {
            perror("Eroare la alocarea memoriei");
            return 1; // exit (1);
        }
    }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%f", &a[i][j]);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%.2f ", a[i][j]);
        printf("\n");
    }
    freeMemory(a, m);
    return 0;
}