#include <stdio.h>
#include <malloc.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);

    free(a);
    return 0;
}