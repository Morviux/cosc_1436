/*
 * Movie Library
 * COSC 1436
 * Spring 2026
 */
#include <iostream>
#include <iomanip>
#include <string>

//Movie definition
const int MaximumGenres = 5;
struct Movie
{
    //Fields
    int id;

    std::string title;   // Required, not empty

    std::string genres[MaximumGenres];
    int genreCount = 0;

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

void DisplayError(std::string);
void DisplayWarning(std::string);
void ResetColors();
void SetForegroundColor(ConsoleColor);

const int g_maximumLineLength = 80; //Only allowed case for a constant

/// @brief Displays a horizontal line.
/// @param width Width of the line
void DisplayLine(int width)
{
    //int maximumLineLength = -1;

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

/// @brief Reads an optional string
/// @param message Message to display
/// @return Input from user
std::string ReadString(std::string message)
{
    return ReadString(message, false);
}

/// @brief Find a movie given its ID
/// @param movies 
/// @param size 
/// @param id 
/// @return Index of movie, if found
int FindMovieById(Movie movies[], int size, int id)
{
    for (int index = 0; index < size; ++index)
        if (movies[index].id == id)
            return index;

    //Not found
    return -1;
}

Movie AddMovie()
{
    ClearInputBuffer();

    Movie movie;

    //Title is required    
    movie.title = ReadString("Enter title (required): ", true);
    movie.description = ReadString("Enter description: ");

    for (int count = 0; count < MaximumGenres; ++count)
    {
        std::string genre = ReadString("Enter genre: ", false);
        if (genre == "")
            break;

        movie.genres[count] = genre;
        ++movie.genreCount;
    }

    movie.runLength = ReadInt("Enter run length (in minutes): ", 0);
    movie.releaseYear = ReadInt("Enter release year (1900-2100): ", 1900, 2100);

    std::cout << "Enter the user rating (1.0-5.0): ";
    std::cin >> movie.userRating;

    movie.isClassic = Confirm("Is classic?");

    return movie;
}

// Arrays as parameters are always open arrays (undefined size)
// Array size always follows array parameter
int AddMovie(Movie movies[], int size)
{
    //Get the movie details
    Movie movie = AddMovie();

    static int id = 1;

    //Find an empty spot in the array
    for (int index = 0; index < size; ++index)
    {
        if (movies[index].title == "") //Find first element that is not assigned
        {
            movie.id = id++;

            movies[index] = movie;
            return index;
        }
    }

    return -1;
}

//TODO: Fix this correctly later
void DeleteMovie(Movie& movie)
{
    // No movie = no work
    if (movie.title == "")
        return;

    //Delete    
    if (Confirm("Are you sure you want to delete '" + movie.title + "'"))
        movie.title = "";
}

//Arrays are pass by value
//Array behaves like pass by reference (parameter and argument point to the same array in memory)
// Since the parameter is pass by value you cannot change what the argument refers to (the array)
// Arrays can never be the return type of a function
void DeleteMovies(Movie movies[], int size)
{
    //Determine movie to delete
    int id = ReadInt("Enter ID of the movie to delete: ", 1);

    //Find the movie
    int index = FindMovieById(movies, size, id);
    if (index < 0 || index >= size)
    {
        DisplayWarning("Movie not found");
        return;
    };

    //Delete it
    DeleteMovie(movies[index]);
}

void ViewMovie(Movie const& movie)
{
    //Movie must exist
    if (movie.title == "")
        return;

    //Display movie details
    std::cout << "[" << movie.id << "] ";
    std::cout << movie.title << " (" << movie.releaseYear << ")" << std::endl;
    std::cout << "Length (in minutes) " << movie.runLength << std::endl;
    //std::cout << "Genre(s): " << movie.genres << std::endl;
    std::cout << "Genres: ";
    for (int index = 0; index < movie.genreCount; ++index)
    {
        if (index > 0)
            std::cout << ", ";

        std::cout << movie.genres[index];
    }
    std::cout << std::endl;

    std::cout << "User Rating: " << movie.userRating << std::endl;
    std::cout << "Classic? " << (movie.isClassic ? "Yes" : "No") << std::endl;

    std::cout << movie.description << std::endl;
}

void ViewMovies(Movie movies[], int size)
{
    //For range statement does not work with array parameters
    //for (Movie movie: movies)
    for (int index = 0; index < size; ++index)
    {
        if (movies[index].title != "")
            ViewMovie(movies[index]);
    }
}

void ArrayDemo()
{
    const int MaximumValues = 10;
    int values[MaximumValues];

    // Accessing array elements
    //    array_element ::= arr[index]
    //    index ::= Ei
    // You can read and write element values

    // Index is specified inside brackets (integral)
    // Index is always zero-based
    //    Index 0 = Element 1 
    //    Index 1 = Element 2
    //    Index N = Element N+1
    // Given an array of size M
    //    There are M elements (1-M)
    //    Index is 0 to M - 1
    int thirdElement = values[2];

    values[0] = 10;
    values[1] = 20;
    values[2] = 30;

    //Iterate the elements in an array (0..<size)
    // There is no way at runtime to correctly determine # of elements in the array
    for (int index = 0; index < MaximumValues; ++index)
    //int index = 0;
    //for (int& value: values)
    {
        values[index] = index * 10;
        //value = index++ * 10;
    }

    // for-range statement ::= for (T id : arr)
    // Only works if the array is declared within the same function
    //for (int index = 0; index < MaximumValues; ++index)
    for (int value: values)
    {
        //int value = values[index];
        //std::cout << values[index] << " ";
        std::cout << value << " ";
        value = 0;
    }
}

void ArrayInitDemo()
{
    // Zero array initialization - initialize all elements in the array
    //int daysInMonth[12] = {0};

    // Full array initialization sets all elements in the array
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    //Init each element to specific value
    /*daysInMonth[0] = daysInMonth[2] = daysInMonth[4] = daysInMonth[6] = daysInMonth[7] =
        daysInMonth[9] = daysInMonth[11] = 31;
    daysInMonth[3] = daysInMonth[5] = daysInMonth[8] = daysInMonth[10] = 30;
    daysInMonth[1] = 28;    */

    //Implicit array sizing - when using an array initializater, size of array is optional
    //  Use cases:
    //    1. Size of array will never change for your life
    //    2. string
    std::string monthNames[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    //monthNames[0] = "Jan";
    //monthNames[1] = "Feb";
    //monthNames[2] = "Mar";
    //monthNames[3] = "Apr";
    //monthNames[4] = "May";
    //monthNames[5] = "Jun";
    //monthNames[6] = "Jul";
    //monthNames[7] = "Aug";
    //monthNames[8] = "Sep";
    //monthNames[9] = "Oct";
    //monthNames[10] = "Nov";
    //monthNames[11] = "Dec";

    for (int index = 0; index < 12; ++index)
        std::cout << monthNames[index] << " has " << daysInMonth[index] << " days" << std::endl;

    //Partial array initialization - only some element values are set, the rest are zero initialized
    char name[100] = {'B', 'o', 'b'}; //"Bob"
    char companyName[] = "My Company";

    double rates[5] = {1.2, 3.4, 5.6, 7.8, 9.0};

    int x = 100;
    int numbers[10];
    double r = 5.6;

    // Off by one
    //  Starting at 1 and therefore skipping first element
    //  Indexing to size which is one after the last element
    //Init the array
    for (int index = 0; index < 10; ++index)
        numbers[index] = index + 1;

    for (int index = 0; index < 10; ++index)
        std::cout << numbers[index] << " ";
    std::cout << std::endl;
}

void CopyArray(int target[], int targetSize, int source[], int sourceSize)
{
    int size = (sourceSize <= targetSize) ? sourceSize : targetSize;

    for (int index = 0; index < size; ++index)
        target[index] = source[index];
}

bool CompareArray(int left[], int leftSize, int right[], int rightSize)
{
    if (leftSize != rightSize)
        return false;

    for (int index = 0; index < leftSize; ++index)
        if (left[index] != right[index])
            return false;

    return true;
}

void ArrayUsageDemo()
{
    //Things you can't do with array variables
    int array1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array2[10] = {2,4, 6, 8, 9, 10, 12, 14, 16, 18};

    //Copy them
    //array2 = array1;
    CopyArray(array2, 10, array1, 5);

    //Compare them
    //bool areEqual = array1 == array2;
    bool areEqual = CompareArray(array1, 10, array2, 10);

    //Display them
    std::cout << array1 << std::endl;
    //TODO: 
}

void main()
{
    //ArrayDemo();
    //ArrayInitDemo();

    //TODO: Remove once no longer used
    //Movie movie;
    //Movie movie2, movie3, movie4; //Support more than 1 movie
    const int MaximumMovies = 100;
    Movie movies[MaximumMovies];         // Stores 100 movies

    //Array declarations  T id [ Eci ];
    //  Elements are the values stored in an array
    //  Names are plural
    //  All elements have same type
    //  DO NOT USE to store unrelated values just to save variables
    //  Value inside the brackets is the size, number of elements, in the array
    //  Size must be:
    //  1. a compile time constant 
    //  2. > than 0
    //  3. Integer
    //  Array is NOT part of the type
    // Other names for arrays: collection, vector, set, list, array

    // All arrays store their elements contiguously in memory
    // Local variables are stored on stack so be careful of stack space

    bool quit = false;
    while (!quit)
    {
        // Display menu
        std::cout << "Main Menu" << std::endl;
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
                    DisplayError("Invalid option");
                    break;
                }
            }
        }

        switch (input)
        {
            case MenuCommand::Add:
            {
                int index = AddMovie(movies, MaximumMovies);
                if (index < 0)
                    DisplayError("No more space available");

                break;
            }
            case MenuCommand::Edit: DisplayWarning("Edit not implemented");
            case MenuCommand::Delete: DeleteMovies(movies, MaximumMovies); break;
            case MenuCommand::View: ViewMovies(movies, MaximumMovies); break;

            case MenuCommand::Quit: quit = true; break;

            //Everything else
            default: DisplayError("Invalid option"); break;
        }
    }
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
        DisplayWarning("No movies in library");
        return;
    }

    //Display movie details
    std::cout << movie.title << " (" << movie.releaseYear << ")" << std::endl;
    std::cout << "Length (in minutes) " << movie.runLength << std::endl;
    // std::cout << "Genre(s): " << movie.genres << std::endl;
    std::cout << "Genres: ";
    for (int index = 0; index < movie.genreCount; ++index)
    {
        if (index > 0)
            std::cout << ", ";

            std::cout << movie.genres[index] << " ";    
            
    }
    std::cout << std::endl;

    std::cout << "User Rating: " << movie.userRating << std::endl;
    std::cout << "Classic? " << (movie.isClassic ? "Yes" : "No") << std::endl;

    std::cout << movie.description << std::endl;
}

