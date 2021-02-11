// Exercise #2
// Write a program that lets the user enter the total rainfall for each of 12 months into an array of doubles.
// The program should calculate and display the total rainfall for the year, the average monthly rainfall, and the months with the highest and lowest amounts.
// Input Validation: Do not accept negative numbers for monthly rainfall figures.

#include <iostream>
#include <limits>

void inputValues(const int SIZE, double values[]);
void printTotal(const int SIZE, double values[]);
void printAverage(const int SIZE, double values[]);
void printLargest(double largest, const int SIZE, double values[]);
void printSmallest(double smallest, const int SIZE, double values[]);

int main()
{
    //initialize size and array
    const int SIZE = 12;
    double values[SIZE];

    // initialize largest and smallest
    double largest = 0,
           smallest = 0;
  
    inputValues(SIZE, values);
    printTotal(SIZE, values);
    printAverage(SIZE, values);
    printLargest(largest, SIZE, values);
    printSmallest(smallest, SIZE, values);

    return 0;
}

void inputValues(const int SIZE, double values[])
{
    std::cout << "Enter " << SIZE << " rainfall amounts for each month (1-12)\n";
    for (int i = 0; i < SIZE; i++)
    {
        while ((std::cout << "Month " << (i+1) << ": ") && (!(std::cin >> values[i]) || values[i] < 0))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again.\n";
        }
    }
}

void printTotal(const int SIZE, double values[])
{
    double sum = 0;
    for (int i = 0; i < SIZE; i++)
    {
        sum += values[i];
    }
    std::cout << "\nThe total rainfall for the year is " << sum;
}

void printAverage(const int SIZE, double values[])
{
    double sum = 0,
           average = 0;
    for (int i = 0; i < SIZE; i++)
    {
        sum += values[i];
    }

    average = (sum / (double)SIZE);
    std::cout << "\nThe average monthly rainfall is " << average;
}

void printLargest(double largest, const int SIZE, double values[])
{
    int month = 0;
    largest = values[0];
    for (int i = 0; i < SIZE; i++)
    {
        if (values[i] > largest)
        {
            largest = values[i];
            month = (i+1);
        }
    }
    std::cout << "\nMonth " << month << " had the largest amount of rainfall (" << largest << ")";
}

void printSmallest(double smallest, const int SIZE, double values[])
{
    int month = 0;
    smallest = values[0];
    for (int i = 0; i < SIZE; i++)
    {
        if (values[i] < smallest)
        {
            smallest = values[i];
            month = (i+1);
        }
    }
    std::cout << "\nMonth " << month <<" had the smallest amount of rainfall (" << smallest << ")";
}