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

    int runLength = 0;      // >= 0
    int releaseYear = 0;     // 1900 to 2100

    double userRating = 0;   //1 to 5

    bool isClassic = false;

    std::string description;  //Optional
};

// C++ enum
enum class MenuCommand
{
    Add = 1,
    Edit = 2,
    Delete = 3,
    View = 4,
    Quit = 5
};
  

void Multiply(int value, int multiple)
{
    // value = value * multiple
    value *= multiple;
}

/// @brief Displays a horizontal line.
/// @param width Width of the line. 
void DisplayLine(int width )
{
    // int width = 10
    // logical operation
    std::cout << std::setfill('-') << std::setw(width) << "" << std::setfill(' ') << std::endl;
};

/// @brief Resets the output text colors to their default values.
void ResetColors()
{
    std::cout << "\033[0m";
}

/// @brief Clears the input buffer of extra characters.
void ClearInputBuffer()
{
    std::cin.ignore(INT32_MAX, '\n'); 
};

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

    BrightBlack = 90,
    BrightRed = 91,
    BrightGreen = 92,
    BrightYellow = 93,
    BrightBlue = 94,
    BrightMagenta = 95,
    BrightCyan = 96,
    BrightWhite = 97,
};

/// @brief Sets the output colors for displaying errors.
/// @param color Color to use for the foreground.
void SetForegroundColor ( ConsoleColor color )
{
    char buffer[10] = {0};
    _itoa_s((int)color, buffer, 10, 10);

    
    std::string value = "\033[";
    value += buffer;
    value += "m";

    std::cout << value;
};

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
    std::cout << message << std::endl;
    ResetColors();
}

/// @brief Displays a message
/// @param color Color to show the message in 
/// @param message Message to display
/// @param inlcludeNewLine Add a new line?
void DisplayMessage(ConsoleColor color, std::string message, bool includeNewLine)
{
    SetForegroundColor(color);

    std::cout << message;;
    if (includeNewLine)
        std::cout << std::endl;
    ResetColors();
}

void Fibonacci(int value)
{
    if (value >= 1)
    {
        // 1 * 2 * 3 * N
        // value * Fibonacci(value - 1);
        std::cout << value << std::endl;
        Fibonacci(value - 1);
    };
    
}

