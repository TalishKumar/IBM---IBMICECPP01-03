#include<iostream> 
using namespace std;

int findArrayElement(int* p, int element, int size)
{
    bool found {false};
    
    for (int i{0}; i < size; ++i)
    {
        if (*(p + i) == element)
        {
            return i;
        }
        if (i == (size-1) && !found)
        {
            return -1;
        }
    }
}

int main()
{
    //Get the size of the array
    cout << "Enter the size of the array\n";
    int size{};
    cin >> size;
    
    //Get the elements of the array
    cout << "Enter the elements\n";
    int userArray[size]{};
    for (int i{0}; i < size; ++i)
    {
        cin >> userArray[i];
    }
    
    //Get the element to be searched
    cout << "Enter the element to search:\n";
    int element{};
    cin >> element;
    
    //Create pointer to userArray
    int* p{&userArray[0]};
    
    //Find the array element & assign it to a var
    int result{findArrayElement(p, element, size)};
    
    //Print the arrayIndex
    cout << result;
    
    return 0;
}
