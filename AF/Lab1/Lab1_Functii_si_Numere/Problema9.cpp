//#include <iostream>
//
//int inversiune_cifre(int n)
//{
//	int new_nr = 0;
//	int p = 1;
//	
//	while (n)
//	{
//		int c1 = n % 10;
//		int c2 = n / 10 % 10;
//		int pereche = c1 * 10 + c2;
//		new_nr = new_nr + pereche * p;
//		p *= 100;
//		n /= 100;
//	}
//
//	return new_nr;
//}
//
//void main()
//{
//	int n;
//	std::cout << "Introduceti un numar: ";
//	std::cin >> n;
//
//	std::cout << inversiune_cifre(n);
//
//}