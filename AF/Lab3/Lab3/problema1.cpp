//#include <iostream>
//
//void alocareMatrice(int**& matrice, int& lin, int& col) {
//	std::cout << "Dimensiune: \n";
//	std::cin >> lin >> col;
//	std::cout << "Matrice: \n";
//	matrice = new int* [lin];
//	for (int i = 0; i < lin; i++) {
//		matrice[i] = new int[col];
//	}
//}
//
//void dealocareMatrice(int**& matrice, int& lin, int& col)
//{
//	for (int i = 0; i < lin; i++) {
//		delete[] matrice[i];
//	}
//	delete[] matrice;
//}
//
//void citireMatrice(int**& matrice, const int lin, const int col)
//{
//	for (int i = 0; i < lin; i++) {
//		for (int j = 0; j < col; j++) {
//			std::cin >> matrice[i][j];
//		}
//	}
//}
//
//int indexMaximDiagonalaPrincipala(int** matrice, const int lin, const int col)
//{
//	int indexMax = 0;
//	for (int i = 0; i < lin; i++) {
//		if (matrice[i][i] > matrice[indexMax][indexMax]) {
//			indexMax = i;
//		}
//	}
//	return indexMax;
//}
//
//int indexMinDiagonalaSecundara(int** matrice, const int lin, const int col)
//{
//	int indexMin = 0;
//	for (int i = 0; i < lin; i++) {
//		if (matrice[i][col - i - 1] < matrice[indexMin][col - indexMin - 1]) {
//			indexMin = i;
//		}
//	}
//	return indexMin;
//}
//
//void afisareMatrice(int** matrice, const int lin, const int col)
//{
//	for (int i = 0; i < lin; i++) {
//		for (int j = 0; j < col; j++) {
//			std::cout << matrice[i][j] << " ";
//		}
//		std::cout << std::endl;
//	}
//}
//
//int main()
//{
//	int** matrice;
//	int linii, coloane;
//
//	alocareMatrice(matrice, linii, coloane);
//	citireMatrice(matrice, linii, coloane);
//	
//	int ind1 = indexMaximDiagonalaPrincipala(matrice, linii, coloane);
//	int ind2 = indexMinDiagonalaSecundara(matrice, linii, coloane);
//
//	int aux = matrice[ind1][ind1];
//	matrice[ind1][ind1] = matrice[ind2][coloane - ind2 - 1];
//	matrice[ind2][coloane - ind2 - 1] = aux;
//
//	std::cout << "\n";
//	afisareMatrice(matrice, linii, coloane);
//	dealocareMatrice(matrice, linii, coloane);
//}