#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res;

        for (const string& f : folder) {
            if (res.empty() || f.find(res.back() + "/") != 0) {
                res.push_back(f);
            }
        }

        return res;
    }
};

// Driver code
int main() {
    vector<string> folder = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};
    Solution sol;
    vector<string> result = sol.removeSubfolders(folder);

    cout << "Output: ";
    for (const string& f : result) {
        cout << f << " ";
    }
    cout << endl;

    return 0;
}
