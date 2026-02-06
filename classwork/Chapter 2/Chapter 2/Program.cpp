/*
 * Chapter 2
 * COSC 1436 Spring 2025
 */
#include <iostream>
#include <string>

// Custom types
struct Point
{
    // Declare the variables that make up the type
    int x; // Field
    int y;
};
 
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
    // Prompt user for their name
    std::cout << "Enter your name: ";

    // Read user's name
    std::string name;
    std::cin >> name; //This will be talked about in chapter 3 

    //Print out user's name
    std::cout << "Hello " << name << std::endl;

    //Variables are used for reading and writing things.
    // Variable_decl ::= T id;
    //  id - name of the variable
    //  T - what can be stored in the variable

    // Variables must be declared before they can be used
    //  Exists at the point of declaration

    // ok: firstname ,lastname, middlename, etc
    // better: firstName, Firstname
    // worse: first_name, last_name, rest_of_name
    // variable idtentifiers: camel casing
    //  capitalize on word boundaries (Capitlatize words where a space would be), with the exception of the first word
    //  eg. payGrade, restOfName, firstName, middleName
    

    // Can't use keywords as identifiers
    // ID cannot already exist (Use a previous ID you have made)

    int age; 
    double payRate;

    // Compiler error - cannot re-declare a value
    // double age;

    // Student name
    /* std::string firstname;
    std::string lastname;
    */
    std::string firstName, lastName;
    

    // Perimeter of a rectangle
    /*int length;
    int width;
    int perimeter;
    */
    int length, width, perimeter;

    // Write to a variable using the assignment operator '='
    length = 10;
    width = 20;

    std::cout << length;
    std::cout << width;

    // Type 
    //  primatives : understood by language
    //  floating point = stores fractional values
    //  integral = stores numbers 

    // TYPE | SIZE | RANGE 

    // short, size of 2 bytes, range of + or - 32k
    // int, 4 bytes, range of + or - 2 billion
    // long, 4 bytes, range of + or - 2 billion

    // float, 4 bytes, e + or - 38 | 5-7 digits after the decimal before dealing with round-off errors
    // double, 8 bytes. e + or - 308 | 12-15 digits aftr the decimal before dealing with round-off errors

    // bool, 1 byte, false & true range

    // char, 1 byte, single character,

    // unsigned short, size of 2 bytes, range of 64
    // unsigned int, size of 4 bytes, 4 billion
    // unsigned long, size of 4 bytes, 4 billion

    // if needing an integer type, always use 'int'
    // Every expression must have a type
    // Whole numbers are always typed as 'int'
    // if a number has either a capital or lowercase 'L,' its classifying the number as a long, not an int '5L, 5l'
    // If needing to store a floating point value, use 'double'
    // Floating point literals are considered doubles
    // if a fractional number has a lowercase or uppercase 'f,' it is considered a float
    // char is technically an integer type
    // Can declare one or more identifiers in a single type

    int hoursWorked; //hours worked in past week
    hoursWorked = 25; 
    
    //Store class average on a quiz
    double classAverage; // or classQuizAverage
    classAverage = 78.9;

    // Store letter grade for a student
    char letterGrade;
    letterGrade = 'A';

    // Store first time in college
    bool firstTimeinCollege; 
    firstTimeinCollege = true;

    // Assigment ::= E = E
    //      l-value = r-value; only variables are l-values
    length = 50;
    width = length;

    // variables are only on the left side (writable)
    // Any expression can be an r-value

    // Zero initialization; zero int variables before use
    // Cannot read varaibles before definitely assigned
    // Definitely assingned
    //  Assignment
    //  std::cin

    int someVariable = 0;
    // someVariable = 0; someVariable = 0;

    // read an int from user
    // std::cin >> someVariable;

    int anotherValue = 10, anotherValueAgain = 20;

    // print out int
    std::cout << someVariable;

    //Arithmetic operators
    // + - * / %
    // + - (unary)

    // integer division problem:: int / int => int
    int quotent = 10 / 3;  //int / int => int

    // modulos -> remainder when you divide two ints
    int remainder = 10 % 3; // 1

    int negativeRemainder = -remainder;
    quotent = +quotent;

    double actualQuotent = 10.0 / 3.0; // double / double -> double

    // Calculate perimeter of rectangle
    std::cout << "Enter Length? ";
    std::cin >> length;

    std::cout << "Enter width? ";
    std::cin >> width;

    // P = 2L +2W
    perimeter = length + length + width + width;
    std::cout << "Perimeter = " << perimeter << std::endl;

    // Scope - its lifetime; point of declaration until the block that contains it ends
    // aLocalVariable = 20;

    int aLocalVariable = 0;
    aLocalVariable = 10;

    // Start a new block
    {
        double blockVariableA = 0;

        // Can access variables declared in the block + any parent blocks
        blockVariableA = 10;
        aLocalVariable = 20;

        double length;
        length = 80;
    }

    std::cout << length << std::endl;
    //blockVariableA no longer accessible

    // C++ strings
    // - Not a primitive type
    // - Only usagble in C++
    std::string someStringValue;
    someStringValue = "Bob";
    someStringValue = someStringValue + "How are you?";

    // Assignment
    //  - Expression as well
    //  - Value is value of variable after assignment
    //  - Can chain assignments together
    length = width = perimeter = 0;

    // Named constants
    //  Literal : 25
    //  Variable : T id = 25;
    // const_decl ::= const T id = E;
    // Casing: pascal or all uppercase
    // must be complile time constant - must be calculatable at compile time
    // - Literals
    // - simple math exprssions with constant expressions
    // 4 + 5, MaximumStudents, MaximumStudents - 10
    const int MAXI_SIZE = 25;
    const int MaximumStudents = 25;

    // Change value at runtime
    // maximumStudents = 40; cannot write to a constant

    int largestNumberOfStudents = 25; // using the literal
    // largestNumberOfStudents = maximumStudents; // using the variable
    largestNumberOfStudents = MaximumStudents; // Using constant

    // Create and get input for a point
    Point left;

    std::cout << "Enter the X value ";
    std::cin >> left.x; //specify fields using a dot. Followed by the field.

    std::cout << "Enter the Y value ";
    std::cin >> left.y;

    std::cout << "(" << left.x << ", " << left.y << ")" << std::endl;
}