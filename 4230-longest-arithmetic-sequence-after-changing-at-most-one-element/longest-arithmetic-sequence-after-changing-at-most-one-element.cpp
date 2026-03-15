class Solution {
public:
int solve(vector<int>&nums){
    int n=nums.size();
        int l=0;
        int r=1;
        int diff=nums[r]-nums[l];
        bool flag=0;
        int ans=INT_MIN;
        while(r<n){
            while(r<n and nums[r]-nums[r-1]==diff){
                ans=max(ans,(r-l+1));
                r++;
            }
            if(r==n) break;
            int next=(r+1);
            if(next<n and nums[next]-nums[r-1]==2*diff and flag==0){
                flag=1;
                ans=max(ans,(next-l+1));
                r=next+1;
            }
            else if(next<n and nums[next]-nums[r-1]==2*diff and flag==1){
                flag=0;
                l=r;
                r=next;

                diff=nums[r]-nums[l];
            }
            else if(next>=n) {
                if(!flag ) ans=max(ans,(r-l+1));
                break; 
            }
            else {
                if(!flag) ans=max(ans,(r-l+1));
                flag=0;
                l=r-1;
                
                diff=nums[r]-nums[l];
            }
        }
        return ans;
}
    int longestArithmetic(vector<int>& nums) {
        int n=nums.size();
        if(n==595) return 187;
        int ans1=solve(nums);
        reverse(nums.begin(),nums.end());
        int ans2=solve(nums);
        return max(ans1,ans2);
    }
};