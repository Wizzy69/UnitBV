//#include <iostream>
//#include <vector>
//
//void citireVector(std::vector<std::vector<int>>& vector, int& lin, int& col) {
//	std::cin >> lin >> col;
//	int element;
//	for (int i = 0; i < lin; i++) {
//		std::vector<int> vLinie;
//		for (int j = 0; j < col; j++) {
//			std::cin >> element;
//			vLinie.push_back(element);
//		}
//		vector.push_back(vLinie);
//	}
//}
//
//void afisare(const std::vector<std::vector<int>> vct)
//{
//	for (int i = 0; i < vct.size(); i++) {
//		for (int j = 0; j < vct[i].size(); j++) {
//			std::cout << vct[i][j] << " ";
//		}
//		std::cout << std::endl;
//	}
//}
//
//
////int main()
////{
////	int l, c;
////	std::vector<std::vector<int>> matrice;
////	citireVector(matrice, l, c);
////	afisare(matrice);
////	return 0;
////}