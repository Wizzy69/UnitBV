//#include <iostream>
//
// int removeDigitFromCustomPos(int n, int i)
//{
//	int new_nr = 0;
//	int p = 1;
//
//	while (n)
//	{
//		int c = n % 10;
//		if (i != 0)
//		{
//			new_nr = new_nr + c * p;
//			p *= 10;
//		}
//		i--;
//		n /= 10;
//	}
//
//	return new_nr;
//}
//
// int numberOfDigits(int n)
//{
//	int nr = 0;
//	while (n)
//	{
//		nr++;
//		n /= 10;
//	}
//	return nr;
//}
//
// void main()
//{
//	int n;
//	std::cout << "Introduceti un numar: ";
//	std::cin >> n;
//
//	int nr_digits = numberOfDigits(n);
//	int max_nr = 0;
//	for (int i = 0; i < nr_digits; ++i)
//	{
//		int new_nr = removeDigitFromCustomPos(n, i);
//		if (new_nr > max_nr)
//		{
//			max_nr = new_nr;
//		}
//	}
//
//	std::cout << max_nr;
//}
