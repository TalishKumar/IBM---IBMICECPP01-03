#include <iostream>
using namespace std;


int main()   //DO NOT change the 'main' signature
{
    //Get use email ID
    string userEmail{};
    getline(cin, userEmail);
    
    //Get length of email ID
    int userEmailLen{0};
    for (int i {0}; i < userEmail[i] != '\0'; ++i)
    {
        ++userEmailLen;
    }
    
    //Input validate email (whitespace)
    bool validEmailSpace{false};
    
    for (int i{0}; i < userEmailLen; ++i)
    {
        if (userEmail[i] - 1 == ' ')
        {
            break;
        }
        else
        {
            validEmailSpace = true;
        }
    }
    
    //Input validate email (has @ & .)
    bool validEmailSymbol1{false};
    bool validEmailSymbol2{false};
    bool hasValidSymbols{false};
    
    for (int i {0}; i < userEmailLen; ++i)
    {
        if (userEmail[i] == 64)
        {
            validEmailSymbol1 = true;
            
            if (validEmailSymbol2)
            {
                validEmailSymbol2 = false;
                break;
            }
        }
        if (userEmail[i] == 46)
        {
            validEmailSymbol2 = true;
        }
    }
    
    if (validEmailSymbol1 && validEmailSymbol2)
    {
        hasValidSymbols = true;
    }
    
    //Output conditional statement
    if (validEmailSpace && hasValidSymbols)
    {
        cout << "Valid email Id";
    }
    else
    {
        cout << "Invalid email Id";
    }
    
    return 0;
}
