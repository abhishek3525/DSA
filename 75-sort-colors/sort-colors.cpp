class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        int i=0;
        while(i<=right){
            if(nums[i]==2){
                while(right>i and nums[right]==2)right--;
                swap(nums[i],nums[right]);
                
            }
            if(nums[i]==0){
                swap(nums[left],nums[i]);
                left++;
            }
            i++;
        }
        
    }
};