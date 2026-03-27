/*
 * Movie Library
 * COSC 1436
 * Spring 2026
 */
#include <iostream>
#include <iomanip>
#include <string>

//Movie definition
struct Movie
{
    //Fields
    std::string title;   // Required, not empty

    std::string genres;  // comma separated list

    int runLength = 0;       // >= 0
    int releaseYear = 0;     // 1900 to 2100

    double userRating = 0;   //1 to 5

    bool isClassic = false;

    std::string description;  //Optional
};

//C++ enum
enum class MenuCommand
{
    Add = 1,
    Edit = 2,
    Delete = 3,
    View = 4,
    Quit = 5
};

// Function - a reusable block of code that does one logical operation

// Function definition - Defines a function and its implemention
//   func_decl ::= T id ( [parameter-list] )
//   func_defn ::= func_decl { S* }
//   parameter-list ::= parameter {, parameter}*
//   parameter ::= T id
// 
//   func_call ::= id ( [arg-list] );
//   arg-list  ::= E {, E}* 
//                
// - functions are actions and should be named as verbs
// - casing: camel or Pascal 
//
// parameter ::= input to a function
// parameter kinds
//   1) Input (pass by value) (C++: T id)
//          Copy of argument passed to function
//          Function can read and write parameter
//          Changes to parameter have no impact on original argument

enum class ConsoleColor
{
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37,

    BrightRed = 91,
    BrightGreen = 92,
    BrightYellow = 93,
    BrightBlue = 94,
    BrightMagenta = 95,
    BrightCyan = 96,
    BrightWhite = 97,
};

//Prototypes / forward reference
// Function declaration without the definition
void DisplayError(std::string);
void DisplayWarning(std::string);
void ResetColors();
void SetForegroundColor(ConsoleColor);

//void SuperMultiply(int, int);

//void Multiply(int value, int multiple)
//{
//    SuperMultiply(value, multiple);
//
//    // value = value * multiple
//    value *= multiple;    
//}

// Variables 
//      Local - Declared inside a function and has a lifetime tied to the function call
//      Global - Declared outside a function and has a program lifetime
//               Used when multiple functions need access to data that is impractical to pass as parameters
//      Issues with globals (and why you will not use them, especially in this class)
//      1. Functions are no longer isolated
//      2. Initialization order is undefined
//      3. Anybody can read / write them
//      4. 

/* int g_standardConsoleLineLenth = 80;
int g_maximumLineLength = g_standardConsoleLineLenth; */
const int g_maximumLineLength = 80; //Only allowed case for a constant


/// @brief Displays a horizontal line.
/// @param width Width of the line
void DisplayLine(int width)
{
    // int maximumLineLength = -1;

    {
        double width = 24;
        int someValue = width * g_maximumLineLength;
    }
    if (width < 0)
        width = 0;
    else if (width > g_maximumLineLength)
        width = g_maximumLineLength;
    //int width = 10;

    //Logical operation
    std::cout << std::setfill('-') << std::setw(width) << "" << std::setfill(' ') << std::endl;
};

/// @brief Clears the input buffer of extra characters.
void ClearInputBuffer()
{
    std::cin.ignore(INT32_MAX, '\n');
};

/// @brief Displays a message.
/// @param color Color to show the message in.
/// @param message Message to display.
/// @param includeNewline Add a new line?
void DisplayMessage(ConsoleColor color, std::string message, bool includeNewline)
{
    SetForegroundColor(color);

    std::cout << message;;
    if (includeNewline)
        std::cout << std::endl;

    ResetColors();
}

/// @brief Displays an error message.
/// @param message Message to display.
void DisplayError(std::string message)
{
    SetForegroundColor(ConsoleColor::BrightRed);
    std::cout << "ERROR: " << message << std::endl;
    ResetColors();
}

/// @brief Displays a warning message.
/// @param message Message to display.
void DisplayWarning(std::string message)
{
    SetForegroundColor(ConsoleColor::Yellow);
    std::cout << "WARN: " << message << std::endl;
    ResetColors();
}

/// @brief Resets the output colors to their default values.
void ResetColors()
{
    std::cout << "\033[0m";
};

/// @brief Sets the output colors for displaying errors.
/// @param color Color to use for the foreground
void SetForegroundColor(ConsoleColor color)
{
    char buffer[10] = {0};
    _itoa_s((int)color, buffer, 10, 10);

    std::string value = "\033[";
    value += buffer;
    value += "m";

    std::cout << value;
};

//Demoing when recursive calls never end
// return - exits function immediately
void Fibonacci(int value)
{
    //Validate parameters
    if (value < 1)
        return;

    //1 * 2 * 3 * N
    //value * Fibonacci(value - 1);
    std::cout << value << std::endl;
    Fibonacci(value - 1);
}

