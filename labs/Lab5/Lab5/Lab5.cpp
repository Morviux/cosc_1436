/*
Lab 5
Demetris Lincoln
COSC 1436 - Spring 2026
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>


/// @brief A struct to represent a 'stop' in the program.
struct Stop
{
    int x = 0;
    int y = 0;
};

/// @brief Adds a stop to the trip array.
/// @param stops Array of stop pointers.
/// @param size The maxiumum size of the array.
/// @param stopCount Current number of stops. 
/// @param pStop Pointer to the stop to add.
/// @return True if added successfully, false if the array is full. 
bool AddStop(Stop* stops[], int size, int& stopCount, Stop* pStop)
{
    if (stopCount >= size)
        return false;

    stops[stopCount] = pStop;
    stopCount++;
    return true;
}

/// @brief Handles the stop menu option
/// @param stops The array of stop pointers.
/// @param size Maximum size of the array.
/// @param stopCount Current number of stops. 
void HandleAddStop(Stop* stops[], int size, int& stopCount)
{
    Stop* pStop = new Stop;

    std::cout << "Enter X (-100 to 100): ";
    std::cin >> pStop->x;
    while (pStop->x < -100 || pStop->x > 100)
    {
        std::cout << "Invalid value. Enter X (-100 to 100): ";
        std::cin >> pStop->x;
    }

    std::cout << "Enter Y (-100 to 100): ";
    std::cin >> pStop->y;
    while (pStop->y < -100 || pStop->y > 100)
    {
        std::cout << "Invalid value. Enter y (-100 to 100): ";
        std::cin >> pStop->y;
    }

    if (!AddStop(stops, size, stopCount, pStop))
    {
        std::cout << "You maximized your total number of trips!" << std::endl;
        delete pStop;
        pStop = nullptr;
    }
}



/// @brief Displays the main menu for the user. 
/// @return The user's input.
char DisplayMainMenu()
{
    char choice;

    std::cout << std::endl;
    std::cout << "Main Menu" << std::endl;
    std::cout << std::setfill('-') << std::setw(20) << "" << std::setfill(' ') << std::endl;

    std::cout << "A)dd Stop" << std::endl;
    std::cout << "V)iew Trip" << std::endl;
    std::cout << "D)elete Stop" << std::endl;
    std::cout << "C)lear Trip" << std::endl;
    std::cout << "Q)uit" << std::endl;
    std::cin >> choice;

    while (choice != 'a' && choice != 'A' &&
           choice != 'v' && choice != 'V' &&
           choice != 'd' && choice != 'D' &&
           choice != 'c' && choice != 'C' &&
           choice != 'q' && choice != 'Q')

    {
        std::cout << "Invalid option, try again: ";
        std::cin >> choice; 
    }

    return choice;
}

/// @brief Prompts the user a question to leave the program.
/// @return A confirmation of the users input.
bool ConfirmQuit()
{
    char confirm;
    std::cout << "Are you sure you want to leave? (Y/N): ";
    std::cin >> confirm;

    return (confirm == 'y' || confirm == 'Y');
}


/// @brief Displays the program information
void DisplayProgramInfo()
{
    std::cout << "Lab Five - Managing a Planned Trip" << std::endl;
    std::cout << "Demetris Lincoln" << std::endl;
    std::cout << "COSC 1436 - Spring 2026" << std::endl;
}

void main()
{
    char choice;
    bool quit = false;
    const int MaxStops = 100;
    Stop* stops[MaxStops] = {nullptr};
    int stopCount = 0;

    DisplayProgramInfo();


    do {
        choice = DisplayMainMenu();

        switch (choice)
        {
            case 'q': case 'Q':
                quit = ConfirmQuit();
                break;

            case 'a': case 'A':
                HandleAddStop(stops, MaxStops, stopCount);
                break;
        }
    } while (!quit);
}