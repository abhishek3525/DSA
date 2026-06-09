class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
        return 1LL*k*(maxi-mini);
    }
};