// Extended Boyer Moore’s Voting Algorithm: 

// Article Link: https://takeuforward.org/data-structure/majority-elementsn-3-times-find-the-elements-that-appears-more-than-n-3-times-in-the-array/

// Approach: 

// Initialize 4 variables:
// cnt1 & cnt2 – for tracking the counts of elements
// el1 & el2 – for storing the majority of elements.
// Traverse through the given array.
// If cnt1 is 0 and the current element is not el2 then store the current element of the array as el1 along with increasing the cnt1 value by 1.
// If cnt2 is 0 and the current element is not el1 then store the current element of the array as el2 along with increasing the cnt2 value by 1.
// If the current element and el1 are the same increase the cnt1 by 1.
// If the current element and el2 are the same increase the cnt2 by 1.
// Other than all the above cases: decrease cnt1 and cnt2 by 1.
// The integers present in el1 & el2 should be the result we are expecting. So, using another loop, we will manually check their counts if they are greater than the floor(N/3).

// Intuition: 

// If the array contains the majority of elements, their occurrence must be greater than the floor(N/3). Now, we can say that the count of minority elements and majority elements is equal up to a certain point in the array. So when we traverse through the array we try to keep track of the counts of elements and the elements themselves for which we are tracking the counts. 

// After traversing the whole array, we will check the elements stored in the variables. Then we need to check if the stored elements are the majority elements or not by manually checking their counts.

// Complexity Analysis

// Time Complexity: O(n) + O(n), where n = size of the given array.
// Reason: The first O(n) is to calculate the counts and find the expected majority elements. The second one is to check if the calculated elements are the majority ones or not.

// Space Complexity: O(1) as we are only using a list that stores a maximum of 2 elements. The space used is so small that it can be considered constant.

#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> v) {
    int n = v.size(); //size of the array

    int cnt1 = 0, cnt2 = 0; // counts
    int el1 = INT_MIN; // element 1
    int el2 = INT_MIN; // element 2

    // applying the Extended Boyer Moore's Voting Algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != v[i]) {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && el1 != v[i]) {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (v[i] == el1) cnt1++;
        else if (v[i] == el2) cnt2++;
        else {
            cnt1--, cnt2--;
        }
    }

    vector<int> ls; // list of answers

    // Manually check if the stored elements in
    // el1 and el2 are the majority elements:
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el1) cnt1++;
        if (v[i] == el2) cnt2++;
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini) ls.push_back(el1);
    if (cnt2 >= mini) ls.push_back(el2);

    // Uncomment the following line
    // if it is told to sort the answer array:
    // sort(ls.begin(), ls.end()); //TC --> O(2*log2) ~ O(1);

    return ls;
}

int main()
{
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElement(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}
