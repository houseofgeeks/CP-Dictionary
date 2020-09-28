#include<iostream>
using namespace std;
struct node								// structure of an element of the tree
{
	int data;
	node *right,*left;
};
node *newnode(int info)					//function to create new elements in a tree
{
	node *temp=new node;
	temp->data=info;
	temp->right=temp->left=NULL;
	return temp;
}
int count_nodes(node *root, int &c)		//function to count the number of elements in a tree
{
	if(root==NULL)
		return c;
	count_nodes(root->left,c);
	count_nodes(root->right,c);
	return ++c;
}
int main()
{
	node *root=NULL;
	int c=0;
	/*
		root->	1
			   / \
			  2   3
		    / \  / \
		   4  5 6  7
		  /       / \ 
		 8       9  10
	*/
	root=newnode(1);
	root->right=newnode(2);
	root->left=newnode(3);
	root->right->right=newnode(4);
	root->right->left=newnode(5);
	root->left->right=newnode(6);
	root->left->left=newnode(7);
	root->right->right->right=newnode(8);
	root->left->left->right=newnode(9);
	root->left->left->left=newnode(10);
	cout<<"Number of nodes:"<<count_nodes(root,c);
	
}
