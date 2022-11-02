#include <stdio.h>

int main()
{
    int n = 10;
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        printf("a[%d] =", i);
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
    return 0;
}