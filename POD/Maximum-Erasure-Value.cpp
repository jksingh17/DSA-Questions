class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> map;
        int left=0,ans=0;
        int temp=0;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
            temp+=nums[i];
            while(map[nums[i]]>1){
                map[nums[left]]--;
                temp-=nums[left];

                left++;
            }
            
            
            ans=max(ans,temp);
        }
        return ans;
    }
};