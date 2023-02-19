// This program allows a user to enter a password in an account and
// verify if it fits the requirements.

#include <iostream>
#include <cctype>
#include <cstring>  // for strlen
using namespace std;

// Function prototype
void welcomeGreeting();
bool testPassword(char [], int);
bool noUpper(char[], int);
bool noNum(char[], int);

int main()
{
    welcomeGreeting();   // Call function welcomeGreeting
    
    const int SIZE = 8;  // Array Size
    char user[SIZE];     // To hold a user password
    long length;         // Length of the password
    
    // Prompt user to enter password
    cout << "Please enter your seven digit password\n";
    cout << "(It must be 7 letters/numbers long with at\n";
    cout << "least 1 uppercase letter and 1 number):\n";
    cin >> user;
    
    // Determine the if the password is the valid length
    length = strlen(user);
    
    
    // Determine whether it is valild
    if (testPassword(user, SIZE))
    {
        cout << "The password has been accepted.\n";
    }
    else
    {
        cout << "The password has not been accepted.\n";
    }
    
    // Determine whether is length is valid
    if (length != SIZE -1)
    {
        cout << "The password is not 7 characters long.\n";
    }
    
    // Display if at least 1 uppercase is not in password
    if (noUpper(user, SIZE))
    {
        cout << "The password does not have at least\n";
        cout << "1 uppercase letter.\n";
    }
    
    // Display if at least 1 number is not in password
    if (noNum(user, SIZE))
    {
        cout << "The password does not have at least\n";
        cout << "1 number.\n";
    }
    return 0;
}

//*****************************************
// Definition of function welcomeGreeting *
// This function displays a message       *
//*****************************************

void welcomeGreeting()
{
    // For loop which creates diamond design
    int n = 3, k , c , space = 1;
    space = n - 1;
    
    for(k= 1; k <= n; k++)
    {
        for(c = 1; c <= space; c++)
        {
            cout << " ";
        }
        space--;
        for(c = 1;c <= 2 * k - 1; c++)
        {
            cout << "*";
        }
        cout << endl;
    }
    space = 1 ;
    for(k = 1; k <= n; k++)
    {
        for(c = 1; c <= space; c++)
        {
            cout << " ";
        }
        space++;
        for(c = 1;c <= 2 * (n - k) - 1; c++)
        {
            cout << "*";
        }
        cout << endl;
    }
    
    cout << "Welcome to the Valid Password Program!\n";
    cout << endl;
    cout << "This program is desgined to prompt the user\n";
    cout << "to enter a password in an account and verify\n";
    cout << "if it fits the requirements\n";
    cout << endl;
    cout << "Designed by: J & J Enterprise.\n";
    cout << endl;
    
    // For loop which creates diamond design
    space = n - 1;
    for(k = 1; k <= n; k++)
    {
        for(c = 1;c <= space; c++)
        {
            cout << " ";
        }
        space--;
        for(c = 1; c <= 2 * k - 1; c++)
        {
            cout << "*";
        }
        cout << endl;
    }
    space = 1;
    for(k = 1; k <= n; k++)
    {
        for(c = 1;c <= space; c++)
        {
            cout << " ";
        }
        space++;
        for(c = 1;c <= 2 * (n - k) - 1; c++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

//*****************************************
// Definition of function testPassword    *
// This function determines whether the   *
// user provided a valid password.        *
//*****************************************

bool testPassword(char userPass[], int size)
{
    bool passUpper = false;
    bool passNum = false;
    int count; // Loop counter
    long length; // Length of the password
    
    length = strlen(userPass);
    
    // Test the characters for 1 uppercase letter and 1 number
    for (count = 0; count < size; count++)
    {
        if (isupper(userPass[count]))
            passUpper = true;
        
        else if (isdigit(userPass[count]))
            passNum = true;
    }
    if (passUpper & passNum & length == size - 1)
        passNum = true;
    
    else
        passNum = false;
    return passNum;
}

//*******************************************
// Definition of function noUpper           *
// This function determines if the password *
// has at least 1 uppercase letter.         *
//*******************************************

bool noUpper(char upper[], int size)
{
    int count; // Loop counter
    
    for (count = 0; count < size; count++)
    {
        if (isupper(upper[count]))
            return false;
    }
    return true;
}

//***********************************
// Definition of function noUpper   *
// This function determines if the  *
// password has at least 1 number.  *
//***********************************

bool noNum(char number[], int size)
{
    int count; // Loop counter
    
    for (count = 0; count < size; count++)
    {
        if (isdigit(number[count]))
            return false;
    }
    return true;
}
