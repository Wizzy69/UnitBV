#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <sstream>

std::list<std::string> split(std::string line, char delimiter)
{
    std::list<std::string> tokens;
    std::string token;
    std::stringstream tokenStream(line);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}
std::unordered_map<std::string, std::list<std::pair<std::string, std::string>>> getCompetitionParticipants()
{
    std::unordered_map<std::string, std::list<std::pair<std::string, std::string>>> competitionParticipants;
    std::ifstream file("competitie.txt");
    std::string competitionName, firstName, lastName;
    while(!file.eof())
    {
        std::string line;
        std::getline(file, line);
        std::list<std::string> tokens = split(line, ' ');
        competitionName = tokens.front();
        tokens.pop_front();
        while(!tokens.empty())
        {
            firstName = tokens.front();
            tokens.pop_front();
            lastName = tokens.front();
            tokens.pop_front();
            competitionParticipants[competitionName].push_back(std::make_pair(firstName, lastName));
        }
    }
    return competitionParticipants;

}

std::unordered_map<std::pair<std::string, std::string>, int> NumberOfCompetitionParticipants(std::unordered_map<std::string, std::list<std::pair<std::string, std::string>>> competitionParticipants)
{
    std::unordered_map<std::pair<std::string, std::string>, int> numberOfCompetitionParticipants;
    for(auto it = competitionParticipants.begin(); it != competitionParticipants.end(); it++)
    {
        for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
        {
            numberOfCompetitionParticipants[*it2]++;
        }
    }
    return numberOfCompetitionParticipants;
}

int main()
{
    auto competitionParticipants = getCompetitionParticipants();
    auto numberOfCompetitionParticipants = NumberOfCompetitionParticipants(competitionParticipants);
    for(auto it = numberOfCompetitionParticipants.begin(); it != numberOfCompetitionParticipants.end(); it++)
    {
        if(it->second > 1)
            std::cout << it->first.first << " " << it->first.second << " " << it->second << std::endl;
    }
    return 0;
}