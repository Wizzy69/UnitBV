#include <iostream>
#include <unordered_map>


int random(int min, int max)
{
    return min + rand() % (max - min + 1);
}

std::tuple<int,int,int> normalize(std::tuple<int,int,int> t)
{
    int a = std::get<0>(t);
    int b = std::get<1>(t);
    int c = std::get<2>(t);
    if (a > b)
    {
        std::swap(a, b);
    }
    if (a > c)
    {
        std::swap(a, c);
    }
    if (b > c)
    {
        std::swap(b, c);
    }
    return std::make_tuple(a, b, c);
}

std::unordered_map<std::tuple<int,int,int>, int> generateThrows(int N)
{
    std::unordered_map<std::tuple<int, int, int>, int> throws;
    for (int i = 0; i < N; i++)
    {
        int a = random(1, 6);
        int b = random(1, 6);
        int c = random(1, 6);
        std::tuple<int, int, int> key = normalize(std::make_tuple(a, b, c));
        throws[key]++;
    }

    return throws;
}

int main()
{
    int N;
    std::cin >> N;
    auto map = generateThrows(N);

    int option;
    while(1)
    {
        std::cout << "Introduceti tripletul (sau -1 pentru a iesi)" << std::endl;
        int a, b, c;
        if(a == -1) break;
        std::cin >> a >> b >> c;
        std::tuple<int, int, int> key = normalize(std::make_tuple(a, b, c));
        std::cout << map[key] << std::endl;
    }
    return 0;
}