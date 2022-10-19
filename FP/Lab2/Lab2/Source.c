#include <stdio.h>

float credit(int v)
{
	float c;

	c = v * 3;

	return c;
}

void main()
{
	int v;
	char nume[25];
	
	printf("Introduceti numele: ");
	scanf("%s", nume);

	printf("Introduceti varsta: ");
	scanf("%d", &v);

	float c = credit(v);

	printf("Numele este %s si varsta este %d. Credit: %.2f", nume, v, c);
}