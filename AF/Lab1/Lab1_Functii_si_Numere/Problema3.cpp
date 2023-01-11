#include <iostream>

bool Palindrom(int n)
{
	int rasturnat = 0;
	int copie = n;
	while (n)
	{
		rasturnat = rasturnat * 10;
		rasturnat += n % 10;
		n /= 10;
	}
	return rasturnat == copie;
}

//void main()
//{
//	int a, b;
//	std::cout << "a="; std::cin >> a;
//	std::cout << "b="; std::cin >> b;
//
//	for (int i = a; i <= b; ++i)
//		if (Palindrom(i))
//			std::cout << i << " ";
//
//}