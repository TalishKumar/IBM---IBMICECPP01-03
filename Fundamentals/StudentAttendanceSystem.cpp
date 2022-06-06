#include <iostream>
using namespace std;

int main()   //DO NOT change the 'main' signature
{
    //Get number of students
    cout << "Enter number of students\n";
    short int numOfStudents{};
    cin >> numOfStudents;
    
    cout << '\n';
    
    //Initialize array for student information
    string student[numOfStudents][3]{};
    
    //For each student, get their information
    for (int i{0}; i < numOfStudents; ++i)
    {
        cout << "Enter roll number: ";
        cin >> student[i][0];
        
        cout << "Enter name: ";
        cin >> student[i][1];
        
        cout << "Enter gender: ";
        cin >> student[i][2];
        
        cout << '\n';
    }
    
    //Get roll number of student that needs to be found
    cout << "Enter the roll number of student to view: ";
    string studentRollNum{};
    cin >> studentRollNum;
    
    //Find the student with roll number 
    for (int i{0}; i < numOfStudents; ++i)
    {
        if (studentRollNum == student[i][0])
        {
            cout << student[i][1] << '\n';
            cout << student[i][2];
        }
    }
    
    return 0;
}
