/*
Lab 4 
Demetris L. Lincoln
COSC 1436 - Spring 2026
*/

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

/// @brief A menu table for the user to see / utilize.
/// @return The user's menu selection
char DisplayMenu()
{
    char choice;
    
    std::cout << "Main Menu" << std::endl;
    std::cout << std::setfill('-')
        << std::setw(19)
        << "" << std::setfill(' ') 
        << std::endl;
    std::cout << "A) dd" << std::endl;
    std::cout << "L) argest" << std::endl;
    std::cout << "M) ean" << std::endl;
    std::cout << "S) mallest" << std::endl;
    std::cout << "I) nsert" << std::endl;
    std::cout << "V) iew" << std::endl;
    std::cout << "Q) uit" << std::endl;
    std::cin >> choice;

    while (choice != 'a' && choice != 'A' &&
           choice != 'l' && choice != 'L' &&
           choice != 'm' && choice != 'M' &&
           choice != 's' && choice != 'S' &&
           choice != 'i' && choice != 'I' &&
           choice != 'v' && choice != 'V' &&
           choice != 'q' && choice != 'Q')

    {
        std::cout << "Invalid option, please try again: ";
        std::cin >> choice;
    }

    return choice;
}

/// @brief Finds the largest integer in an array.
/// @param values Array (pointer) to the integers to search; must refer to at least 'size' elements.
/// @param size Number of elements within the array; should be > 0.
/// @return The largest integer found in the array.
int GetLargest(int values[], int size)
{
    int largest = values[0];
    for (int i = 1; i < size; i++)
    {
        if (values[i] > largest)
            largest = values[i];
    }
    return largest;
}

/// @brief Finds the smallest integer in an array
/// @param values Array (pointer) to the integers to search; must refer to at least 'size' elements. 
/// @param size Number of elements within the array; should be > 0
/// @return The smallest integer found in the array
int GetSmallest(int values[], int size)
{
    int smallest = values[0];
    for (int i = 1; i < size; i++)
    {
        if (values[i] < smallest)
            smallest = values[i];
    }
    return smallest;
}

/// @brief Function that prompts the user a single or multiple numerical inputs.
/// @param values Numerical values that are not negative numbers or < 0.
/// @param size The maximum number of values the array can hold.
/// @return The number of values entered by the user.
int GetNumbers(int values[], int size)
{
    int count = 0;

    while (count < size)
    {
        int input;
        std::cout << "Enter a value (or 0 to stop): ";
        std::cin >> input;

        if (input == 0)
        break;

        if (input < 0)
        {
            std::cout << "Please, enter a value that is greater than or equal to 0" << std::endl;
            std::cout << std::endl;
            continue;
        }

        values[count] = input;
        count++;
    }

    return count;

}

/// @brief Function to calculate the mean of the numbers provided. 
/// @param values 
/// @param size The number of values within the array
/// @return The mean of the calculation. 
double GetMean(int values[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += values[i];

    return static_cast<double>(sum) / size;
}

/// @brief Displays the program information 
void DisplayProgramInfo()
{
    std::cout << "Lab Four" << std::endl;
    std::cout << "Demetris Lincoln" << std::endl;
    std::cout << "COSC 1436 - Spring 2026" << std::endl;
    std::cout << std::endl;
}


void main()
{
    DisplayProgramInfo();

    int numbers[100];
    int count = GetNumbers(numbers, 100);

    char choice;
    do
    {
        choice = DisplayMenu();
        
        switch (choice)
        {
            case 'l': case 'L':
                std::cout << "Largest = " << GetLargest(numbers, count) << std::endl;
                break;

            case 's': case 'S':
                std::cout << "Smallest = " << GetSmallest(numbers, count) << std::endl;
                break; 

            case 'm': case 'M':
                std::cout << std::fixed << std::setprecision(4); 
                std::cout << "Mean = " << GetMean(numbers, count) << std::endl;
                break;
        }
    } while (choice != 'q' && choice != 'Q');

}