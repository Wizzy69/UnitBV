#include <iostream>
int rasturnat(int valoare)
{
	int rasturnat = 0;
	while (valoare)
	{
		rasturnat = rasturnat * 10;
		rasturnat += valoare % 10;
		valoare /= 10;
	}
	return rasturnat;

}

int rezolvare(int n) {
	int val1, nrvalori = 0, valoare;
	std::cin >> val1;
	for (int i = 1; i < n; ++i) {
		std::cin >> valoare;
		if (rasturnat(valoare) == val1)
			nrvalori++;
	}
	return nrvalori;
}

//int main()
//{
//	int a = 10; //10
//	int b = 10 >> 2;
//	std::cout << b;
//	return 0;
//}