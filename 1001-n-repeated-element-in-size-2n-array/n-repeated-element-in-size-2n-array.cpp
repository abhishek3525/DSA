class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
    //    unordered_map<int,int>mp;
    //    for(int i=0;i<nums.size();i++){
    //     if(mp.count(nums[i])) return nums[i];
    //     mp[nums[i]]++;
    //    } 
    //    return -1;
    //M-2
    for(int i=0;i<nums.size()-2;i++){
        if(nums[i]==nums[i+1] or nums[i]==nums[i+2]) return nums[i];
    }
    
    return nums[nums.size() - 1];
    }
};