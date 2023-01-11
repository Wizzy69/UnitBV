#include <fstream>
#include <iostream>
#include <vector>

struct padure {
	int tip;
	int dimensiune;
};

struct Pozitie {
	int linie, coloana;
};

template<typename T>
void swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

bool contains(std::vector<int> vector, int element)
{
	for (auto e : vector)
		if (e == element)
			return true;
	return false;
}

bool citireMatrice(int**& matrice, std::vector<int>& types, int& n, int& m)
{
	std::ifstream f("input.txt");
	f >> n >> m;
	if (n <= 0 || m <= 0)
	{
		std::cout << "Valorile introduse nu sunt corecte";
		return false;
	}
	matrice = new int* [n];
	for (int linie = 0; linie < n; linie++)
	{
		matrice[linie] = new int[m];
		for (int coloana = 0; coloana < m; coloana++)
		{
			f >> matrice[linie][coloana];
			if ((linie == 0) || (coloana == 0) || (linie == n - 1) || (coloana == m - 1))
			{
				if (matrice[linie][coloana] != 0)
				{
					std::cout << "Matricea nu este valida";
					return false;
				}
			}
			else {
				if (matrice[linie][coloana] != 0)
				{
					if((matrice[linie][coloana] != matrice[linie - 1][coloana] && matrice[linie - 1][coloana] != 0) ||
					    matrice[linie][coloana] != matrice[linie][coloana - 1] && matrice[linie][coloana - 1] != 0)
					{
						std::cout << "Matricea nu este valida (doua valori alaturate nenule)";
						return false;
					}

					if(!contains(types, matrice[linie][coloana]))
						types.push_back(matrice[linie][coloana]);
				}
				
			}
			
		}
	}
	
	f.close();
}

int CalculDimensiune(int** matrice, int tip, int n, int m)
{
	int nr = 0;
	for (int linie = 0; linie < n; linie++)
		for (int coloana = 0; coloana < m; coloana++)
			if (matrice[linie][coloana] == tip)
				nr++;

	return nr;
}

padure* AflarePaduri(std::vector<int> types, int** matrice, int n, int m)
{
	padure* paduri = new padure[types.size()];
	for (int index = 0; index < types.size(); index++)
	{
		paduri[index].tip = types[index];
		paduri[index].dimensiune = CalculDimensiune(matrice, types[index], n, m);
	}

	return paduri;
}

void sortarePaduriDescrescator(padure* paduri, int length)
{
	for(int index=0;index<length;index++)
		for(int index2 = index+1;index2 < length;index2++)
			if (paduri[index].dimensiune < paduri[index2].dimensiune)
				swap(paduri[index], paduri[index2]);
}

void afisarePaduriSortate(padure* paduri, int length)
{
	std::ofstream outputFile("output.txt");
	for (int index = 0; index < length; index++)
		outputFile << paduri[index].tip<< " ";
	outputFile << "\n";
	outputFile.close();
}

void verificareLegarePaduriPrinPlantare(int** matrice, int n, int m, std::vector<Pozitie>& legaturi)
{
	for(int linie=1;linie<n-1;linie++)
		for (int coloana = 1; coloana < m-1; coloana++)
		{
			if (matrice[linie][coloana] == 0)
			{
				if ((matrice[linie][coloana - 1] == matrice[linie][coloana + 1] && matrice[linie][coloana - 1] != 0) ||
					matrice[linie - 1][coloana] == matrice[linie + 1][coloana] && matrice[linie + 1][coloana] != 0)
				{
					Pozitie p;
					p.linie = linie;
					p.coloana = coloana;
					legaturi.push_back(p);
				}
			}
		}
}

padure calculCeaMaiMarePadure(int ** matrice, int n, int m)
{
	padure p;
	padure maxP;
	maxP.dimensiune = 0;
	maxP.tip = -1;
	p.tip = -1;
	p.dimensiune = 0;
	for(int linie=1;linie<n;linie++)
		for (int coloana = 1; coloana < m; coloana++)
		{
			if (matrice[linie][coloana] != 0)
			{
				if (p.tip == -1)
					p.tip = matrice[linie][coloana];
				if (p.tip == matrice[linie][coloana])
					p.dimensiune++;
				if (p.dimensiune > maxP.dimensiune)
				{
					maxP.dimensiune = p.dimensiune;
					maxP.tip = matrice[linie][coloana];
				}
				if (p.tip != matrice[linie][coloana])
					p.dimensiune = 0;
			}
		}

	return maxP;
}

void afisarePadure(padure p)
{
	std::ofstream fileStream("output.txt");
	fileStream << "Cea mai mare padure are dimensiunea de " << p.dimensiune << " si contine tipul " << p.tip << " de copaci.";
	fileStream.close();
}


int main()
{
	int n, m;
	std::vector<int> types = {};
	std::vector<Pozitie> pozitii = {};
	int** matrice;

	if (!citireMatrice(matrice, types, n, m))
		return 1;

	padure* paduri = AflarePaduri(types, matrice, n, m);
	sortarePaduriDescrescator(paduri, types.size());
	afisarePaduriSortate(paduri, types.size());
	verificareLegarePaduriPrinPlantare(matrice, n, m, pozitii);
	padure _padure = calculCeaMaiMarePadure(matrice, n, m);
	afisarePadure(_padure);
	for (int i = 0; i < n; i++)
		delete matrice[i];
	delete[] matrice;
	return 0;
}