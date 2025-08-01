#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        vector<int> ans;
        vector<bool> v(adj.size(),false);
        queue<int>q;
        q.push(0);
        v[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto &x:adj[node]){
                if(!v[x]){
                    v[x]=1;
                    q.push(x);
                }
            }
        }
        return ans;
    }
};