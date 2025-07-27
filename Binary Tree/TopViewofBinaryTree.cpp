#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        if(!root) return {};
        map<int,int> map;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            Node* temp=x.first;
            int line=x.second;
            if(map.find(line)==map.end()) map[line]=temp->data;
            if(temp->left!=nullptr) q.push({temp->left,line-1});
            if(temp->right!=nullptr) q.push({temp->right,line+1});   
        }
        vector<int> ans;
        for(auto i:map){
            ans.push_back(i.second);
        }
        return ans;
    }
   
};