#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());  // sort greed factors
    sort(s.begin(), s.end());  // sort cookie sizes

    int i = 0; // index for children
    int j = 0; // index for cookies

    while (i < g.size() && j < s.size()) {
        if (s[j] >= g[i]) {
            i++; // child is content
        }
        j++; // move to next cookie
    }

    return i; // number of content children
}

int main() {
    vector<int> g = {1, 2, 3};  // greed factor of children
    vector<int> s = {1, 1};     // size of cookies

    cout << "Maximum number of content children: " << findContentChildren(g, s) << endl;

    return 0;
}
