#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int min = 0, max = 0;
        for (auto c : s) {
            if (c == '(') {
                min++;
                max++;
            } else if (c == ')') {
                min--;
                max--;
            } else { // '*'
                min--;    // treat * as ')'
                max++;    // treat * as '('
            }

            // min can't be negative
            if (min < 0) min = 0;

            // too many unmatched ')'
            if (max < 0) return false;
        }
        // all open '(' must be closed in some interpretation
        return min == 0;
    }
};

// Test driver
int main() {
    Solution sol;
    
    string test1 = "(*))";
    string test2 = "(*()";
    string test3 = "(*(*)";
    string test4 = "(((******)))";
    string test5 = "((*)";

    cout << boolalpha;
    cout << "Test 1: " << sol.checkValidString(test1) << endl; // true
    cout << "Test 2: " << sol.checkValidString(test2) << endl; // false
    cout << "Test 3: " << sol.checkValidString(test3) << endl; // false
    cout << "Test 4: " << sol.checkValidString(test4) << endl; // true
    cout << "Test 5: " << sol.checkValidString(test5) << endl; // true

    return 0;
}
