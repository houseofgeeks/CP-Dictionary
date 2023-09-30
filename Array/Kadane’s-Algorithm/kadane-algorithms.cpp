#include <iostream>
#include <vector>

using namespace std;

int kadaneAlgorithm(const vector<int>& nums) {
    int maxSum = nums[0];  // Initialize maxSum with the first element of the array.
    int currentSum = nums[0];  // Initialize currentSum with the first element of the array.

    for (size_t i = 1; i < nums.size(); ++i) {
        // Choose the maximum of the current element and the current element + currentSum
        currentSum = max(nums[i], currentSum + nums[i]);

        // Update maxSum if the currentSum is greater
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    vector<int> nums = {-2, -3, 4, -1, -2, 1, 5, -3};

    int maxSubarraySum = kadaneAlgorithm(nums);

    cout << "Maximum subarray sum: " << maxSubarraySum << endl;

    return 0;
}

