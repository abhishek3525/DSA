class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int sm=0;
        int lg=0;
        for(int i=0;i<k;i++){
            sm+=nums[i];
        }
        int ind=nums.size()-1;
        while(k--){
            lg+=nums[ind];
            ind--;
        }
        return abs(lg-sm);
    }
};