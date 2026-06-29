class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.rbegin(),nums.rend());
        long long sum=0;
        for(int i=0;i<k;i++){
            if(nums[i]<0 or mul<=0){
                sum+=nums[i];
                continue;
            }
            sum+=(1LL*mul*nums[i]);
            mul--;

        }
        return sum;
    }
};