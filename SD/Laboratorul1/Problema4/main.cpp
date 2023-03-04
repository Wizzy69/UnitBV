#include <iostream>
#include <cmath>

bool inAcelasiCadran(std::pair<float,float> p1, std::pair<float,float> p2)
{
    if(p1.first > 0 && p2.first > 0)
        return true;
    if(p1.first < 0 && p2.first < 0)
        return true;
    if(p1.second > 0 && p2.second > 0)
        return true;
    if(p1.second < 0 && p2.second < 0)
        return true;
    return false;
}

float distantaEuclidiana(std::pair<float,float> p1, std::pair<float,float> p2)
{
    return sqrt((p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second));
}

float unghiulFormatDePuncteCuOx(std::pair<float,float> p1, std::pair<float,float> p2)
{
    // atan2f returneaza unghiul in radiani
    // atan2f - 
    return atan2f(p2.second - p1.second, p2.first - p1.first);  
}

int main()
{
    std::pair<float,float> p1,p2;
    std::cin>>p1.first>>p1.second>>p2.first>>p2.second;
    if(inAcelasiCadran(p1, p2))
        std::cout<<"Punctele se afla in acelasi cadran\n";
    else
        std::cout<<"Punctele nu se afla in acelasi cadran\n";
    
    std::cout<<"Distanta euclidiana dintre punctele ("<<p1.first<<","<<p1.second<<") si ("<<p2.first<<","<<p2.second<<") este "<<distantaEuclidiana(p1, p2)<<'\n';
    std::cout<<"Unghiul format de punctele ("<<p1.first<<","<<p1.second<<") si ("<<p2.first<<","<<p2.second<<") cu Ox este de "<<unghiulFormatDePuncteCuOx(p1, p2)<< " radiani\n";
    return 0;

}