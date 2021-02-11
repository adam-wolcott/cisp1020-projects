// Exercise #12
// A teacher has five students who have  taken four tests.
// The teacher uses the following grading scale to assign a letter grade to a student, based on the average of his or her four test scores:
// ===============================
//  Test Score       Letter Grade
// -------------------------------
//  90-100           A
//  80-89            B
//  70-79            C
//  60-69            D
//  0-59             F
// ===============================
// Write a program that uses an array of string objects to hold the five student names, an array of five characters to hold the five students' letter grades, and five arrays of four doubles to hold each student's set of test scores.
// The program should allow the user to enter each student's name and his or her four test scores.
// It should then calculate and display each student's average test score, and letter grade based on the average.
// Input Validation: Do not accept test scores less than 0 or greater than 100.

#include <iostream>
#include <string>
#include <iomanip>

void getInput(const int NUMBER_OF_TESTS, std::string student_names[], double test_scores[]);
bool stringValidation(std::string& student_names);
double doubleValidation(double score);
void calculateAndDisplay(const int NUMBER_OF_TESTS, std::string student_names[], double test_scores[], char grades[]);
char findLetter(double average);

int main()
{
    const int NUMBER_OF_STUDENTS = 5,
              NUMBER_OF_TESTS = 4;
    std::string student_names[NUMBER_OF_STUDENTS];  
    double test_scores1[NUMBER_OF_TESTS],
           test_scores2[NUMBER_OF_TESTS],
           test_scores3[NUMBER_OF_TESTS],
           test_scores4[NUMBER_OF_TESTS],
           test_scores5[NUMBER_OF_TESTS];
    char grades[NUMBER_OF_STUDENTS];

    std::cout << "\n\nEnter student testing information: ";

    getInput(NUMBER_OF_TESTS, student_names, test_scores1);
    getInput(NUMBER_OF_TESTS, student_names, test_scores2);
    getInput(NUMBER_OF_TESTS, student_names, test_scores3);
    getInput(NUMBER_OF_TESTS, student_names, test_scores4);
    getInput(NUMBER_OF_TESTS, student_names, test_scores5);

    std::cout << "\n\n" << std::setw(20) << std::left << "Name" << std::right << " | ";
    std::cout << std::setw(10) << std::left << "Avg" << std::right << " | ";
    std::cout << std::setw(10) << std::left << "Grade" << std::endl;
    std::cout << std::setfill('=')  << std::setw(40) << "=";
    std::cout << std::setfill(' ');
    
    calculateAndDisplay(NUMBER_OF_TESTS, student_names, test_scores1, grades);
    calculateAndDisplay(NUMBER_OF_TESTS, student_names, test_scores2, grades);
    calculateAndDisplay(NUMBER_OF_TESTS, student_names, test_scores3, grades);
    calculateAndDisplay(NUMBER_OF_TESTS, student_names, test_scores4, grades);
    calculateAndDisplay(NUMBER_OF_TESTS, student_names, test_scores5, grades);

    std::cout << std::endl;

    return 0;
}

void getInput(const int NUMBER_OF_TESTS, std::string student_names[], double test_scores[])
{
    static int n = 0;
    std::cout << "\n\nStudent #" << n+1 << " name: ";
    std::getline(std::cin, student_names[n]);

    while (!stringValidation(student_names[n]) || student_names[n].length() > 20)
    {
        std::cout << "\nInvalid input! Letters and spaces only. 20 char limit. : ";
        std::getline(std::cin, student_names[n]);
    }

    for (int i = 0; i < NUMBER_OF_TESTS; i++)
    {
        std::cout << "\n" << student_names[n] << "'s test #" << i+1 << " score: ";
        test_scores[i] = doubleValidation(test_scores[i]);
    }

    n++;
}

bool stringValidation(std::string& student_names)
{
    for (const char c : student_names)
    {
        if (!isalpha(c) && !isspace(c))
            return false;
    }

    return true;
}

double doubleValidation(double score)
{
    while (!(std::cin >> score) || score < 0 || score > 100)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nInvalid input. Try again: ";
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return score;
}

void calculateAndDisplay(const int NUMBER_OF_TESTS, std::string student_names[], double test_scores[], char grades[])
{
    static int n = 0;
    double sum = 0.0,
           average = 0.0;

    for (int i = 0; i < NUMBER_OF_TESTS; i++)
    {
        sum += test_scores[i];
    }
    average = (sum / (double)NUMBER_OF_TESTS);

    grades[n] = findLetter(average);

    std::cout << "\n" << std::setw(20) << std::left << student_names[n] << std::right << " | ";
    std::cout << std::setw(10) << std::left << average << std::right << " | ";
    std::cout << std::setw(10) << std::left << grades[n];
    
    n++;
}

char findLetter(double average)
{
    if (average > 79 && average < 90)
        return 'B';
    else if (average > 69 && average < 80)
        return 'C';
    else if (average > 59 && average < 70)
        return 'D';
    else if ( average < 60)
        return 'F';
    else
        return 'A';
}