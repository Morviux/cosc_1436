/*
Lab 3
Demetris Lincoln
COSC 1436 - Spring 2026 
*/

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

/// @brief Function to convert results into feet.
/// @param meters The distance in meters
/// @return The distance in feet
double ConvertToFeet(double meters)
{
    return meters * 3.28084;
}

/// @brief Calculates the falling velocity of an object.
double CalculateVelocity(int time)
{
    double velocity = 9.8 * time;
        if (velocity > 90)
            velocity = 90;
    return velocity;
}

/// @brief Displays the program information
void DisplayProgramInfo()
{
    std::cout << "Lab Three" << std::endl;
    std::cout << "Demetris Lincoln" << std::endl;
    std::cout << "COSC 1436 - Spring 2026" << std::endl;
    std::cout << std::endl;
};

/// @brief Prompts the user for the time their item fell.
int GetFallingTime()
{
    int fallingTime;

    std::cout << "How many seconds did your item fall? (1-60 Seconds): ";
    std::cin >> fallingTime;

    while (fallingTime < 1 || fallingTime > 60)
    {
        std::cout << "Invalid Input. Enter a value between (1 - 60): ";
        std::cin >> fallingTime;
    }

    return fallingTime;
}

/// @brief Calculates the falling distance of an object
double CalculateFallingDistance(int time)
{
    return 0.5 * 9.8 * pow(time, 2);
}

/// @brief Function to display the table for seconds, distance, and velocity.
void DisplayTable(int time, char units)
{
    std::cout << std::left << std::fixed;
    std::cout << std::setprecision(2);

    std::cout << std::setw(14) << "Seconds "
        << std::setw(11) << "Distance "
        << std::setw(11) << "Velocity "
        << std::endl;
    
    std::cout << std::setfill('=')
        << std::setw(40)
        << "" << std::setfill(' ')
        << std::endl;

    // For-loop for the sixty seconds of a minute
    for (int second = 1; second <= time; ++second)
    {
        double distance = CalculateFallingDistance(second);

        if (units == 'f' || units == 'F')
            distance = ConvertToFeet(distance);

        std::string unitLabel = (units == 'f' || units == 'F') ? "ft" : "m";
       
        double velocity = CalculateVelocity(second);
        if (units == 'f' || units == 'F')
            velocity = ConvertToFeet(velocity);

        // This part is genuinely frustrating. Getting the unitLabel properly aligned to the 'Distance' value.
        // I'll admit, i gave up. I had a headache and honestly. I'll take the grade i get. 
        std::cout << std::setw(14) << second
            << std::setw(11) << distance << " " << unitLabel
            << velocity << " " << unitLabel << "/s"
            << std::endl;
    }   
}

/// @brief Prompts the for the unit of measurement
char GetUnits()
{
    char unitValue;

    std::cout << "Do you want your value in feet (f) or meters (m)?: ";
    std::cin >> unitValue;

    while (unitValue != 'm' && unitValue != 'M' && unitValue != 'f' && unitValue != 'F')
    {
        std::cout << "Invalid input, please enter m (meters) or f (feet): ";
        std::cin >> unitValue;
    }

    return unitValue;
}


void main()
{
    DisplayProgramInfo();
    int time = GetFallingTime();
    char units = GetUnits();
    DisplayTable(time, units);
}