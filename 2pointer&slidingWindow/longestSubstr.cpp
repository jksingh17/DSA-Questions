#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> seen;
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.length(); right++) {
        while (seen.find(s[right]) != seen.end()) {
            seen.erase(s[left]);
            left++;
        }
        seen.insert(s[right]);
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int lastSeen[128] = {0}; // Store the last index (+1) where each character was seen
//         int maxLen = 0;          // The final answer: length of longest valid substring
//         int left = 0;            // Left boundary of the current window

//         for (int right = 0; right < s.size(); ++right) {
//             char ch = s[right];

//             // Update the left pointer to skip over duplicates
//             left = max(left, lastSeen[ch]);

//             // Update maxLen with the size of the current valid window
//             maxLen = max(maxLen, right - left + 1);

//             // Store the current character's index + 1
//             lastSeen[ch] = right + 1;
//         }

//         return maxLen;
//     }
// };


int main() {
    string s = "abcabcbb";
    cout << "Length of Longest Substring Without Repeating Characters: " << lengthOfLongestSubstring(s) << endl;
    return 0;
}
