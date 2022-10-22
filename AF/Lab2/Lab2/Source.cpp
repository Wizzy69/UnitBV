#include <iostream>
#include <vector>

void citire(std::vector<int>& vector, const int dimensiune)
{
	for (int i = 0; i < dimensiune; ++i)
	{
		int x;
		std::cin >> x;
		vector.push_back(x);
	}
}

void afisare(const std::vector<int> vector)
{
	for (auto element : vector)
		std::cout << element << " ";
}

void main()
{
	int dimensiune, k;
	std::vector<int> vector;
	std::cin >> dimensiune >> k;
	vector.resize(k);
	citire(vector, dimensiune);
	afisare(vector);
}
