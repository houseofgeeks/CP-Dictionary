#include <bits/stdc++.h>
using namespace std;

// Same Tree

// Given the roots of two binary trees p and q, check if they are the same or not.
// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

// Example 1:
// Input: p = [1,2,3], q = [1,2,3]
// Output: true

// Example 2:
// Input: p = [1,2], q = [1,null,2]
// Output: false

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both trees are empty, they are identical.
        if (p == nullptr && q == nullptr) {
            return true;
        }

        // If one tree is empty and the other is not, they are not identical.
        if ((p != nullptr && q == nullptr) || (p == nullptr && q != nullptr)) {
            return false;
        }

        // Recursively check if left and right subtrees are identical, as well as the current node value.
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        bool value = (p->val == q->val);

        // Both subtrees and the current node value must be identical for the trees to be identical.
        if (left && right && value) {
            return true;
        }

        return false;
    }
};

int main() {
    // Create two binary trees for demonstration purposes
    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);

    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);

    Solution solution;
    bool isIdentical = solution.isSameTree(tree1, tree2);

    if (isIdentical) {
        std::cout << "The two binary trees are identical." << std::endl;
    } else {
        std::cout << "The two binary trees are not identical." << std::endl;
    }

    // Clean up the memory allocated for the binary trees
    // (You may want to use a proper tree traversal for more complex trees)
    delete tree1->left;
    delete tree1->right;
    delete tree1;

    delete tree2->left;
    delete tree2->right;
    delete tree2;

    return 0;
}