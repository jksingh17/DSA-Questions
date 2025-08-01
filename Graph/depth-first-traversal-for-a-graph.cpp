#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    void solve(vector<vector<int>>& adj,vector<bool>&v,int start,vector<int>&dfs){
        v[start]=1;
        dfs.push_back(start);
        for(auto& x:adj[start]){
            if(!v[x]){
                solve(adj,v,x,dfs);
            }
        }
        
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int>dfs;
        vector<bool> v(adj.size());
        int start=0;
        solve(adj,v,start,dfs);
        return dfs;
    }
};