void ArrayDemo()
{
    const int maximumValues = 10;
    int values[maximumValues];

    // Accessign array elements
    //      Array_element ::= array[index]
    //      index ::= Ei
    // You can read and write the element values 

    // The value inside of the square brackets is called the 'Index' (Heh. Index, like the index in warframe)
    // Index is always zero-based
    //      Index 0 = Element 1
    //      Index 1 = Element 2
    //      Index 2 = Element 3
    //      Index N = Element N+1
    // Given an array of size M
    //   There are M elements ranging from 1-M
    //   Index is 0 to M - 1
    int thirdElement = values[2];

    values[0] = 10;
    values[1] = 20; 
    values[2] = 30;

    // Iterate the elements in an array (0.. < size)
    // There is no way at run-time to correctly determine number of elements in the array
    for (int index = 0; index < maximumValues; ++index)
    // int index = 0;
    // for (int& value: values)
    {
        values[index] = index * 10;
        // value = index++ * 10;
    }

    // For-range statement | ::= for (Type Id : ArrayName)
    // Only works if the array is declared within the same function
    // for (int index = 0; index < maximumValues; ++index)
    for (int value: values)
    {
        // int value = values[index];
        // std::cout << values[index] << " ";
        std::cout << value << " ";
        value = 0;
    }
}

