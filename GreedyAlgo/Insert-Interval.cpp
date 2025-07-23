#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& newi) {
        vector<vector<int>>ans;
        int i=0,n=inter.size();
        while(i<inter.size() && inter[i][1]<newi[0]){
            ans.push_back(inter[i]);
            i++;
        }
        while(i<n && inter[i][0]<=newi[1]){
            newi[0]=min(newi[0],inter[i][0]);
            newi[1]=max(newi[1],inter[i][1]);
            i++;
        }
        ans.push_back(newi);
        while(i<inter.size() && inter[i][1]>newi[0]){
            ans.push_back(inter[i]);
            i++;
        }
        return ans;
    }
};