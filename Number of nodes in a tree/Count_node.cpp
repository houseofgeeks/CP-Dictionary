#include<iostream>
using namespace std;
struct node										// structure of an element of the tree
{
	int data;
	node *child[2];								//an array for number of child of each node
};
node *newnode(int info,int n)					//function to create new elements in a tree
{
	node *temp=new node;
	temp->data=info;
	for(int i=0;i<n;i++)
		temp->child[i]=NULL;
	return temp;
}
int count_nodes(node *root, int &c,int n)		//function to count the number of elements in a tree with n children of each node
{
	if(root==NULL)
		return c;
	for(int i=0;i<n;i++)
		count_nodes(root->child[i],c,n);
	return ++c;
}
int main()
{
	node *root=NULL;
	int c=0,n=2;								//change the n to the number of child in a tree
	/*
		root->	1
			   / \
			  2   3
		    / \  / \
		   4  5 6  7
		  /       / \ 
		 8       9  10
	*/
	root=newnode(1,n);
	root->child[0]=newnode(2,n);
	root->child[1]=newnode(3,n);
	root->child[0]->child[0]=newnode(4,n);
	root->child[0]->child[1]=newnode(5,n);
	root->child[1]->child[0]=newnode(6,n);
	root->child[1]->child[1]=newnode(7,n);
	root->child[0]->child[0]->child[0]=newnode(8,n);
	root->child[1]->child[1]->child[0]=newnode(9,n);
	root->child[1]->child[1]->child[1]=newnode(10,n);
	cout<<"Number of nodes:"<<count_nodes(root,c,n);
	
}
