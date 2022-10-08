//#include <iostream>
//
//int Suma(int a)
//{
//	int contor = 0;
//	while (a) {
//		contor += a % 10;
//		a /= 10;
//	}
//	return contor;
//}
//void Perechi(int n) {
//	if (n < 0) {
//		std::cout << "imposibil";
//		return;
//	}
//	for (int i = 1; i < n; i++)
//		for (int j = i + 1; j <= n; j++)
//			if (Suma(i) == Suma(j))
//				std::cout << i << " " << j << std::endl;
//}
//int main()
//{
//	//std::cout<<Suma(234);
//	int n;
//	std::cin >> n;
//
//	Perechi(n);
//	return 0;
//}