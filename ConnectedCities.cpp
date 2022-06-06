#include <iostream>
using namespace std;

//Define class node
class Node
{
public:
	int vertex{}; //Integer value of the ending node of the connected edge
	int weight{}; //Store the edge value
	Node* next{}; //Storing the address of the next variable in the list
};

//This function with create the directed, weighted graph
void create(Node* head[], int conRoad) /*Takes an array of pointers as its parameter& the number of connections(edges) for the for loop*/
{
	//Define the required vars
	int v1{ 0 }, v2{ 0 };
	int weight{ 0 }; //the distance of the roads

	//Define the required node variables
	Node* newNode{}; //used to create new nodes
	Node* temp{}; //a node used to hold temporary data

	//Get information for the graph (start node, end node, & weight)
	for (int i{ 0 }; i < conRoad; ++i)
	{
		//Get the starting node and the ending node
		cout << "Enter the start node (city) and the end node (city) in the connection " << i+1 << ": ";
		cin >> v1 >> v2;

		//Get the distance (weight) of each road (edge)
		cout << "Enter the distance (weight): ";
		cin >> weight;

		//Create a new node using the node class
		newNode = new Node();
		newNode->vertex = v2; //remember vertex is only meant to hold the value of the ending node of the connected edge
		newNode->weight = weight; //this will hold the weight of the edge (road)

		//A temp variable to hold the v1 index value of the "head" pointer array
		temp = head[v1];

		//If the head of the list is NULL then set the new node as the head of the list
		if (temp == NULL)
		{
			head[v1] = newNode;
		}
		else //Otherwise iterate to the end of the list and set the new node there
		{
			while (temp->next != NULL)
			{
				temp = temp->next;
			}

			temp->next = newNode;
		}
	}

	cout << '\n';
}

//Function to display the adjacency list that has been created
void display(Node* head[], int numCity, int conRoad) //Takes an array of pointers as its parameter, the number of cities (vertices), & the number of connections
{
	//Define required variable(s)
	Node* adj{};
	Node* adjTemp{};

	cout << "The distance between the connecting cities are:\n";

	//Create an array to store the iteration
	int arr[25]{0};

	//Create counter for each vertex to store in array
	int count{0};

	//Iterate through the list and dispaly each node's memeber values
	for (int i{ 0 }; i < numCity; ++i)
	{
		adj = head[i];
		adjTemp = head[i+1];

		if (adj == NULL) //If it is null
		{
			cout << i << ' ';
			cout << "- " << "No connecting roads found"; //Then no connecting roads exist
			cout << '\n';
		}
		else //If it is not null
		{

			while (adj != NULL) //While it is not null
			{
				if (adjTemp == adj && adjTemp->next != NULL && adj->vertex > adjTemp->vertex)
				{
					cout << i << ' ';
					cout << "-> " << adjTemp->vertex << " Distance: " << adjTemp->weight; //Print out the Vertex, the edge, and the vertex it is connected to
					cout << '\n';

					adjTemp = adjTemp->next;
					++count; //Add to the counter for how many connections the particular vertex has
				}

				cout << i << ' ';
				cout << "-> " << adj->vertex << " Distance: " << adj->weight; //Print out the Vertex, the edge, and the vertex it is connected to
				cout << '\n';

				adj = adj->next;
				++count; //Add to the counter for how many connections the particular vertex has

			}

			arr[i] = count; //Set that counter number to the associated index (city number) of the array
		}

		count = 0; //reset the counter for the next vertex
	}

	cout << '\n';

	if (!conRoad) //If the number of connections entered is 0
	{
		cout << "No city has any connecting road.\n"; //Then we know that there will be no connecting roads
	}
	else //If the number of connecting roads is greater than 0
	{
		//variable to store the largest connecting city
		int store{0};

		for (int i{ 1 }; i < conRoad; ++i) //For each connection
		{
			if (arr[0] < arr[i]) //iterate through the array
			{
				store = i; //and set the index which has the greatest number of connections to the store variable
			}
		}

		//Finally, print out the index (which is really the city) that has the greatest number of connections
		cout << store << " is the city with the highest connecting roads.\n";
	}
}

int main() 
{
	//Declare an array of pointers of the type Node class
	Node* head[25]{ 0 };

	//Get the number of cities from user
	cout << "Enter the no. of cities: ";
	int numCity{ 0 };
	cin >> numCity;

	//Get the number of one-way connecting roads
	cout << "Enter the no. of connecting (one-way) roads: ";
	int conRoad{ 0 };
	cin >> conRoad; cout << '\n';

	//Call the create & dispaly functions
	create(head, conRoad);
	display(head, numCity, conRoad);

	return 0;
}

