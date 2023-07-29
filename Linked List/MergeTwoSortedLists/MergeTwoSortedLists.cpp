#include <bits/stdc++.h>
using namespace std;

// Leetcode 21. Merge Two Sorted Lists

// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.

// Example 1:
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// Example 2:
// Input: list1 = [], list2 = []
// Output: []

// Example 3:
// Input: list1 = [], list2 = [0]
// Output: [0]

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int val) : val(val), next(nullptr) {}
};

class Solution {
private:
    /**
     * Helper function to merge two sorted linked lists.
     * @param first The head of the first linked list.
     * @param second The head of the second linked list.
     * @return The head of the merged linked list.
     */
    ListNode* solve(ListNode* first, ListNode* second) {
        if (first->next == nullptr) {
            first->next = second;
            return first;
        }

        ListNode* curr1 = first;
        ListNode* next1 = first->next;
        ListNode* curr2 = second;
        ListNode* next2 = second->next;

        while (next1 != nullptr && curr2 != nullptr) {
            if (curr2->val >= curr1->val && curr2->val <= next1->val) {
                curr1->next = curr2;
                next2 = curr2->next;
                curr2->next = next1;
                curr1 = curr2;
                curr2 = next2;
            } else {
                curr1 = next1;
                next1 = next1->next;

                if (next1 == nullptr) {
                    curr1->next = curr2;
                    return first;
                }
            }
        }

        return first;
    }

public:
    /**
     * Merges two sorted linked lists into a single sorted linked list.
     * @param list1 The head of the first sorted linked list.
     * @param list2 The head of the second sorted linked list.
     * @return The head of the merged sorted linked list.
     */
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }

        if (list1->val < list2->val) {
            return solve(list1, list2);
        } else {
            return solve(list2, list1);
        }
    }
};

int main() {
    Solution solution;

    // Example 1:
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* result1 = solution.mergeTwoLists(list1, list2);
    ListNode* curr1 = result1;
    while (curr1 != nullptr) {
        std::cout << curr1->val << " ";
        curr1 = curr1->next;
    }
    std::cout << std::endl;

    // Example 2:
    ListNode* list3 = nullptr;

    ListNode* list4 = nullptr;

    ListNode* result2 = solution.mergeTwoLists(list3, list4);
    ListNode* curr2 = result2;
    while (curr2 != nullptr) {
        std::cout << curr2->val << " ";
        curr2 = curr2->next;
    }
    std::cout << std::endl;

    // Example 3:
    ListNode* list5 = nullptr;

    ListNode* list6 = new ListNode(0);

    ListNode* result3 = solution.mergeTwoLists(list5, list6);
    ListNode* curr3 = result3;
    while (curr3 != nullptr) {
        std::cout << curr3->val << " ";
        curr3 = curr3->next;
    }
    std::cout << std::endl;

    return 0;
}