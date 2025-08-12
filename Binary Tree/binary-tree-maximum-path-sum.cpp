
#include<bits/stdc++.h>
 using namespace std;
  struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  class Solution {
public:

    int check(TreeNode* root,int &ans){
        if(!root) return 0;
        int left=max(0,check(root->left,ans));
        int right=max(0,check(root->right,ans));
        ans=max(ans,(left+right+root->val));
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        check(root,ans);
        return ans;
    }
};