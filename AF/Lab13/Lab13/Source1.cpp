#include <iostream>
#include <vector>

int cautare(const std::vector<int>& vector, int pozCurenta)
{
	if (pozCurenta >= vector.size()) return 0;
	int suma1 = vector[pozCurenta] + cautare(vector, pozCurenta + 2);
	int suma2 = vector[pozCurenta] + cautare(vector, pozCurenta + 3);

	return std::max(suma1, suma2);
}

int main()
{
	std::vector<int> vector = { 6,7,1,3,8,2,4 };
	std::cout << std::max(cautare(vector, 0), cautare(vector, 1));
	return 0;
}