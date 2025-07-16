#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0); // To store frequency of each character in the window
        int left = 0, maxCount = 0, result = 0;

        for (int right = 0; right < s.length(); ++right) {
            count[s[right] - 'A']++;
            maxCount = max(maxCount, count[s[right] - 'A']);

            // If we need to change more than k characters, shrink window from left
            while ((right - left + 1) - maxCount > k) {
                count[s[left] - 'A']--;
                left++;
            }

            result = max(result, right - left + 1);
        }

        return result;
    }
};

int main() {
    Solution sol;
    string s = "AABABBA";
    int k = 1;

    cout << "Longest substring length: " << sol.characterReplacement(s, k) << endl;

    return 0;
}