/// @brief Confirms information from the user
/// @param message Message to display
/// @return true if yes or false if no
bool Confirm(std::string message)
{
    // Confirm
    message += " (Y/N)? ";
    DisplayMessage(ConsoleColor::Cyan, message, false);
    bool confirm = false;
    do
    {
        char choice;
        std::cin >> choice;
        if (choice == 'Y' || choice == 'y')
            return true;
        /*{
            confirm = true;
            break;*/
        else if (choice == 'N' || choice == 'n')
            return false;
        /*{
            confirm = false;
            break;
        };*/
    } while (true);

    //return false;
}

int ReadInt(std::string message, int minValue, int maxValue)
{
    std::cout << message;

    int input;

    do
    {
        std::cin >> input;

        if (input >= minValue && input <= maxValue)
            return input;

        //TODO: Fix later
        DisplayError("Value is not in expected range");
    } while (true);
}

int ReadInt(std::string message, int minValue)
{
    return ReadInt(message, minValue, INT32_MAX);
}

int ReadInt(std::string message, int maxValue)
{

}

/// @brief Reads a string from the user
/// @param message Message to display
/// @param required true to indicate a required value
/// @return Input from user
std::string ReadString(std::string message, bool required)
{
    std::cout << message;

    std::string input;
    do
    {
        std::getline(std::cin, input);

        //Validate
        if (input != "" || !required)
            return input;

        DisplayError("Value is required");
    } while (true);
}

// Function Oveloading - Overloading a function's name by parameter types
// 1) Each overload must use the same name
// 2) Each overload must have one parameter type that is different
// 3) 

/// @brief Reads an optional string
/// @param message Message to display
/// @return Input from user
std::string ReadString(std::string message)
{
    return ReadString(message, false);
}

Movie AddMovie()
{
    //Reset input buffer
    //std::cin.ignore(INT32_MAX, '\n');
    ClearInputBuffer();

    Movie movie;

    //Title is required
    movie.title = ReadString("Enter title (required): ", true);
    movie.description = ReadString("Enter description; ");

    for (int count = 0; count < 5; ++count)
    {
        std::string genre = ReadString("Enter genre: ", false);
        if (genre == "")
            break;

        movie.genres += ", " + genre;
    }

    movie.runLength = ReadInt("Enter run length (in minutes): ", 0);
    movie.releaseYear = ReadInt("Enter release year (1900-2100): ", 1900, 2100);

    std::cout << "Enter the user rating (1.0-5.0): ";
    std::cin >> movie.userRating;

    movie.isClassic = Confirm("Is classic?");

    return movie;
}

//TODO: Fix this correctly later
// Movie is pass-by-reference
// pass-by-reference (input-output) T& id
// Function can modify argument provided by caller
// Caller must pass a variable 
void DeleteMovie(Movie& movie)
{
    // No movie = no work
    if (movie.title == "")
        return;

    // Calling a function returning a value
    //bool confirm = Confirm("Are you sure you want to delete '" + movie.title + "'");

    //Confirm("Hello");

    //Delete
    //if (confirm)
    if (Confirm("Are you sure you want to delete '" + movie.title + "'"))
        movie.title = "";
}

// Pass by reference makes sense when: copying the value is too expensive, large, or not allowed
// Make the parameter constant to avoid modification
void ViewMovie(Movie const& movie)
{
    //Movie must exist
    if (movie.title == "")
    {
        //std::cout << "No movies in library" << std::endl;
        DisplayWarning("No movies in library");
        return;
    }

    //Display movie details
    std::cout << movie.title << " (" << movie.releaseYear << ")" << std::endl;
    std::cout << "Length (in minutes) " << movie.runLength << std::endl;
    std::cout << "Genre(s): " << movie.genres << std::endl;
    std::cout << "User Rating: " << movie.userRating << std::endl;
    std::cout << "Classic? " << (movie.isClassic ? "Yes" : "No") << std::endl;

    std::cout << movie.description << std::endl;
}

