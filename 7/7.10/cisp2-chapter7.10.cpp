// Exercise #10
// The local Driver's License Office has asked you to write a program that grades the written portion of the driver's license exam.
// The exam has 20 multiple-choice questions.
// Here are the correct answers:
//
// 1. A     6. B    11. A   16. C
// 2. D     7. A    12. C   17. C
// 3. B     8. B    13. D   18. A
// 4. B     9. C    14. B   19. D
// 5. C    10. D    15. D   20. B
//
// Your program should store the correct answers shown above in an array.
// It should ask the user to enter the student's answers for each of the 20 questions, and the answers should be stored in another array.
// After the student's answers have been entered, the program should display a message indicating whether the student passed or failed the exam.
// (A student must correctly answer 15 out of the 20 questions to pass the exam.)
// It should then display the total number of correctly answered questions, the total number of incorrectly answered questions, and a list showing the question numbers of the incorrectly answered questions.
// Input Validation: Only accept the letters A, B, C, or D as answers.

#include <iostream>
#include <vector>
#include <cctype>
#include <conio.h>

void getAnswers(char student[], const int NUMBER_OF_QUESTIONS);
char inputValidation(char answer);
void checkAnswers(const char student[], const char key[], int& correct, std::vector<int>& track_incorrect, const int NUMBER_OF_QUESTIONS);
void displayResults(const int correct, const char student[], const char key[], std::vector<int> track_incorrect, const int NUMBER_OF_QUESTIONS);
void displayVector(std::vector<int> vector, std::string vector_name);

int main()
{
    const int NUMBER_OF_QUESTIONS = 20;
    int correct = 0;
    char key[NUMBER_OF_QUESTIONS] = { 'A', 'D', 'B', 'B', 'D',
                                      'B', 'A', 'B', 'C', 'D',
                                      'A', 'C', 'D', 'B', 'D',
                                      'C', 'C', 'A', 'D', 'B' };

    char student[NUMBER_OF_QUESTIONS];
    std::vector<int> track_incorrect;
    
    getAnswers(student, NUMBER_OF_QUESTIONS);
    checkAnswers(student, key, correct, track_incorrect, NUMBER_OF_QUESTIONS);
    displayResults(correct, student, key, track_incorrect, NUMBER_OF_QUESTIONS);

    std::cout << std::endl;
    return 0;
}

void getAnswers(char student[], const int NUMBER_OF_QUESTIONS)
{
    std::cout << "\n__Driver's_License_Exam__";
    std::cout << "\n\nEnter answers for " << NUMBER_OF_QUESTIONS << " questions.";
    for (int i = 0; i < NUMBER_OF_QUESTIONS; i++)
    {
        std::cout << "\n#" << (i + 1) << ": ";
        student[i] = inputValidation(student[i]);
    }
}

char inputValidation(char answer)
{
    bool valid = true;

    answer = _getche();
    while (valid)
    {
        switch (answer)
        {
        case 'a':
        case 'A':
        case 'b':
        case 'B':
        case 'c':
        case 'C':
        case 'd':
        case 'D':
            valid = false;
            break;

        default:
            std::cout << "\nInvalid input. \nMust enter A, B, C, or D: ";
            answer = _getche();
            break;
        }
    }

    return toupper(answer);
}

void checkAnswers(const char student[], const char key[], int &correct, std::vector<int> &track_incorrect, const int NUMBER_OF_QUESTIONS)
{
    for (int i = 0; i < NUMBER_OF_QUESTIONS; i++)
    {
        if (student[i] == key[i])
            correct++;
        else
            track_incorrect.push_back(i+1);
    }
}

void displayResults(const int correct, const char student[], const char key[], std::vector<int> track_incorrect, const int NUMBER_OF_QUESTIONS)
{
    std::cout << "\n\nResults: " << (correct >= 15 ? "PASS" : "FAIL");
    std::cout << "\nTotal correct: " << correct;
    std::cout << "\nTotal incorrect: " << NUMBER_OF_QUESTIONS - correct;
    if (correct < 20)
    {
        displayVector(track_incorrect, "\nIncorrect questions: ");
    }
}

void displayVector(std::vector<int> vector, std::string vector_name)
{
    std::cout << vector_name << std::endl;
    for (int i = 0; i < vector.size(); i++)
    {
        if (i == (vector.size() - 1))
            std::cout << "#" << vector[i];
        else
            std::cout << "#" << vector[i] << ", ";
    }
}