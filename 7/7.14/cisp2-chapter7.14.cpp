// Exercise #14
// Write a program that simulates a lottery.
// The program should have an array of five integers named lottery and should generate a random number in the range of 0 through 9 for each element in the array.
// The user should enter five digits, which should be stored in an integer array named user.
// The program is to compare the corresponding elements in the two arrays and keep a count of the digits that match.
// For example, the following shows the lottery array and the user array with sample numbers stored in each.
// There are two matching digits (elements 2 and 4).
//
// Lottery array:
// [7][4][9][1][3]
//
// User array:
// [4][2][9][7][3]
//
// The program should display the random numbers stored in the lottery array and the number of matching digits.
// If all of the digits match, display a message proclaiming the user as a grand prize winner.

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateLottery(const int SIZE, int lottery[]);
void assignUser(const int SIZE, int user[]);
int compareArray(const int SIZE, int array1[], int array2[]);
void displayResults(const int SIZE, int matching, int lottery[]);

int main()
{
    const int SIZE = 5;
    int lottery[SIZE],
        user[SIZE],
        matching;

    srand(time(NULL));

    generateLottery(SIZE, lottery);

    assignUser(SIZE, user);

    matching = compareArray(SIZE, lottery, user);

    displayResults(SIZE, matching, lottery);

    std::cout << std::endl;

    return 0;
}

void generateLottery(const int SIZE, int lottery[])
{
    for (int i = 0; i < SIZE; i++)
    {
        lottery[i] = rand() % 9 + 0;
    }
}

void assignUser(const int SIZE, int user[])
{
    for (int i = 0; i < SIZE; i++)
    {
        while ((std::cout << "\n\nPick #" << i+1 << ": ") && (!(std::cin >> user[i]) || user[i] < 0 || user[i] > 9))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again. \n";
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int compareArray(const int SIZE, int array1[], int array2[])
{
    int n = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (array1[i] == array2[i])
            n++;
    }
    return n;
}

void displayResults(const int SIZE, int matching, int lottery[])
{
    std::cout << "\n";

    for (int i = 0; i < SIZE; i++)
        std::cout << "[" << lottery[i] << "]";

    std::cout << "\nYou matched " << matching << " lottery numbers.";
    
    switch (matching)
    {
    case 5:
        std::cout << "\n\nYou are the grand prize winner!";
        break;
    default:
        std::cout << "\n\nYou are not the grand prize winner.";
    }
}