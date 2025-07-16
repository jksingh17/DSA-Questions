#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefixSumFreq;
        prefixSumFreq[0] = 1; // To handle subarrays starting from index 0

        int sum = 0, count = 0;

        for (int num : nums) {
            sum += num;

            // If (sum - goal) exists, it means there's a subarray that sums to goal
            if (prefixSumFreq.find(sum - goal) != prefixSumFreq.end()) {
                count += prefixSumFreq[sum - goal];
            }

            // Store the current sum in the map
            prefixSumFreq[sum]++;
        }

        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;

    int result = sol.numSubarraysWithSum(nums, goal);
    cout << "Number of subarrays with sum = " << goal << ": " << result << endl;

    return 0;
}
