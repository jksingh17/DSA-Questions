#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        sort(inter.begin(),inter.end());
               vector<vector<int>>ans;
        int i=0,n=inter.size();
        while(i<n){
            if(ans.empty()||ans.back()[1]<inter[i][0]){
                ans.push_back(inter[i]);
            }
            else{
                ans.back()[1]=max(ans.back()[1],inter[i][1]);
            }
            i++;
        }
        return ans;
    }
};