#include <bits/stdc++.h>
using namespace std;

// Leetcode 148. Sort List

// Given the head of a linked list, return the list after sorting it in ascending order.

// Example 1:
// Input: head = [4,2,1,3]
// Output: [1,2,3,4]

// Example 2:
// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]

// Example 3:
// Input: head = []
// Output: []

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> ans;
        ListNode* temp = head;
        while (temp != NULL) {
            ans.push_back(temp->val);
            temp = temp->next;
        }

        sort(ans.begin(), ans.end());

        ListNode* dummy = new ListNode(-1);
        ListNode* x = dummy;

        for (int i = 0; i < ans.size(); i++) {
            ListNode* temp = new ListNode(ans[i]);
            x->next = temp;
            x = x->next;
        }

        return dummy->next;
    }
};

// Helper function to create a linked list from a vector of integers
ListNode* createLinkedList(const vector<int>& values) {
    ListNode* dummy = new ListNode(-1);
    ListNode* current = dummy;
    for(int i = 0; i < values.size(); i++){
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return dummy->next;
}

// Helper function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Example usage
    vector<int> values ;
    values[0] = 4;
    values[1] = 2;
    values[2] = 1;
    values[3] = 3;
    ListNode* inputList = createLinkedList(values);

    Solution solution;
    ListNode* sortedList = solution.sortList(inputList);

    cout << "Sorted Linked List: ";
    printLinkedList(sortedList);

    return 0;
}