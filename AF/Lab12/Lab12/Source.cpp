#include <iostream>
#include <fstream>

void alocareMatrice(int**& matrix, int& n)
{
	matrix = new int* [n];

	for (int i = 0; i < n; i++)
		matrix[i] = new int[n];

}



int** citireMatrice(std::string fileName, int& n)
{
	std::ifstream file(fileName);
	int** matrix;
	file >> n;
	alocareMatrice(matrix, n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			file >> matrix[i][j];
	file.close();
	return matrix;
}

int sumaMaxima(int**& matrix, int n, int i, int j)
{

	if (i == n - 1)
		return matrix[i][j];

	return matrix[i][j] + std::max(sumaMaxima(matrix, n, i + 1, j),
		sumaMaxima(matrix, n, i + 1, j + 1));
}

int main()
{
	int n = 0;
	int** matrix = citireMatrice("matrice.txt", n);
	std::cout << sumaMaxima(matrix, n, 0, 0);

	for (int i = 0; i < n; i++) delete[] matrix[i];
	delete[] matrix;

	return 0;
}