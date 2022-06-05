#include<iostream> 

using namespace std;

int* sortArray (int* ptr, int size)
{
    int temp{};
    
    for (int i{0}; i < size; ++i)
    {
        for (int j{i+1}; j < size; ++j)
        {
            if (ptr[i] > ptr[j])
            {
                temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j]=temp;
            }
        }
    }
    
    return ptr;
}

int main()
{
    //Get the size of an array
    cout << "Enter the size of the array\n";
    int size{};
    cin >> size;
    
    //Get the elements to be sorted
    cout << "Enter the elements\n";
    int userArray[size]{};
    for (int i{0}; i < size; ++i)
    {
        cin >> userArray[i];
    }
    
    //Starting address of userArray
    int* ptr{&userArray[0]};
    
    //Sort array by calling method
    int* result {sortArray(ptr, size)};
    
    for (int i{0}; i < size; ++i)
    {
        cout << *result << '\n';
        ++result;
    }
    
    return 0;
}
