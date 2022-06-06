#include <iostream>
using namespace std;

class Node 
{
public:
	int data;
	Node* left, * right;
};

class BST 
{
public:
	Node* root;
	BST() 
	{
		root = NULL;
	}
	Node* insert(Node*, int);
	void preOrder(Node*);
	void inOrder(Node*);
	void postOrder(Node*);
};

Node* BST::insert(Node* root, int value) 
{
	Node* newNode = new Node{}; //Create space for new node

	newNode->data = value; //Set the value of a new node
	newNode->left = NULL;  //Set the left variable as NULL
	newNode->right = NULL; //Set the right variable as NULL

	if (root == NULL) //If the root not does not exist
	{
		root = newNode; //Make a root node
	}
	else if (value < root->data) //Else if the value is less than the root node
	{
		root->left = insert(root->left, value); //Recursively call the insert function to insert the value in the BST
	}
	else //Else the value is greater than or equal to the root node
	{
		root->right = insert(root->right, value); //Recursively call the insert function to insert the value in the BST
	}

	return root;
}

void BST::preOrder(Node* root) //Traverse is ROOT -> LEFT -> RIGHT
{
	Node* temp{ root }; //Make a temp var to hold the address of the root node

	//Check to make sure the node is not NULL
	if (temp == NULL)
	{
		return;
	}

	//First print the root node
	cout << temp->data << ' ';

	//Now recur on the left subtree
	preOrder(temp->left);

	//Now recur on the right subtree
	preOrder(temp->right);


	/* MY METHOD
	Node* temp{ root }; //Make a temp var to hold the address of the root node

	while (temp != NULL) //While temp is not NULL
	{
		cout << temp->data << ' ';  //This will print the root & keep printing the left nodes
		temp = temp->left; //Go the left
	}

	temp = root; //Reset temp to the root node address
	temp = temp->right; // Set is to the right so that the root is not printed twice

	while (temp != NULL) //While temp is not NULL
	{
		cout << temp->data << ' '; //Print the data of the node
		temp = temp->right; //Keep going to the right
	}
	*/
}

void BST::inOrder(Node* root) //Traverse is LEFT -> ROOT -> RIGHT
{
	Node* temp{ root }; //Make a temp var to hold the address of the root node

	if (temp == NULL) //Make sure that the node we are getting is not NULL
	{
		return;
	}

	//First recur on the left child
	inOrder(temp->left);

	//Print the data of the node
	cout << temp->data << ' ';

	//Now recur on the right child
	inOrder(temp->right);
}


void BST::postOrder(Node* root) 
{
	Node* temp{ root }; //Make a temp var to hold the address of the root node

	if (temp == NULL) //Make sure that the node we are getting is not NULL
	{
		return;
	}

	//First recur on the left child
	postOrder(temp->left);

	//Now recur on the right child
	postOrder(temp->right);

	//Print the data of the node
	cout << temp->data << ' ';
}

int main()
{
	BST tree;
	string ch = "yes";
	int num;

	do 
	{
		cout << "Enter the element to be inserted in the tree\n";
		cin >> num;
		tree.root = tree.insert(tree.root, num);
		cout << "Do you want to insert another element(yes/no)?\n";
		cin >> ch;
	} while (ch.compare("yes") == 0);

	cout << "Preorder Traversal : The elements in the tree are:\n";
	tree.preOrder(tree.root);
	cout << "\n";
	cout << "Inorder Traversal : The elements in the tree are:\n";
	tree.inOrder(tree.root);
	cout << "\n";
	cout << "Postorder Traversal : The elements in the tree are:\n";
	tree.postOrder(tree.root);
	cout << "\n";

	return 0;
}



