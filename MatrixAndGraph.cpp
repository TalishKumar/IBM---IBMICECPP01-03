#include <iostream>
using namespace std;

void addEdge(int adjMat[][25], int row, int col)
{
    adjMat[row][col] = 1;
    adjMat[col][row] = 1;
}

class Node
{
public:
    int vertex{};
    Node* next{};
};

void create(Node* head[], int adjMat[][25], int noOfCon)
{
    Node* newNode{};
    Node* temp{};

    int row{ 0 }, col{ 0 };

    //Loop for each connection & get the connection matrix
    for (int i{ 0 }; i < noOfCon; ++i)
    {
        cout << "Enter the start node and end node in connection " << i + 1 << ':' << '\n';
        cin >> row >> col;
        addEdge(adjMat, row, col);

        newNode = new Node();
        newNode->vertex = col;
        temp = head[row];

        if (temp == NULL)
        {
            head[row] = newNode;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        newNode = new Node();
        newNode->vertex = row;
        temp = head[col];

        if (temp == NULL)
        {
            head[col] = newNode;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }
}

void display(Node* head[], int adjMat[][25], int noOfUsers)
{
    //Assign the proper values to each user
    for (int i{ 1 }; i <= noOfUsers + 1; ++i)
    {
        for (int j{ 1 }; j <= noOfUsers + 1; ++j)
        {
            if (adjMat[i][j] == 1)
            {
                adjMat[i][j] = j;
            }
        }
    }

    //print out the matrix
    cout << '\n' << "The representation of SocialNet users: \n\n";

    for (int row{ 1 }; row <= noOfUsers; ++row)
    {
        for (int col{ 1 }; col <= noOfUsers; ++col)
        {
            cout << adjMat[row][col] << " ";
        }

        cout << '\n';
    }

    //Print the friend list
    cout << "\nThe friends' list of all users: \n\n";

    Node* adj;
    int counter {0};
    for (int i{ 1 }; i < noOfUsers + 1; ++i)
    {
        cout << i << "->";
        adj = head[i];

        while (adj != NULL)
        {
            cout << adj->vertex << ' ';
            adj = adj->next;
            ++counter;
        }

        if (adj == NULL && counter == 0)
        {
            cout << 0;
        }

        cout << '\n';
        
        counter = 0;
    }
}

int main()
{
    //Get the number of users
    cout << "Enter the no. of users: ";
    int noOfUsers{ 0 };
    cin >> noOfUsers;

    Node* head[25]{ 0 };
    for (int i{ 0 }; i < noOfUsers; ++i)
    {
        head[i] = NULL;
    }

    //Get the number of connections
    cout << "\nEnter the no. of connections: ";
    int noOfCon{ 0 };
    cin >> noOfCon;

    //Create the array for matrix
    int adjMat[25][25]{ 0 };

    //Create the matrix
    create(head, adjMat, noOfCon);

    //Print the matrix
    display(head, adjMat, noOfUsers);

    return 0;
}
