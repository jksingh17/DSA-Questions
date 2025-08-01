#include<bits/stdc++.h>
using namespace std;
class Solution {
    void dfs(vector<vector<int>>&adj,vector<bool>&v,int start){
        v[start]=1;
        for(auto& x:adj[start]){
            if(!v[x]){
                dfs(adj,v,x);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& mt) {
        int n=mt.size();
        vector<vector<int>>adj(mt.size());
        for(int i=0;i<mt.size();i++){
            for(int j=0;j<mt[i].size();j++){
                if(mt[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);

                }
            }
        }
        vector<bool> v(n,false);
        
        int count=0;
        for(int i=0;i<n;i++){
            if(!v[i]){
                count++;
                dfs(adj,v,i);
            }
        }
        return count;

    }
};