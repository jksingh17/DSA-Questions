#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> map;
        int ans=0;
        int left=0;
        
        for(int i=0;i<fruits.size();i++){
            map[fruits[i]]++;
             while (map.size() > 2) {
                map[fruits[left]]--;
                if (map[fruits[left]] == 0) {
                    map.erase(fruits[left]); 
                }
                left++;
            }
            ans=max(ans,i-left+1);
        }
        
        return ans;
    }
};