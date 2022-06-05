#include <iostream>
#include <string.h>
using namespace std;

int main()   //DO NOT change the 'main' signature
{
    //Get user SSN
    cout << "Enter the SSN number:\n";
    string userSSN{};
    cin >> userSSN;
    
    //Get user SSN length
    int userSSNLen{};
    for (int i{0}; i < userSSN[i] != '\0'; ++i)
    {
        ++userSSNLen;
    }
    
    //Create array for chars
    char userSSNCh[10]{};
    
    //Create array for digits
    int userSSNInt[10]{};
    
    //Iterators
    int iteratorCh{0};
    int iteratorInt{0};
    
    //Put char & int types in its own array
    for (int i{0}; i < userSSNLen; ++i)
    {
        if(isalpha(userSSN[i]))
        {
           userSSNCh[iteratorCh] = userSSN[i];
           
           ++iteratorCh;
        }
        else if(isdigit(userSSN[i]))
        {
            userSSNInt[iteratorInt] = userSSN[i] - 48;
            
            ++iteratorInt;
        }
    }
    
    //Length of char & int array
    int userSSNChLen{sizeof(userSSNCh)/sizeof(userSSNCh[0])};
    int userSSNIntLen{sizeof(userSSNInt)/sizeof(userSSNInt[0])};
    
    //Input validate chars
    bool validCh{false};
    
    for (int i{0}; i < userSSNChLen; ++i)
    {
        if (userSSNCh[i] < 91 && userSSNCh[i] > 64)
        {
            validCh = true;
        }
        else if (userSSNCh[i] == 0)
        {
            validCh = true;
        }
        else
        {
            validCh = false;
            break;
        }
    }
    
    //Input validate int
    bool validInt{false};
    
    for (int i{0}; i < userSSNIntLen; ++i)
    {
        if (userSSNInt[i] < 0 || userSSNInt[i] > 9)
        {
            validInt = false;
            break;
        }
        else
        {
            validInt = true;
        }
    }
    
    //Output condition statement
    if (validInt && validCh)
    {
        cout << "Valid SSN number";
    }
    else if (userSSNLen != 10)
    {
        cout << "Invalid SSN number";
        return 0;
    }
    else
    {
        cout << "Invalid SSN number";
    }
    
    return 0;
}
