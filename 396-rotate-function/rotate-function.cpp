class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=0;
        int mul=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mul+=(i*nums[i]);
        }
        int res=mul;
        for(int i=n-1;i>0;i--){
            int temp=mul+sum-n*nums[i];
            res=max(res,temp);
            mul=temp;
        }
        return res;
    }
};