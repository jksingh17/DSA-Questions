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
    bool isSymmetric(TreeNode* root) {
        if(!root) return 1;
        return check(root->left,root->right);
    }
    bool check(TreeNode*x,TreeNode*y){
        if(!x&& !y) return 1;
        if(!x || !y) return 0;
        return (x->val==y->val)&&check(x->left,y->right)&& check(x->right,y->left);
    }
};