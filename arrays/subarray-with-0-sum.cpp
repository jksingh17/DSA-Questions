#include<bits/stdc++.h>
 using namespace std;
 class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        // Your code here
        unordered_map<int,int> mp;
        int sum=0;
        mp[0]=1;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(mp.find(sum)!=mp.end()) return true;
            mp[sum]++;
            
        }
        return false;
    }
};