//#include <iostream>
//
//void alocareMatrice(int**& matr, int& nrl, int& nrcol)
//{
//	std::cout << "Dimensiunea: ";
//	std::cin >> nrl >> nrcol;
//
//	matr = (int **)malloc(sizeof(int*)*nrl);
//	for (int i = 0; i < nrl; ++i)
//		matr[i] = (int*) malloc(sizeof(int) * nrcol);
//}
//
//void citire(int **& matrice, int l, int c) {
//	for (int i = 0; i < l; ++i)
//		for (int j = 0; j < c; ++j)
//			std::cin >> matrice[i][j];
//}
//
//void dealocare(int**& matrice, int l, int c)
//{
//	for (int i = 0; i < l; ++i)
//		delete[] matrice[i];
//	delete[] matrice;
//}
//
//
//int main()
//{
//
//	int numarLinii, nrColoane;
//	int** matriceDinamica;
//
//	alocareMatrice(matriceDinamica, numarLinii, nrColoane);
//	citire(matriceDinamica, numarLinii, nrColoane);
//
//	for (int i = 0; i < numarLinii; i++)
//	{
//		for (int j = 0; j < nrColoane; ++j)
//			std::cout << matriceDinamica[i][j] << " ";
//		std::cout << std::endl;
//	}
//
//	dealocare(matriceDinamica, numarLinii, nrColoane);
//	return 0;
//}