#include <malloc.h>
#include <stdio.h>

int nrPozitive(float **a, int m, int n)
{
    int i, j, nr = 0;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] > 0)
                nr++;
    return nr;
}

int main()
{
    int m, n;
    printf("Introduceti numarul de linii si numarul de coloane: ");
    scanf("%d %d", &m, &n);

    float **a = (float **)malloc(m * sizeof(float *));
    if (a == NULL)
    {
        perror("Eroare la alocarea memoriei !");
        return 1; // exit(1);
    }

    for (int i = 0; i < m; i++)
    {
        a[i] = (float *)malloc(n * sizeof(float));
        if (a[i] == NULL)
        {
            perror("Eroare la alocarea memoriei !");
            return 1; // exit(1);
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

    int x = nrPozitive(a, m, n);
    printf("Numarul de elemente pozitive este %d\n", x);

    for (int i = 0; i < m; i++)
    {
        free(a[i]);
    }
    free(a);

    return 0;
}