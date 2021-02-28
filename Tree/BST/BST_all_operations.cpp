/* Program for insertion, searching and deletion in BST. */

#include<bits/stdc++.h>
using namespace std;


/* Each node contining data, left pointer and right pointer. */
struct Node
{
	int data;
	Node* left ;
	Node* right;
};


/* For creating a new node with the given value. */
Node* newNode(int val)
{
	Node *temp = new Node();
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

/* Searcing in BST. */
bool search(Node* root, int val)
{
	if (root != NULL)
	{
		if (root->data == val) return 1;
		else if (val > root->data) return search(root->right, val);
		else return search(root->left, val);
	}
	else return 0;

}

/* Inserting the value at the appropriate position. */
Node* insert(Node* root, int value)
{
	if (root == NULL)
	{
		return newNode(value);
	}

	else if (value <= root->data)
	{
		root->left = insert(root->left, value);
	}
	else
	{
		root->right = insert(root->right, value);
	}
	return root;
}


/* Function to find the minimum value in the subtree. */
Node* minValueNode(Node* node)
{
	Node* current = node;

	while (current && current->left != NULL) current = current->left;

	return current;
}

/*Deleting a value in the BST. */
Node* deleteNode(Node* root, int val)
{

	/* Searching the value. */
	if (root == NULL) return root;

	if (val < root->data) 	root->left = deleteNode(root->left, val);

	else if (val > root->data)	root->right = deleteNode(root->right, val);

	else
	{
		/*When there is no child or one child of the node
		  then we can directly delete it.*/
		if (root->left == NULL)
		{
			Node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			Node *temp = root->left;
			free(root);
			return temp;
		}

		/* If the node which we have to delete is having two childrens then
			we replace the current value with the inorder successor and
			delete that value from its original position. */

		Node* temp = minValueNode(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}


/* Printing the BST using pre-order traversal. */
void printBST(Node* root)
{
	if (root == NULL) return;
	printBST(root->left);
	cout << root->data << " ";
	printBST(root->right);
}

int main()
{

	Node *root = NULL;

	root = insert(root, 8);

	/* Number of nodes we want to insert. */
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		insert(root, val);
	}

	/* Printing the initial BST. */
	printBST(root);
	cout << endl;

	/* Searching a value and then delete it. */
	if (search(root, 8)) cout << "Value Present in BST. " << endl;
	else cout << "Not present! " << endl;

	/* Delete the node if present else will not affect other nodes. */
	int k = 2;
	deleteNode(root, k);

	/* Printing the BST. */
	printBST(root);

	return 0;
}

/*

Sample Input:
10
7 1 3 6 4 5 2 9 8 10

Output:
1 2 3 4 5 6 7 8 8 9 10
Value Present in BST.
1 3 4 5 6 7 8 8 9 10

*/
