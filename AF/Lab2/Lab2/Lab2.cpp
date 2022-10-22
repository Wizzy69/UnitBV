//#include <iostream>
//#include <vector>
//
//int minim(int x)
//{
//	int min = 0;
//	while (x)
//	{
//		if (x % 10 < min)
//		{
//			min = x % 10;
//		}
//		x = x / 10;
//	}
//	return min;
//}
//
//bool isPrime(int x)
//{
//	if (x == 1)
//	{
//		return false;
//	}
//	if (x == 2)
//	{
//		return true;
//	}
//	if (x % 2 == 0)
//	{
//		return false;
//	}
//	for (int i = 3; i * i <= x; i += 2)
//	{
//		if (x % i == 0)
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//void citire(std::vector<int>& vector, int n)
//{
//	for(int i=0;i<n;++i)
//	{
//		int x;
//		std::cin >> x;
//		vector.push_back(x);
//	}
//	
//}
//
//void inlocuire(std::vector<int>& vector)
//{
//	for (int i = 0; i < vector.size(); ++i)
//	{
//		if (i % 2 == 0)
//			vector[i] = minim(vector[i]);
//		else
//			vector[i] = (int)isPrime(vector[i]);
//	}
//}
//
//void afisare(const std::vector<int>& vector)
//{
//	for (auto a : vector)
//		std::cout << a << " ";
//}
//
//void main()
//{
//	try {
//		std::vector<int> vector;
//		int n;
//		std::cout << "n="; std::cin >> n;
//		if (n < 0) throw "n<0";
//		citire(vector, n);
//		inlocuire(vector);
//		afisare(vector);
//
//	}
//	catch (std::exception e)
//	{
//		
//			std::cout << e.what();
//		
//	}
//	
//}
//
