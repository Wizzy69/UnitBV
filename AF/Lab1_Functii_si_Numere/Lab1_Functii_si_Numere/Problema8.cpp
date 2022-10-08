#include <iostream>


int eliminare_cifre(int n, int c)
{
	int new_nr = 0, putere = 1;
	while (n)
	{
		if (n % 10 != c)
			new_nr = (n % 10) * putere + new_nr,
			putere *= 10;
		n /= 10;
	}

	return new_nr;
}

//void main()
//{
//	int n, c;
//	std::cout << "n="; std::cin >> n;
//	std::cout << "c="; std::cin >> c;
//
//	int nr_fara_c = eliminare_cifre(n, c);
//	std::cout << "Numarul rezultat este: " << nr_fara_c;
//
//}