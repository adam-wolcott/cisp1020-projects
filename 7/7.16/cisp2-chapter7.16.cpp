// Exercise #16
// If you have downloaded this book's source code, you will find the following files in this chapter's folder:
//
// * Teams.txt--This file contains a list of several Major League baseball teams in alphabetical order.
//   Each team listed in the file has won the World Series at least once.
// * WorldSeriesWinners.txt--This file contains a chronological list of the World Series' winning teams from 1903 to 2012.
//   (The first line in the file is the name of the team that won in 1903, and the last line is the name of the team that won in 2012.
//   Note the World Series was not played in 1904 or 1994.)
//
// Write a program that displays the contents of the Teams.txt file on the screen and prompts the user to enter the name of one of the teams.
// The program should then display the number of times that team has won the World Series in the time period from 1903 to 2012.

// TIP: Read the contents of the WorldSeriesWinners.txt file into an array or vector.
//      When the user enters the name of a team, the program should step through the array or vector counting the number of times the selected team appears.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

void fileToVector(std::string file_name, std::vector<std::string>& world_series_winners);
void displayVector(std::vector<std::string>& str_vector);
void selectTeam(std::vector<std::string>& team_list, std::string& user_input);
bool validateInput(std::vector<std::string>& team_list, std::string user_input);
void displayWins(std::vector<std::string>& winners, std::vector<int>& years, std::string user);
int tallyWins(std::vector<std::string>& winners, std::vector<int>& years, std::string user);

int main()
{
    std::string winners_file = "WorldSeriesWinners.txt",
                teams_file = "Teams.txt",
                user;

    std::vector<std::string> winners,
                             teams;

    std::vector<int> years;
    
    fileToVector(winners_file, winners);
    fileToVector(teams_file, teams);

    displayVector(teams);

    selectTeam(teams, user);

    displayWins(winners, years, user);

    std::cout << std::endl;
    return 0;
}

void fileToVector(std::string file_name, std::vector<std::string>& world_series_winners)
{
    std::ifstream inputFile;
    inputFile.open(file_name);
    if (inputFile.is_open())
    {
        std::string file_line;

        while (std::getline(inputFile, file_line))
            world_series_winners.push_back(file_line);
    }
    else
    {
        std::cout << "\n\nFile not found. Restart the program.";
    }

    inputFile.close();
}

void displayVector(std::vector<std::string>& str_vector)
{
    for (std::size_t i = 0; i < str_vector.size(); i++)
    {
        std::cout << "\n" << std::right << std::setw(2) << i + 1 << ". ";
        std::cout << std::setw(100) << std::left << str_vector[i];
    }
}

void selectTeam(std::vector<std::string>& team_list, std::string& user_input)
{
    std::cout << "\n\nType the team name you want to display data for: ";
    std::getline(std::cin, user_input);
    while (!validateInput(team_list, user_input))
    {
        std::cout << "\n" << "'" << user_input << "'" << " does not exist. Check spelling and try again. ";
        std::getline(std::cin, user_input);
    }
}

bool validateInput(std::vector<std::string>& team_list, std::string user_input)
{
    for (std::size_t i = 0; i < team_list.size(); i++)
    {
        if (user_input == team_list[i])
            return true;
    }
    return false;
}

void displayWins(std::vector<std::string>& winners, std::vector<int>& years, std::string user)
{
    std::cout << "\n\nThe " << user << " have won the World Series " << tallyWins(winners, years, user) << " times. Years: ";
    for (std::size_t i = 0; i < years.size(); i++)
    {
        if (i == (years.size() - 1))
            std::cout << (years[i] + 1903);
        else
            std::cout << (years[i] + 1903) << ", ";
    }
}

int tallyWins(std::vector<std::string>& winners, std::vector<int>& years, std::string user)
{
    int n = 0;

    for (std::size_t i = 0; i < winners.size(); i++)
    {
        if (user == winners[i])
        {
            years.push_back(i);
            n++;
        }
    }
    return n;
}
