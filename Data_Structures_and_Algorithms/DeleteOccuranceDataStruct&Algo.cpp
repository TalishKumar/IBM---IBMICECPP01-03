#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class LinkedList
{
public:
    Node* head;
    Node* tail;
    LinkedList()
    {
        head = NULL;
    }
    void append(int value);
    void deleteAllOccurrences(int key);
    void display();
};

void LinkedList::append(int value)
{
    Node* newNode{ new Node };
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = head;
        return;
    }
    else
    {
        tail->next = newNode;
        tail = tail->next;
        return;
    }
}

void LinkedList::deleteAllOccurrences(int key)
{
    Node* current{ new Node };
    Node* previous{ new Node };
    previous = head;
    current = head;

    while (current != NULL)
    {
        if (current->data == key)
        {
            if (current == head) 
            {
                head = current->next;
                delete current;
                current = head;
            }
            else 
            {
                previous->next = current->next;
                delete current;
                current = previous->next;
            }
        }
        else 
        {
            previous = current;
            current = current->next;
        }
    }
}

void LinkedList::display()
{
    Node* temp = head;
    cout << "\nThe list after deletion: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    cout << "\nEnter the size of the list: ";
    int N, value;
    LinkedList lst;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> value;
        lst.append(value);
    }
    cout << "\nEnter the element to be deleted: ";
    int delValue;
    cin >> delValue;

    lst.deleteAllOccurrences(delValue);
    lst.display();

    return 0;
}
