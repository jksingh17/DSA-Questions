#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> minPartition(int n) {
        vector<int> denominations = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        vector<int> ans;

        for (int coin : denominations) {
            while (n >= coin) {
                ans.push_back(coin);
                n -= coin;
            }
        }
        return ans;
    }
};

// Driver code
int main() {
    Solution sol;
    int n;

    cout << "Enter the amount: ";
    cin >> n;

    vector<int> result = sol.minPartition(n);

    cout << "Minimum number of currency notes/coins:\n";
    for (int note : result) {
        cout << note << " ";
    }
    cout << endl;

    return 0;
}
