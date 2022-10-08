//#include <iostream>
//
//bool verificare_progresie_aritmetica(int n)
//{
//	if (n < 100) return true;
//	int ratie = n % 10 - (n / 10) % 10;
//	n /= 10;
//	while (n > 9)
//	{
//		if (ratie != n % 10 - (n / 10) % 10)
//			return false;
//		n /= 10;
//	}
//	return true;
//}
//
//// Se tine cont de ordinea in care sunt scrise, astfel daca n = 1243
//// Atunci cifrele lui n NU sunt in progresie aritmetica (dar daca nu se tine cont de ordine atunci ele pot
//// fi in progresie - 1234 sau 4321)
//
//void main()
//{
//	int n;
//	std::cout << "n="; std::cin >> n;
//	if (verificare_progresie_aritmetica(n))
//		std::cout << "Cifrele lui n formeaza o progresie aritmetica";
//	else std::cout << "Cifrele lui n nu formeaza o progresie aritmetica";
//}