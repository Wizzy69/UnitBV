#include <unordered_set>
#include <iostream>
#include <fstream>

bool permutare(std::unordered_set<char> sir1, std::unordered_set<char> sir2)
{
    if (sir1.size() != sir2.size())
        return false;
    for (auto it = sir1.begin(); it != sir1.end(); it++)
    {
        if (sir2.find(*it) == sir2.end())
            return false;
    }
    return true;
}

std::vector<char> citireSir(std::string fileName)
{
    std::ifstream file(fileName);
    std::vector<char> sir;
    char c;
    while (file >> c)
    {
        sir.push_back(c);
    }
    return sir;

}

int main()
{
    std::vector<char> sir1 = citireSir("sir1.txt");
    std::vector<char> sir2 = citireSir("sir2.txt");

    std::unordered_set<char> sir1Set(sir1.begin(), sir1.end());
    std::unordered_set<char> sir2Set(sir2.begin(), sir2.end());

    if (permutare(sir1Set, sir2Set))
        std::cout << "Sirurile sunt permutari";
    else
        std::cout << "Sirurile nu sunt permutari";
    return 0;
}