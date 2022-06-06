#include<iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node* next;
};

class Stack 
{
public:
    Node* top;
    Stack() 
    {
        top = NULL;
    }
    void push(int data);
    int pop();
};

void Stack::push(int data) 
{
    Node* newNode = new Node();
    newNode->data = data;

    if (top == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = top;
    }

    top = newNode;
}


int Stack::pop() 
{
    Node* temp;
    int retVal{0};
    
    if(top==NULL) 
    {
        cout<<"Stack underflow"<<endl;
        return 0;
        
    }

    temp = top;
    retVal = temp->data;
    top = top->next;
    delete temp;

    return retVal;
}

int checkPalindrome(Stack stk, int arr[], int size)
{
    Node* next{ stk.top };
    Stack s;
    Stack s2;

    while (next != NULL)
    {
        s.push(next->data);
        next = next->next;
    }

    Node* next2{ s.top };

    while (next2 != NULL)
    {
        s2.push(next2->data);
        next2 = next2->next;
    }
    
     do
    {
        if (stk.top->data != s.top->data)
        {
            cout << "Popped element: " << s2.pop() << '\n';
            s.pop();
            return 0;
            break;
        }
        else
        {
            cout << "Popped element: " << s2.pop() << '\n';
            s.pop();
        }
        stk.top = stk.top->next;

    } while (stk.top != NULL);
    
    return 1;
}


int main() 
{
    Stack stk;
    int size, i, data;

    cin >> size;
    if (size < 2) 
    {
        cout << "Invalid input";
        return 0;
    }

    int arr[50]{0};
    for (i = 0; i < size; i++) 
    {
        cin >> data;
        arr[i] = data;
        stk.push(data);
    }

    if (checkPalindrome(stk, arr, size))
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }

    return 0;
}
