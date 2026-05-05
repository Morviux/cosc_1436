/*
Lab 5
Demetris Lincoln
COSC 1436 - Spring 2026
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

char DisplayMainMenu()
{
    char choice;

    std::cout << std::endl;
    std::cout << "Main Menu" << std::endl;
    std::cout << std::setfill('-') << std::setw(20) << "" << std::setfill(' ') << std::endl;

    std::cout << "A)dd Stop" << std::endl;
    std::cout << "V)iew Trip"
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
    DisplayProgramInfo();
}