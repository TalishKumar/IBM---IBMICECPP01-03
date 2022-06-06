#include<iostream> 
using namespace std;

char* reverseString(char* p)
{
    char* str{p};
    int length{0};
    
    while (*str != '\0')
    {
        ++length;
        ++str;
    }
    
    char* p1 {p};
    char* p2 {p+length-1};
    
    while (p1 < p2)
    {
        char temp {*p1};
        *p1 = *p2;
        *p2 = temp;
        
        ++p1;
        --p2;
    }
    
    return p;
}

int main()
{
    //Get user string
    cout << "Enter the string\n";
    char userString[100];
    cin >> userString;

    //Create the pointer to userString
    char* p{userString};
    
    //Cout
    cout << "Reversed String\n";
    
    //Call method to reverse the string
    char* result {reverseString(p)};
    
    //Print the reversed string
    while (*result != '\0')
    {
        cout << *result;
        ++result;
    }
    
    return 0;
}
