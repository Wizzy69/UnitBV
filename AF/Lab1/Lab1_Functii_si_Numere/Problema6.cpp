//#include <iostream>
//
//int* frecventa_cifrelor(int n)
//{
//	int* frecventa = new int[10] {0};
//	while (n)
//	{
//		frecventa[n % 10]++;
//		n /= 10;
//	}
//	return frecventa;
//}
//
//void main()
//{
//	int n;
//	std::cout << "n="; std::cin >> n;
//	auto frecventa = frecventa_cifrelor(n);
//
//	for (int i = 1; i < 10; ++i)
//		while (frecventa[i] > 0)
//		{
//			std::cout << i;
//			frecventa[i]--;
//		}
//}