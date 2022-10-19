#include <iostream>
#include <vector>

void citireVector(std::vector<std::vector<int>>& vector, int& lin, int& col) {
	std::cin >> lin >> col;
	int element;
	for (int i = 0; i < lin; i++) {
		std::vector<int> vLinie;
		for (int j = 0; j < col; j++) {
			std::cin >> element;
			vLinie.push_back(element);
		}
		vector.push_back(vLinie);
	}
}

void afisare(const std::vector<std::vector<int>> vct)
{
	for (int i = 0; i < vct.size(); i++) {
		for (int j = 0; j < vct[i].size(); j++) {
			std::cout << vct[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int SumaTriunghiulDeNord(std::vector<std::vector<int>> matrice)
{
	int suma = 0;
	for (int i = 0; i < matrice.size(); i++) {
		for (int j = 0; j < matrice[i].size(); j++) {
			if (i < j && i + j < matrice.size() - 1) {
				suma += matrice[i][j];
			}
		}
	}
	return suma;
}

int SumaTriunghiDeSud(std::vector<std::vector<int>> matrice)
{
	int suma = 0;
	for (int i = 0; i < matrice.size(); i++) {
		for (int j = 0; j < matrice[i].size(); j++) {
			if (i > j && i + j > matrice.size() - 1) {
				suma += matrice[i][j];
			}
		}
	}
	return suma;
}

int SumaTriunghiDeEst(std::vector<std::vector<int>> matrice)
{

	int suma = 0;
	for (int i = 0; i < matrice.size(); i++) {
		for (int j = 0; j < matrice[i].size(); j++) {
			if (i < j && i + j > matrice.size() - 1) {
				suma += matrice[i][j];
			}
		}
	}
	return suma;
}

int SumaTriunghiDeVest(std::vector<std::vector<int>> matrice)
{
	int suma = 0;
	for (int i = 0; i < matrice.size(); i++) {
		for (int j = 0; j < matrice[i].size(); j++) {
			if (i > j && i + j < matrice.size() - 1) {
				suma += matrice[i][j];
			}
		}
	}
	return suma;
}

int main()
{
	int linii, coloane;
	std::vector<std::vector<int>> matrice;
	citireVector(matrice, linii, coloane);

	std::cout << "Suma triunghiului de nord este: " << SumaTriunghiulDeNord(matrice) << std::endl;
	std::cout << "Suma triunghiului de sud este: " << SumaTriunghiDeSud(matrice) << std::endl;
	std::cout << "Suma triunghiului de est este: " << SumaTriunghiDeEst(matrice) << std::endl;
	std::cout << "Suma triunghiului de vest este: " << SumaTriunghiDeVest(matrice) << std::endl;
	
	return 0;
	
	
}