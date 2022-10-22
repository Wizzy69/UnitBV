#include <iostream>
#include <vector>

void citireVector(std::vector<std::vector<int>>& matrice, int& lin, int& col) {
	std::cout << "Dimensiune: ";  std::cin >> lin >> col;
	std::cout << "Matrice: \n";
	int element;
	for (int linie = 0; linie < lin; linie++) {
		std::vector<int> vLinie;
		for (int coloana = 0; coloana < col; coloana++) {
			std::cin >> element;
			vLinie.push_back(element);
		}
		matrice.push_back(vLinie);
	}
}

void afisare(const std::vector<std::vector<int>> matrice)
{
	for (int linie = 0; linie < matrice.size(); linie++) {
		for (int coloana = 0; coloana < matrice[linie].size(); coloana++) {
			std::cout << matrice[linie][coloana] << " ";
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
	int l, c;
	std::vector<std::vector<int>> matrice;
	citireVector(matrice, l, c);
	afisare(matrice);
	std::cout << "Suma triunghiului de nord: " << SumaTriunghiulDeNord(matrice) << std::endl;
	std::cout << "Suma triunghiului de sud: " << SumaTriunghiDeSud(matrice) << std::endl;
	std::cout << "Suma triunghiului de est: " << SumaTriunghiDeEst(matrice) << std::endl;
	std::cout << "Suma triunghiului de vest: " << SumaTriunghiDeVest(matrice) << std::endl;
	return 0;
}