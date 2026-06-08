class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>ans(n);
        int left=0;
        int right=n-1;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                ans[left]=nums[i];
                left++;
            }
            else if (nums[i]>pivot){
                ans[right]=nums[i];
                right--;
            }
        }
        right++;
        if(right<n){
            reverse(ans.begin()+right,ans.end());

        }
        for(int i=left;i<right;i++){
            ans[i]=pivot;
        }
        return ans;

    }
};