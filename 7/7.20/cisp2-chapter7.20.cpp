// Exercise #20
// In the student sample programs for this book, you will find a text file named 1994_Weekly_Gas_Averages.txt.
// The file contains the average gas price for each week in the year 1994. 
// (There are 52 lines in the file. Line 1 contains the average price for week 1, line 2 contains the average price for week 2, and so forth.)
// Write a program that reads the gas prices from the file into an array or vector. The program should do the following:
//
// * Display the lowest average price of the year, along with the week number for that price, and the name of the month in which it occurred.
// * Display the highest average price of the year, along with the week number for  that price and the name of the month in which it occured.
// * Display the average gas price for each month.
// (To get the average price for a given month, calculate the average of the average weekly prices for that month.)

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

void fileToVector(std::string file_name, const int NUMBER_OF_WEEKS, std::vector<double>& prices);
void displayLowest(std::vector<double>& prices);
void displayHighest(std::vector<double>& prices);
void displayAverage(std::vector<double>& prices);
std::string findMonth(int week);

int main()
{
    const int NUMBER_OF_WEEKS = 52;
    std::string file_name = "1994_Weekly_Gas_Averages.txt";
    std::vector<double> prices;

    fileToVector(file_name, NUMBER_OF_WEEKS, prices);

    displayLowest(prices);

    displayHighest(prices);

    displayAverage(prices);

    std::cout << std::endl;
    return 0;
}

void fileToVector(std::string file_name, const int NUMBER_OF_WEEKS, std::vector<double>& prices)
{
    std::ifstream inputFile;
    inputFile.open(file_name);
    if (inputFile.is_open())
    {
        std::string line;
        double price;

        while (std::getline(inputFile, line))
        {
            price = stod(line);
            prices.push_back(price);
        }
    }
    else
    {
        std::cout << "\n\nFile not found. Restart the program.";
    }

    inputFile.close();
}

void displayLowest(std::vector<double>& prices)
{
    double lowest = prices[0];
    int week = 1;
    std::string month;

    for (size_t i = 0; i < prices.size(); i++)
    {
        if (prices[i] < lowest)
        {
            lowest = prices[i];
            week = i+1;
        }
    }

    month = findMonth(week);

    std::cout << "\nThe lowest average price was $" << lowest << " in week " << week << " (" << month << ").";
}

void displayHighest(std::vector<double>& prices)
{
    double highest = prices[0];
    int week = 1;
    std::string month;

    for (size_t i = 0; i < prices.size(); i++)
    {
        if (prices[i] > highest)
        {
            highest = prices[i];
            week = i+1;
        }
    }

    month = findMonth(week);

    std::cout << "\nThe highest average price was $" << highest << " in week " << week << " (" << month << ").";
}

void displayAverage(std::vector<double>& prices)
{
    double sum = 0.00,
           average = 0.00;
    for (size_t i = 0; i < prices.size(); i++)
    {
        sum += prices[i];
        switch (i)
        {
        case 5:
            average = (sum / 5.00);
            std::cout << "\n" << std::left << std::setw(25) << findMonth(i) + "'s average: " << "$" << std::setprecision(4) << average;
            sum = 0.00;
            break;
        case 9:
            average = (sum / 4.00);
            std::cout << "\n" << std::left << std::setw(25) << findMonth(i) + "'s average: " << "$" << std::setprecision(4) << average;
            sum = 0.00;
            break;
        case 14:
            average = (sum / 4.00);
            std::cout << "\n" << std::left << std::setw(25) << findMonth(i) + "'s average: " << "$" << std::setprecision(4) << average;
            sum = 0.00;
            break;
        case 18:
            average = (sum / 4.00);
            std::cout << "\n" << std::left << std::setw(25) << findMonth(i) + "'s average: " << "$" << std::setprecision(4) << average;
            sum = 0.00;
            break;
        case 23:
            average = (sum / 5.00);
            std::cout << "\n" << std::left << std::setw(25) << findMonth(i) + "'s average: " << "$" << std::setprecision(4) << average;
            sum = 0.00;
            break;
        case 27:
            average = (sum / 4.00);
            std::cout << "\n" << std::left << std::setw(25) << findMonth(i) + "'s average: " << "$" << std::setprecision(4) << average;
            sum = 0.00;
            break;
        case 31:
            average = (sum / 4.00);
            std::cout << "\n" << std::left << std::setw(25) << findMonth(i) + "'s average: " << "$" << std::setprecision(4) << average;
            sum = 0.00;
            break;
        case 36:
            average = (sum / 5.00);
            std::cout << "\n" << std::left << std::setw(25) << findMonth(i) + "'s average: " << "$" << std::setprecision(4) << average;
            sum = 0.00;
            break;
        case 40:
            average = (sum / 4.00);
            std::cout << "\n" << std::left << std::setw(25) << findMonth(i) + "'s average: " << "$" << std::setprecision(4) << average;
            sum = 0.00;
            break;
        case 44:
            average = (sum / 4.00);
            std::cout << "\n" << std::left << std::setw(25) << findMonth(i) + "'s average: " << "$" << std::setprecision(4) << average;
            sum = 0.00;
            break;
        case 48:
            average = (sum / 4.00);
            std::cout << "\n" << std::left << std::setw(25) << findMonth(i) + "'s average: " << "$" << std::setprecision(4) << average;
            sum = 0.00;
            break;
        case 52:
            average = (sum / 4.00);
            std::cout << "\n" << std::left << std::setw(25) << findMonth(i) + "'s average: " << "$" << std::setprecision(4) << average;
            sum = 0.00;
            break;
        }
    }
}

std::string findMonth(int week)
{
    switch (week)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        return ("January");
    case 6:
    case 7:
    case 8:
    case 9:
        return ("February");
    case 10:
    case 11:
    case 12:
    case 14:
        return ("March");
    case 15:
    case 16:
    case 17:
    case 18:
        return ("April");
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
        return ("May");
    case 24:
    case 25:
    case 26:
    case 27:
        return ("June");
    case 28:
    case 29:
    case 30:
    case 31:
        return ("July");
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
        return ("August");
    case 37:
    case 38:
    case 39:
    case 40:
        return ("September");
    case 41:
    case 42:
    case 43:
    case 44:
        return ("October");
    case 45:
    case 46:
    case 47:
    case 48:
        return ("November");
    case 49:
    case 50:
    case 51:
    case 52:
        return ("December");
    }
}