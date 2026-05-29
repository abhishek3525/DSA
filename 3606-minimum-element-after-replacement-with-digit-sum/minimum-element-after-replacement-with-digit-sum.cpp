class Solution {
public:
    int digitsum(int num){
        int sum=0;
        while(num){
            int lastdigit=num%10;
            sum+=lastdigit;
            num/=10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int sum=digitsum(nums[i]);
            mini=min(mini,sum);
        }
        return mini;
    }
};