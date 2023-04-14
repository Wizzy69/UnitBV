#include <fstream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>


std::unordered_map <std::string, std::vector<std::string>> anagrame()
{
    std::unordered_map<std::string, std::vector<std::string>> anagrame;
    std::ifstream file("anagrame.txt");
    std::string word;
    while (file >> word)
    {
        std::string sortedWord = word;
        std::sort(sortedWord.begin(), sortedWord.end());
        anagrame[sortedWord].push_back(word);
    }


    return anagrame;
}

int main()
{
    std::unordered_map<std::string, std::vector<std::string>> _anagrame = anagrame();
    for (auto it = _anagrame.begin(); it != _anagrame.end(); it++)
    {
        std::cout << it->first << ": ";
        for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
        {
            std::cout << *it2 << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}