void ArrayInitDemo()
{
    // Zero array initialization - initialize all elements in the array ({0})
    // int daysInMonth[12] = {0};

    // Full array initialization sets all elements in the array
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    //Init each element to specific value
    /* daysInMonth[0] = daysInMonth[2] = daysInMonth[4] = daysInMonth[6] = daysInMonth[7] =
        daysInMonth[9] = daysInMonth[11] = 31;
    daysInMonth[3] = daysInMonth[5] = daysInMonth[8] = daysInMonth[10] = 30;
    daysInMonth[1] = 28; */

    // Implicit array sizing - when using an array initilizatizer, the size of the array is optional
    // Use cases: 
    //  1. Size of the array will never change in my life
    //  2. For strings
    std::string monthNames[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    /*monthNames[0] = "Jan";
    monthNames[1] = "Feb";
    monthNames[2] = "Mar";
    monthNames[3] = "Apr";
    monthNames[4] = "May";
    monthNames[5] = "Jun";
    monthNames[6] = "Jul";
    monthNames[7] = "Aug";
    monthNames[8] = "Sep";
    monthNames[9] = "Oct";
    monthNames[10] = "Nov";
    monthNames[11] = "Dec";*/

    for (int index = 0; index < 12; ++index)
        std::cout << monthNames[index] << " has " << daysInMonth[index] << " days" << std::endl;

    // Partial array initialization - only some element values are set, the rest are zero-initialized.
    char name[100] = {'B', 'o', 'b'}; // "Bob"
    char companyName[] = "My Company";

    double rates[5] = {1.2, 3.4, 5.6, 7.8, 9.0};

    int x = 100;
    int numbers[10];
    double r = 5.6;

    // Off by one 
    //  Starting at 1 and therefore skipping the first element
    //  Indexing to size which is one after the last element
    //Init the array
    for (int index = 0; index < 10; ++index)
        numbers[index] = index + 1;

    for (int index = 0; index < 10; ++index)
        std::cout << numbers[index] << " ";
    std::cout << std::endl;
}

void main()
{
    ArrayInitDemo();

    // TODO: Remove once no longer used
    // Movie movie;
    // Movie movie2, movie3, movie4; // Support more than one movie
    const int maximumMovies = 100;
    Movie movies[maximumMovies];        // Stores five movies

    // Array Declarations Type Identifier Name [Expression (Integer)];
    //  All elements have the same type
    //  DO NOT USE to store unrelated values just to save variables
    //  Value inside the brackets is the size, number of elements, in the array
    //  Size must be:
    // 1. a compile-time constant
    // 2. > than 0
    // 3. Must be an integer
    
    // IMPORTANT:
    // Array is NOT part of the type
    // Other names for arrays: Collection, vector, list, set, array

    // All arrays store their elements continuously in memory
    // Local variables are stored on stack so be careful of stack space
       
    bool quit = false;
    while (!quit)
    {
        // Display menu
        std::cout << "Main Menu" << std::endl;
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
                    DisplayError("Invalid option");
                    break;
                }
            }
        }

        switch (input)
        {
            case MenuCommand::Add:
            {
                // Get the movie details
                // Find the first element not being used in the array
                // Store new movie there, if any
                Movie movie = AddMovie();

                int index;
                for (index = 0; index < maximumMovies; ++index)
                {
                    if (movies[index].title == "") // Find the first empty movie slot
                    {
                        movies[index] = movie;
                        break;
                    }
                }

                // TODO: Clean this up later
                if (index == maximumMovies)
                    DisplayError("No more space available");

                break;
            }
            case MenuCommand::Edit: DisplayWarning("Edit not implemented");
            case MenuCommand::Delete: DeleteMovie(movies[0]); break;
            case MenuCommand::View:
            {
                for (Movie movie: movies)
                {
                    if (movie.title != "")
                        ViewMovie(movie);

                }
                break;
            }

            case MenuCommand::Quit: quit = true; break;

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

Arrays: Multiple values stored as one
Array_declaration: Type identifier[Expression(integer number)]
The values in an array are called elements

Size (array)
 = Size(element) * Size (declaration)

*/
