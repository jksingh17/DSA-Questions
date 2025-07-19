#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Helper function to count subarrays with at most k odd numbers
    int solve(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int left = 0, ans = 0, odd = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 1) odd++;
            while (odd > k) {
                if (nums[left] % 2 == 1) odd--;
                left++;
            }
            ans += (i - left + 1);
        }
        return ans;
    }

    // Main function to count subarrays with exactly k odd numbers
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    int result = sol.numberOfSubarrays(nums, k);
    cout << "Number of nice subarrays with exactly " << k << " odd numbers: " << result << endl;

    return 0;
}