// Main is a special function
// - It is the entry function of your program
// - It's declaration can vary slightly
// - You cannot call main directly
void main()
{
    //Fibonacci(3);

    /*int input = 10;
    int multiple = 5;
    Multiply(input, multiple);
    std::cout << input << std::endl;*/

    Movie movie;

    bool quit = false;
    while (!quit)
    {
        // Display menu
        std::cout << "Main Menu" << std::endl;
        //std::cout << "------------" << std::endl;
        DisplayLine(10);
        std::cout << "A)dd Movie" << std::endl;
        std::cout << "E)dit Movie" << std::endl;
        std::cout << "D)elete Movie" << std::endl;
        std::cout << "V)iew Movie" << std::endl;
        std::cout << "Q)uit" << std::endl;
        std::cout << "? ";

        //Handle user input
        MenuCommand input = (MenuCommand)0;
        char choice;

        while (input == (MenuCommand)0)
        {
            std::cin >> choice;
            switch (choice)
            {
                case 'A':
                case 'a': input = MenuCommand::Add; break;

                case 'E':
                case 'e': input = MenuCommand::Edit; break;

                case 'V':
                case 'v': input = MenuCommand::View; break;

                case 'D':
                case 'd': input = MenuCommand::Delete; break;

                case 'Q':
                case 'q': input = MenuCommand::Quit; break;

                default:
                {
                    //SetForegroundColor(ConsoleColor::BrightRed);
                    //std::cout << "ERROR: Invalid option" << std::endl; 
                    //ResetColors();
                    DisplayError("Invalid option");
                    break;
                }
            }
        }

        switch (input)
        {
            case MenuCommand::Add: movie = AddMovie();break;
            case MenuCommand::Edit: DisplayWarning("Edit not implemented");
            case MenuCommand::Delete: DeleteMovie(movie); break;
            case MenuCommand::View: ViewMovie(movie); break;

            case MenuCommand::Quit: quit = true; break;

            //Everything else
            default: DisplayError("Invalid option"); break;
        }
    }
}

/*

NOTES:
Conditional Operator: E(Booleen) ? V(True) : V(False) - Good for calculating one of two values
    - Both Values of the variables in the conditional operator must be of the same type
    - Will NOT do type coercion. (But you can type cast)
    - The compiler may confuse itself when distinguishing a conditional operator. Best course of action is to use parenthesis

Switch Statements: Switch (Expression)
{
    case Label(1) : S (statement);
    case Label(2) : S (statement);
    ..
}
    - Basically a glorified if else if statement
    - The most advanced variant, can only be used under certain cases.

Enumeration -> Subrange of an int


prefix increiment ++x Both incriment my variable by one
postfix increment X++

prefix decriment --x both decriment my variable by one
postfix decriment x--
    ONLY VARIABLES ARE ALLOWED

TABLE

OP               Syntax              X'          Expression Returns
Prefix inc       ++x                 x+1         X'
Postfix inc      x++                 x+1         temp = x

prefix dec       --x                 x-1         X'
postfix dec      x--                 x-1         X'

Table:         Pre / Post      S
While          Pre             0+  - General purpose
For            Pre             0+  - Fixed iterations
Do-while       Post            0+  - At least once

Relational demo
Relational operators
rel_expr ::= Eb rel_op Eb => bool
rel_op ::= > >= < <= == !=
Precedence => below arithmetic but above equality, left associative
bool isGreater = 4 > 5;  false
isGreater = 10 >= 3;     true

int x = 10, y = 20;
bool areEqual = x == y;     Equality
bool areNotEqual = x != y;  Inequality

Common C code for boolean since it didn't support it
int isCorrect = 0;  false
isCorrect = 10;     true

areEqual = x == y;  false, equality
areEqual = x = y;    true, assignment

areEqual = x == 10;
areEqual = x = 10;

When comparing to constants put the constant first
areEqual = 10 == x;
areEqual = 10 = x;

(In)Equality with floating point types
float f1 = 1 / 3;
float f2 = 100 / (100 / 30 * 100);

Do not use with floating point values
areEqual = f1 == f2;  Mathematically equal
areEqual = f1 >= f2;

Can use with floating point with integer
f1 = 100.0;
areEqual = f1 == 100;   True

Strings - works with relational
Numeric comparison
Case sensitive
Locale insensitive (not good for sorting)
std::string firstName = "Bob";
std::string lastName = "bob";
bool isSingularName = firstName == lastName;

Case insensitive string comparison
Use .c_str() to convert C++ string to C
int result = _strcmpi("Bob", "bob");
isSingularName = _strcmpi(firstName.c_str(), lastName.c_str()) == 0;  //Not equal != 0 

FUNCTIONS:
Function - a reusable block of code that does one logical operation

Function definition - Defines a funcrtion and its implementation
      func_defn ::= T id () { S* }
      functions are actiosn that should be named as verbs
 - casing: camel or PascalCasing

 // DEFINITION (PARAMETER): Variable inside the function definition (Also called formal argument)
 // parameter ::= input to a function
 // parm_list: param {, param}*
 // parameter ::= T id

 // DEFINITION (Argument): Value passed to a function in the function call (Also called actual argument)

func_def ::= void id ()
{
    Statement
}; 

Function Call: func_call ::= id(arguments)

args ::= E {, E }*

Parameter Kind                      Syntax          Operations
Input parameter (Pass by value)     T)ype id        Param: Read & Write | Argument: No Change
Output                              Ret type        Param: Write | 
Input-Output (Pass by reference)    T)ype & id      Param: Read & write | Argument: changed (Must be a variable)


*/
