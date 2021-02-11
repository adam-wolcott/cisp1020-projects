// Exercise #6
// An amatuer meteorologist wants to keep track of weather conditions during the past year's three-month summer season, and has designated each day as either rainy ('R'), cloudy ('C'), or sunny ('S').
// Write a program that stores this information in a 3 x 30 array of characters, where the row indicates the month (0 = June, 1 = July, 2 = August) and the column indicates the day of the month.
// Note data are not being collected for the 31st of any month.
// The program should begin by reading the weather data in from a file.
// Then it should create a report that displays, for each month and for the whole three- month period, how many days were rainy, how many days were cloudy, and how many were sunny.
// It should also report which of the three months had the largest number of rainy days. Data for the program can be found in the RainOrShine.txt file.

#include <iostream>
#include <fstream>

void fileToArray(char summer[3][30], const int MONTHS, const int DAYS);
void processArray(int report[3][3], char summer[3][30], const int MONTHS, const int WEATHER);

int main()
{
    // initialize
    const int MONTHS  = 3,
              DAYS    = 30,
              WEATHER = 3; // types of weather. rainy, cloudy, sunny...

    char summer[MONTHS][DAYS]; //array text file will be processed to

    //total weather to month data   J  J  A
    int report[MONTHS][WEATHER] = { 0, 0, 0,    // R 
                                    0, 0, 0,    // C    overwrite garbage
                                    0, 0, 0 };  // S
    
    // load file into array
    fileToArray(summer, MONTHS, DAYS);
    // process array and display report
    processArray(report, summer, MONTHS, DAYS);
    
    return 0;
}

void fileToArray(char summer[3][30], const int MONTHS, const int DAYS)
{
    std::ifstream inputFile;

    // load file
    inputFile.open("RainOrShine.txt");

    // read file into array
    if (inputFile.is_open())
    {
        for (int i = 0; i < MONTHS; i++)
        {
            for (int j = 0; j < DAYS; j++)
            {
                inputFile >> summer[i][j];
            }
        }
    }
    else
    {
        std::cout << "\nFile not found. Restart the program.";
    }

    // close file
    inputFile.close();
}

void processArray(int report[3][3], char summer[3][30], const int MONTHS, const int DAYS)
{
    
    int tr = 0, // total rainy
        tc = 0, // total cloudy
        ts = 0, // total sunny
        mr = 0, // most rain
        month = 0;

    mr = report[0][0]; // overwrite garbage

    // month loop
    for (int i = 0; i < MONTHS; i++)
    {
        // day loop
        for (int j = 0; j < DAYS; j++)
        {
            // convert weather data from char summer array to int report array
            switch (summer[i][j])
            {
            case 'R':
                report[i][0]++;
                break;
            case 'C':
                report[i][1]++;
                break;
            case 'S':
                report[i][2]++;
                break;
            }
        }

        // calculate and store totals for each weather type
        for (int j = 0; j < 3; j++)
        {
            switch (j)
            {
            case 0:
                tr += report[i][j];
                break;
            case 1:
                tc += report[i][j];
                break;
            case 2:
                ts += report[i][j];
                break;
            }
        }

        // calculate month with highest amount of rain
        if (report[i][0] > mr)
        {
            month = i;
            mr = report[i][0];
        }

        // display message depending on which month is being processed
        switch (i)
        {
        case 0:
            std::cout << "\nJune had " << report[i][0] << " rainy days, " << report[i][1] << " cloudy days, and " << report[i][2] << " sunny days.";
            break;
        case 1:
            std::cout << "\nJuly had " << report[i][0] << " rainy days, " << report[i][1] << " cloudy days, and " << report[i][2] << " sunny days.";
            break;
        case 2:
            std::cout << "\nAugust had " << report[i][0] << " rainy days, " << report[i][1] << " cloudy days, and " << report[i][2] << " sunny days.";
            break;
        }

    }

    // display total
    std::cout << "\n\nThere were a total of " << tr << " rainy days, " << tc << " cloudy days, and " << ts << " sunny days.";

    // display most rainy month
    switch (month)
    {
    case 0:
        std::cout << "\nJune had the most rain (" << report[month][0] << " days)." << std::endl;
        break;
    case 1:
        std::cout << "\nJuly had the most rain (" << report[month][0] << " days)." << std::endl;
        break;
    case 2:
        std::cout << "\nAugust had the most rain (" << report[month][0] << " days)." << std::endl;
        break;
    }
}