#include<bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct Node 
{ 
    int data; 
    struct Node* left, *right; 
    Node(int data) 
    { 
        this->data = data; 
        left = right = NULL; 
    } 
}; 

// Prints the pre-order traversal of 
// a binary tree, provide the root node 
// of the same.
void printPreorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    // First deal with current node.
    cout << node->data << " "; 
  
    // Recur on left sub-tree.
    printPreorder(node->left);  
  
    // Recur on right sub-tree.
    printPreorder(node->right); 
}  

// Prints the in-order traversal of 
// a binary tree, provide the root node 
// of the same.
void printInorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    // Recur on left sub-tree.
    printInorder(node->left); 
  
    // Deal with current node.
    cout << node->data << " "; 
  
    // Recur on right sub-tree.
    printInorder(node->right); 
} 

// Prints the post-order traversal of 
// a binary tree, provide the root node 
// of the same.
void printPostorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    // Recur on left sub-tree.
    printPostorder(node->left); 
  
    // Recur on right sub-tree.
    printPostorder(node->right); 
  
    // Now deal with current node.
    cout << node->data << " "; 
} 

int main() 
{ 
    struct Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 

    /*

    The above statements create the 
    binary tree as follows:

        1
       / \
	  2   3
	 / \
	4   5

    */ 
  
    cout << "\nPreorder traversal of binary tree is \n"; 
    printPreorder(root); 
  
    cout << "\nInorder traversal of binary tree is \n"; 
    printInorder(root);  
  
    cout << "\nPostorder traversal of binary tree is \n"; 
    printPostorder(root); 
  
    return 0; 
} 