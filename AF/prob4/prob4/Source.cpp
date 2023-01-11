#include <iostream>

int numarElementeMaiMici(int* sir, int dimensiune, int element) {
	int nr = 0;
	for (int i = 0; i < dimensiune; i++)
		if (sir[i] < element)
			return nr++;

	return nr;
}

// 1 6 3 4 2 0
int cautare(int* sir, int dim, int stanga, int dreapta, int element)
{
	if (stanga > dreapta)
		return element;

	int mijloc = (stanga + dreapta) / 2;
	int nr = numarElementeMaiMici(sir, dim, sir[mijloc]);

	if (nr < sir[mijloc])
	{
		cautare(sir, dim, mijloc + 1, dreapta, sir[mijloc] - 1);
		cautare(sir, dim, stanga, mijloc, sir[mijloc] - 1);
	}
	else {
		cautare(sir, dim, mijloc + 1, dreapta, sir[mijloc] + 1);
		cautare(sir, dim, stanga, mijloc, sir[mijloc] + 1);
	}

}

int main()
{
	int* v = new int[6] { 0, 2, 5, 3, 1, 4 };
	int dim = 6;
	int element = dim - 1;
	int rezultat = cautare(v, dim, 0, dim - 1, element);
	std::cout << rezultat;

}