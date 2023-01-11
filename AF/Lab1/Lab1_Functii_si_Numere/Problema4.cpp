#include <iostream>

int cmmdc(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}

//void main()
//{
//	int n;
//	std::cout << "n="; std::cin >> n;
//
//	int a, b, cmmdc_maxim = 1, max_a = -1, max_b = -1;
//
//	std::cout << "Introduceti cele " << n << " perechi de numere: " << std::endl;
//	for (int i = 1; i <= n; ++i)
//	{
//		std::cin >> a;
//		std::cin >> b;
//		int _cmmdc = cmmdc(a, b);
//		if (_cmmdc > cmmdc_maxim)
//			cmmdc_maxim = _cmmdc, max_a = a, max_b = b;
//	}
//
//	std::cout << "Perechea cu cmmdc maxim este: " << max_a << " " << max_b << '\n';
//}