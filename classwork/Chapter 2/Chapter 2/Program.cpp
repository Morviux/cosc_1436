/*
 * Chapter 2
 * COSC 1436 Spring 2025
 */
#include <iostream>

// Entry point of the program
void main()
{
    // What main does

    // Display output
    

    // cout -> console output
    // << -> Output stream operator | Always used in conjuction with cout
    // String literals - Always encased in double-quotes and represent text for the user (Always in red, and must be in one line)
    // semi-colons are statement terminators. Helps the compiler know when a statement ends (Resembles a period)
    // Statement - Does something (depends on the statement)
    // Expression - Calculation (All expressions produces a value)
    // Can chain expressions together using '<<'
    // std::endl; means a new line MUST be used with cout
    std::cout << "Hello World!" << std::endl;

    std::cout << "Hello" << "World!" << std::endl;
    std::cout << "Hello" << " " << "World!" << std::endl;

    //Escape sequence - only usable inside string literals
    //  Start with a slash followed by a special character
    //  \n - new line
    //  \t - horizontal tab
    std::cout << "Hello World!\n";
    std::cout << "Hello\tWorld\n";
    std::cout << "Hello \"Bob\", How are you?" << std::endl;
    // To have double quotes in statements, place slashes in between the statement words
    std::cout << "C:\\Windows\\System32" << std::endl;

    // Integer literal - whole numbers
    // 4 + 5 = 9
    std::cout << 4 << " + " << 5 << " = " << 4 + 5 << std::endl;

    // Floating point literal - fractional numbers
    std::cout << 4.5 << " * " << 6.7 << " = " << 4.6 * 6.7 << std::endl;

    // Variable - named memory location where data is stored
    std::cout << "Enter your name: ";

    std::string name;
    std::cin >> name; //This will be talked about in chapter 3 

    //Print out user's name
    std::cout << "Hello " << name << std::endl;

    //Variables are used for reading and writing things. 
        
}