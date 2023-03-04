#include <iostream>
#include <fstream>
#include <vector>

void citireIntervale(std::string fileName, std::vector<std::pair<int,int>> &vector)
{
    std::ifstream file(fileName);
    int x,y;
    while(!file.eof())
    {
        file>>x>>y;
        vector.push_back(std::make_pair(x,y));
    }

    file.close();
}


void sortIntervale(std::vector<std::pair<int,int>> &vector)
{
    for(int i = 0; i < vector.size(); i++)
    {
        for(int j = i + 1; j < vector.size(); j++)
        {
            if(vector[i].first > vector[j].first)
                std::swap(vector[i], vector[j]);
        }
    }
}
std::pair<int, int> interval(std::vector<std::pair<int,int>> vector, int nr)
{
    std::pair<int, int> interval;
    for(int i=0;i<vector.size();++i)
    {
        if(vector[i].first<=nr && vector[i].second>=nr)
        {
            interval = vector[i];
            break;
        }
    }

    for(int i=0;i<vector.size();++i)
    {
        if(vector[i].first<=nr && vector[i].second>=nr)
        {
            if(vector[i].second - vector[i].first < interval.second - interval.first)
                interval = vector[i];
        }
    }

    return interval;

}
int main()
{
    std::vector<std::pair<int,int>> vector;
    citireIntervale("intervale.txt", vector);
    sortIntervale(vector);

    int nr;
    std::cin>>nr;

    std::pair<int,int> i = interval(vector, nr);
    std::cout<<i.first<<" "<<i.second;


    return 0;

}