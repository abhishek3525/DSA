class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n-1){
            if(nums[i]<nums[i+1]){
                i++;
            }else{
                break;
            }
        }
        if(i==0 or i==n-1) return 0;
        while(i<n-1){
            if(nums[i]>nums[i+1]){
                i++;
            }else{
                break;
            }
        }
        if(i==n-1) return 0;

        while(i<n-1){
            if(nums[i]<nums[i+1]){
                i++;
            }else{
                break;
            }
        }
        if(i==n-1) return 1;
        return 0;
    }
};