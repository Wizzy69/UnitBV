/*
Se dă o bucată de hârtie de dimensiune A x B. Hârtia se taie în pătrate de orice
dimensiune. Găsiți numărul minim de pătrate în care poate tăia.
Exemplu 13 x 29 = 2 (13x13) + 4 (3x3) + 3 (1x1) = 9 bucăți.
*/

#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d, nr;
	cout << "Introduceti dimensiunile harti: ";
	cin >> a >> b;
	if (a > b)
	{
		c = a;
		a = b;
		b = c;
	}
	nr = 0;
	while (b > 0)
	{
		d = a % b;
		nr = nr + a / b;
		a = b;
		b = d;
	}
	cout << "Numarul minim de patrate este: " << nr;
	return 0;
}