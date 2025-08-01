#include<bits/stdc++.h>
using namespace std;
class Solution {
    
    void dfs(vector<vector<int>>&adj,int start,vector<bool>&v,vector<int>&temp){
        v[start]=1;
        temp.push_back(start);
        for(auto& x:adj[start]){
            if(!v[x]) dfs(adj,x,v,temp);
        }
    }
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        
        vector<vector<int>>adj(V);
      for (auto& edge : edges) {
    adj[edge[0]].push_back(edge[1]);
    adj[edge[1]].push_back(edge[0]);
}

        vector<bool>v(V,false);
      
        vector<vector<int>>ans;
        for(int i=0;i<V;i++){
           if(!v[i]){
                vector<int> temp;
            dfs(adj,i,v,temp);
            ans.push_back(temp);
           }
        }
        return ans;
    }
};