// Main is a special fucntion
//     - It is the entry function of your program
//     - It's declaration can vary slightly
//     - You cannot call main directly
void main()
{
    // Fibonacci(3);

    /* int input = 10;
    int multiple = 5;
    Multiply(input, multiple);
    std::cout << input << std::endl; */

    Movie movie;

    bool quit = false;
    while (!quit)
    {
        // Display menu
        std::cout << "Main Menu" << std::endl;
        // std::cout << "------------" << std::endl;
        DisplayLine(10);
        std::cout << "A)dd Movie" << std::endl;
        std::cout << "E)dit Movie" << std::endl;
        std::cout << "D)elete Movie" << std::endl;
        std::cout << "V)iew Movie" << std::endl;
        std::cout << "Q)uit" << std::endl;
        std::cout << "? ";

        // Handle user input
        MenuCommand input = (MenuCommand)0;
        char choice;


        // Pre-test so S executes 0 or more times 
        while (input == (MenuCommand)0)
        {
            std::cin >> choice;
            switch (choice)
            {
                case 'A':
                case 'a': input = MenuCommand::Add; break;

                case 'E':
                case 'e': input = MenuCommand::Edit; break;

                case 'D':
                case 'd': input = MenuCommand::Delete; break;

                case 'V':
                case 'v': input = MenuCommand::View; break;

                case 'Q':
                case 'q': input = MenuCommand::Quit; break;

                default:
                {
                    // SetForegroundColor(ConsoleColor::BrightRed);
                    // std::cout << "ERROR: Invalid option" << std::endl;
                    // ResetColors();
                    DisplayError("Invalid Option");
                    break;
                }
            }
        }

        switch (input)
        {

            case MenuCommand::Add:
            {
                // Add movie logic
                // Reset input buiffer
                // std::cin.ignore(INT32_MAX, '\n');
                ClearInputBuffer();

                // Prompt for movie details
                std::cout << "Enter title (required): ";
                while (movie.title == "")
                {
                    std::getline(std::cin, movie.title);

                    // Validate title
                    if (movie.title == "")
                        DisplayError("Title is required");
                }

                std::cout << "Enter description: ";
                std::getline(std::cin, movie.description);

                std::cout << "Enter genre: ";

                for (int count = 0; count < 5; ++count)
                {
                    std::string genre;
                    std::getline(std::cin, genre);

                    // if (genre != "")
                    //    continue;

                    //movie.genres += ", " + genre;
                    if (genre != "")
                    {
                        movie.genres += ", " + genre;
                        // ++genreCount:
                    } else
                        // genreCount = 5
                        // count = 5
                        break;
                }


                // HACK: fix this
                std::cout << "Enter run length (in minutes): ";


                do
                {
                    std::cin >> movie.runLength;

                    // Runlength >= 0
                    if (movie.runLength < 0)
                    {
                        DisplayError("Run length must be at least 0");
                        // movie.runLength = 0;
                    }
                } while (movie.runLength < 0);

                std::cout << "enter release year (1900-2100): ";

                // ReleaseYear >= 1900 <= 2100
                while (movie.releaseYear < 1900 || movie.releaseYear > 2100)
                {
                    std::cin >> movie.releaseYear;

                    if (movie.releaseYear < 1900 || movie.releaseYear > 2100)
                    {
                        DisplayError("Release year must be between 1900 - 2100");
                       
                    }
                }

                std::cout << "Enter the user rating (1.0-5.0): ";
                std::cin >> movie.userRating;

                char isClassic;
                std::cout << "Is classic (Y/N): ";

                bool done = false;
                // while (!done)
                do
                {
                    std::cin >> isClassic;

                    if (isClassic == 'Y' || isClassic == 'y')
                    {
                        movie.isClassic = true;
                        // done = true;
                        break;
                    } else if (isClassic == 'N' || isClassic == 'n')
                    {
                        movie.isClassic = false;
                        done = true;
                    } else
                        DisplayError("Must be Y (y) or N (n)"); // != Y y N n
                } while (true);
                break;
            }

            // case 'E':
            case MenuCommand::Edit: DisplayWarning("Edit not implemented");


                ;
            case MenuCommand::Delete:
            {
                // No movie, no work
                if (movie.title == "")
                    break;

                // Confirm
                // std::cout << "Are you sure you want to delete '" << movie.title << "' (Y/N)? ";
                std::string message = "Are you sure you want to delete '";
                message += movie.title;
                message += "' (Y/N)? ";
                DisplayMessage(ConsoleColor::Cyan, message, false);
                bool confirm = false;
                do
                {
                    char choice;
                    std::cin >> choice;
                    if (choice == 'Y' || choice == 'y')
                    {
                        confirm = true;
                    } else if (choice == 'N' || choice == 'n')
                    {
                        confirm = false;
                        break;
                    };
                } while (true);

                // Delete
                if (confirm)
                    movie.title = "";


                break;
            }


            case MenuCommand::View:
            {
                if (movie.title == "")
                {
                    //std::cout << "No movies in library" << std::endl;
                    DisplayWarning("No movies in library");
                    break;
                };

                // Display movie details
                std::cout << movie.title << " (" << movie.releaseYear << ")" << std::endl;
                std::cout << "Length (in minutes) " << movie.runLength << std::endl;
                std::cout << "Genre(s): " << movie.genres << std::endl;
                std::cout << "User Rating: " << movie.userRating << std::endl;



                std::cout << "Classic? " << (movie.isClassic ? "Yes" : "No") << std::endl;

                std::cout << movie.description << std::endl;
                break;
            }

            case MenuCommand::Quit: quit = true; break;

            // Everything else
            default: DisplayError("Invalid Option"); break;
        }


        // Add movie logic
        Movie movie;

        std::cin.ignore(INT32_MAX, '\n');
        //Prompt for movie details
        std::cout << "Enter title (required): ";


        while (movie.title == "")
        {
            std::getline(std::cin, movie.title);

            //Validate title
            if (movie.title == "")
                DisplayError("Title is required");
        }

        std::cout << "Enter description: ";
        std::getline(std::cin, movie.description);

        std::cout << "Enter genres: ";
        std::getline(std::cin, movie.genres);

        // HACK: fix this
        std::cout << "Enter run length (in minutes): ";
        movie.runLength = -1;
        while (movie.runLength < 0)
        {
            std::cin >> movie.runLength;

            //Runlength >= 0
            if (movie.runLength < 0)
            {
                DisplayError("Run length must be at least 0");
                // movie.runLength = 0;
            }
        }

        std::cout << "Enter release year (1900-2100): ";
        std::cin >> movie.releaseYear;


        if (movie.releaseYear < 1900 || movie.releaseYear > 2100)
        {
            DisplayError("Release year must be between 1900 - 2100");
            movie.releaseYear = 1900;
        }

        std::cout << "Enter the user rating (1.0-5.0): ";
        std::cin >> movie.userRating;

        char isClassic;
        std::cout << "Is classic (Y/N)? ";
        std::cin >> isClassic;

        if (isClassic == 'Y' || isClassic == 'y')
            movie.isClassic = true;
        else if (isClassic == 'N' || isClassic == 'n')
            movie.isClassic = false;
        else
        {
            DisplayError("Must be Y(y) or N(n)"); // != Y y N n
            movie.isClassic = false;
        }


        //Display movie details
        std::cout << movie.title << " (" << movie.releaseYear << ")" << std::endl;
        std::cout << "Length (in minutes) " << movie.runLength << std::endl;
        std::cout << "Genre(s): " << movie.genres << std::endl;
        std::cout << "User Rating: " << movie.userRating << std::endl;


        std::cout << "Classic? " << (movie.isClassic ? "Yes" : "No") << std::endl;

        std::cout << movie.description << std::endl;
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
postfix dec      x++                 x-1         X'

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

Parameter Kind                      C++
Input parameter (Pass by value)     T)ype id

*/
