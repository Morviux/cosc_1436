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

/// @brief Handles the stop menu option.
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

/// @brief Finds a stop given a stop number.
/// @param stops An array of stop pointers.
/// @param stopCount Current number of stops.
/// @param stopNumber The stop number to find (1 based)
/// @return Pointer to the stop, or nullptr if not found
Stop* FindStop(Stop* stops[], int stopCount, int stopNumber)
{
    int index = stopNumber - 1;

    if (index < 0 || index >= stopCount)
        return nullptr;

    return stops[index];
}

/// @brief Shifts elements in the stops array left beginning at startIndex, copying subsequent elements into earlier positions until a null pointer is found or the end of the array is reached.
/// @param stops Array of pointers to Stop objects; elements are modified in-place. A null pointer acts as a sentinel to stop compaction.
/// @param size Total number of elements in the stops array.
/// @param startIndex Index at which compaction begins; the element at this index will be overwritten by the next element.
void CompactArray(Stop* stops[], int size, int startIndex)
{
    int newIndex = startIndex;
    for (int index = startIndex + 1; index < size; ++index)
    {
        stops[newIndex] = stops[index];
        ++newIndex;

        if (!stops[index])
            return;
    }
}

/// @brief Removes a stop from the trip array.
/// @param stops An array of pointers.
/// @param size The maximum size of the array.
/// @param stopCount Current number of stops.
/// @param pStop Pointer to the stop to remove.
void RemoveStop(Stop* stops[], int size, int& stopCount, Stop* pStop)
{
    for (int i = 0; i < stopCount; i++)
    {
        if (stops[i] == pStop)
        {
            delete stops[i];
            stops[i] = nullptr;

            CompactArray(stops, size, i);
            stopCount--;
            return;
        }
    }
}

/// @brief Handles the delete stop menu option.
/// @param stops Array of stop pointers.
/// @param size Maximum size of the array.
/// @param stopCount The current number of stops.
void HandleDeleteStop(Stop* stops[], int size, int& stopCount)
{
    if (stopCount == 0)
    {
        std::cout << "There are no stops to delete." << std::endl;
        return;
    }

    int stopNumber = 0;
    std::cout << "Enter stop number to delete: ";
    std::cin >> stopNumber;

    while (stopNumber < 1)
    {
        std::cout << "Invalid. Enter a number greater than 1: ";
        std::cin >> stopNumber;
    }

    Stop* pStop = FindStop(stops, stopCount, stopNumber);

    if (!pStop)
    {
        std::cout << "Stop not found." << std::endl;
        return;
    }

    RemoveStop(stops, size, stopCount, pStop);
    std::cout << "Stop removed." << std::endl;
}

/// @brief Displays the trop stops to the user.
/// @param stops An array of stop pointers.
/// @param stopCount The current number of stops.
/// @param speed The travel speed in miles per hour (MPH).
void HandleViewTrip(Stop* stops[], int stopCount, int speed)
{
    if (stopCount == 0)
    {
        std::cout << "There are no stops present." << std::endl;
        return;
    }

    std::cout << std::left << std::fixed << std::setprecision(2);
    std::cout << std::setw(10) << "Stop"
        << std::setw(15) << "Location"
        << std::setw(20) << "Distance (Miles)"
        << std::setw(20) << "Time (Distance):"
        << std::endl;
    std::cout << std::setfill('-') << std::setw(65) << ""
        << std::setfill(' ') << std::endl;

    double totalDistance = 0;
    double totalTime = 0;
    int prevX = 0, prevY = 0;

    for (int i = 0; i < stopCount; i++)
    {
        double distance = CalculateDistance(prevX, prevY, stops[i]->x, stops[i]->y);
        double time = ceil((distance / speed) * 60);

        totalDistance += distance;
        totalTime += time;

        std::string location = "(" + std::to_string(stops[i]->x)
            + "," + std::to_string(stops[i]->y) + ")";

        std::cout << std::setw(10) << (i + 1)
            << std::setw(15) << location
            << std::setw(20) << distance
            << std::setw(20) << time
            << std::endl;

        prevX = stops[i]->x;
        prevY = stops[i]->y;
    }

    std::cout << std::setfill('-') << std::setw(65) << ""
        << std::setfill(' ') << std::endl;
    std::cout << std::setw(10) << stopCount
        << std::setw(15) << ""
        << std::setw(20) << totalDistance
        << std::setw(20) << totalTime
        << std::endl;
}

/// @brief Removes all stops from the trip.
/// @param stops Array of stop pointers.
/// @param stopCount Current number of stops.
void ClearTrip(Stop* stops[], int& stopCount)
{
    for (int i = 0; i < stopCount; i++)
    {
        delete stops[i];
        stops[i] = nullptr;
    }
    stopCount = 0;
}

/// @brief Handles the clear trip menu option
/// @param stops Array of stop pointers.
/// @param stopCount The current number of stops.
void HandleClearTrip(Stop* stops[], int& stopCount)
{
    if (stopCount == 0)
    {
        std::cout << "There are no stops to clear." << std::endl;
        return;
    }

    char confirm;
    std::cout << "Are you sure you want to clear this trip? (Y/N): ";
    std::cin >> confirm;

    while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N')
    {
        std::cout << "Invalid input. Do you want to clear this trip? (Y/N): ";
        std::cin >> confirm;
    }

    if (confirm == 'y' || confirm == 'Y')
    {
        ClearTrip(stops, stopCount);
        std::cout << "Trip Cleared!" << std::endl;
    }
}

/// @brief Prompts the user for their travel speed. 
/// @return The speed in miles per hour (MPH).
int GetSpeed()
{
    int speed = 0;
    std::cout << "Enter the speed (1-60): ";
    std::cin >> speed; 

    while (speed < 1 || speed > 60)
    {
        std::cout << "Invalid. Enter the speed (1-60): ";
        std::cin >> speed; 
    }

    return speed;
}

/// @brief Calculates the distance between two points.
/// @param x1 Starting the x coordinate. 
/// @param y1 Starting the y coordinate. 
/// @param x2 Ending the x coordinate. 
/// @param y2 Ending the y coordinate. 
/// @return The distance between the two points. 
double CalculateDistance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
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
    std::cout << "Are you sure you want to quit? (Y/N): ";
    std::cin >> confirm;

    while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N')
    {
        std::cout << "Invalid input. Are you ABSOLUTELY sure you want to quit? (Y/N): ";
        std::cin >> confirm;
    }

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
    int speed = GetSpeed();

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

            case 'v': case 'V':
                HandleViewTrip(stops, stopCount, speed);
                break;

            case 'd': case 'D':
                HandleDeleteStop(stops, MaxStops, stopCount);
                break;

            case 'c': case 'C':
                HandleClearTrip(stops, stopCount);

        }
    } while (!quit);
}

// Hi :3