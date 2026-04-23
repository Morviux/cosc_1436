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
/// @return The user's menu selection.
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

/// @brief Locates the largest integer within the array. 
/// @param values Array (pointer) to the integers to search; must refer to at least 'size' elements.
/// @param size Number of elements within the array; should be > 0.
/// @return The largest integer found in the array.
int GetLargestValue(int values[], int size)
{
    int largest = values[0];
    for (int i = 1; i < size; i++)
    {
        if (values[i] > largest)
            largest = values[i];
    }
    return largest;
}

/// @brief Locates the smallest integer within the array.
/// @param values Array (pointer) to the integers to search; must refer to at least 'size' elements. 
/// @param size Number of elements within the array; should be > 0.
/// @return The smallest integer found in the array.
int GetSmallestValue(int values[], int size)
{
    int smallest = values[0];
    for (int i = 1; i < size; i++)
    {
        if (values[i] < smallest)
            smallest = values[i];
    }
    return smallest;
}

/// @brief Prompts the user to enter numberical values greater than 0.
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

/// @brief Calculates the mean of the elements within the array.
/// @param values Array of integers to calculate the mean from.
/// @param size The number of values within the array.
/// @return The mean of the calculation in a double.
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

/// @brief Displays the values stored in the array.
/// @param values Array of integers to display.
/// @param size The number of elements in the array.
void DisplayValues(int values[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << values[i] << "\t";
        
        if ((i + 1) % 10 == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

/// @brief Prompts the user to insert / add a new value into the array.
/// @param values Array of integers in the array
/// @param size The maximum amount the array can hold. 
/// @param count The current amount of elements the user inserted.
void InsertValues(int values[], int size, int& count)
{
    while (count < size)
    {
        int input; 
        std::cout << "Enter a value (or 0 to stop): ";
        std::cin >> input;

        if (input == 0)
            break;

        if (input < 0)
        {
            std::cout << "Please, enter a value greater than or equal to 0." << std::endl;
            continue;
        }
        
        values[count] = input; 
        count++;
    }
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
                std::cout << "Largest = " << GetLargestValue(numbers, count) << std::endl;
                break;

            case 's': case 'S':
                std::cout << "Smallest = " << GetSmallestValue(numbers, count) << std::endl;
                break; 

            case 'm': case 'M':
                std::cout << std::fixed << std::setprecision(4); 
                std::cout << "Mean = " << GetMean(numbers, count) << std::endl;
                break;

            case 'v': case 'V':
                DisplayValues(numbers, count); 
                break;
                
            case 'i': case 'I':
            case 'a': case 'A':
                InsertValues(numbers, 100, count);
                break;
        }
    } while (choice != 'q' && choice != 'Q');

}

/*This was actually easier to do than lab 3. 
I understood arrays better than the previous unit, plus, the table was very, VERY easy to make.
Considering that i HEAVILY referenced the Movielibrary.cpp file to make the menu table, of course.
*/