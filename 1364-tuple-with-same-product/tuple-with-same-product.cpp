class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int prod=nums[i]*nums[j];
                mp[prod]++;
            }
        }
        int ans=0;
        for(auto [key,val]:mp){
            if(val<2) continue;
            int res=((val)*(val-1))/2*8;
            ans+=res;
        }
        return ans;
    }
};