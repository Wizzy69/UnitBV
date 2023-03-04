#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>

std::vector<std::tuple<std::string, std::string, int, int, int>> citireElevi(std::string fileName)
{
    std::ifstream file(fileName);
    std::vector<std::tuple<std::string, std::string, int, int, int>> elevi;
    std::string nume, prenume;
    int nota1, nota2, nota3;
    while(!file.eof())
    {
        file>>nume>>prenume>>nota1>>nota2>>nota3;
        elevi.push_back(std::make_tuple(nume, prenume, nota1, nota2, nota3));
    }

    file.close();

    return elevi;
}

void sortEleviDesc(std::vector<std::tuple<std::string, std::string, int, int, int>> &elevi)
{
    for(int i = 0; i < elevi.size(); i++)
    {
        for(int j = i + 1; j < elevi.size(); j++)
        {
            if((std::get<2>(elevi[i]) + std::get<3>(elevi[i]) + std::get<4>(elevi[i]))/3.0 < (std::get<2>(elevi[j]) + std::get<3>(elevi[j]) + std::get<4>(elevi[j]))/3.0)
                std::swap(elevi[i], elevi[j]);
        }
    }
}

int main()
{
    auto elevi = citireElevi("elevi.txt");
    sortEleviDesc(elevi);
    for(auto elev : elevi)
    if((std::get<2>(elev) + std::get<3>(elev) + std::get<4>(elev))/3.0 < 5.0)
        printf("%s %s %.2f\n", std::get<0>(elev).c_str(), std::get<1>(elev).c_str(), (std::get<2>(elev) + std::get<3>(elev) + std::get<4>(elev))/3.0);
        //std::cout<<std::get<0>(elev)<<" "<<std::get<1>(elev)<<" "<<(std::get<2>(elev) + std::get<3>(elev) + std::get<4>(elev))/3.0<<std::endl;
}
