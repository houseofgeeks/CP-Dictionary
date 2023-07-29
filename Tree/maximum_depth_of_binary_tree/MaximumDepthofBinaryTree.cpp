#include <bits/stdc++.h>
using namespace std;

// Maximum Depth of Binary Tree

// Given the root of a binary tree, find its maximum depth.
// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: 3

// Example 2:
// Input: root = [1,null,2]
// Output: 2

// Definition for a binary tree node.
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // If the tree is empty, the maximum depth is 0.
        if (root == nullptr) {
            return 0;
        }

        // Recursively calculate the maximum depth of the left and right subtrees.
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        // The maximum depth of the current node's subtree is the maximum of left and right subtrees,
        // plus one to account for the current node.
        return std::max(leftHeight, rightHeight) + 1;
    }
};

int main() {
    // Create a binary tree for demonstration purposes
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    int depth = solution.maxDepth(root);

    std::cout << "Maximum depth of the binary tree: " << depth << std::endl;

    // Clean up the memory allocated for the binary tree
    // (You may want to use a proper tree traversal for more complex trees)
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root;

    return 0;
}