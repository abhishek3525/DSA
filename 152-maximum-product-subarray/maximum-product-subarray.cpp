class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        int pre=1;
        for(int i=0;i<n;i++){
            pre*=nums[i];
            ans=max(pre,ans);
            if(pre==0) pre=1;
        }
        int suf=1;
        for(int i=n-1;i>=0;i--){
            suf*=nums[i];
            ans=max(suf,ans);
            if(suf==0) suf=1;
        }
        return ans;
    }
};