class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int maxi=INT_MIN;
        mp[1]=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            maxi=max(maxi,nums[i]);
        }
        int ans=1;
        for (auto& [i, count] : mp) {
            if (i == 1) continue;
            int len=0;
            int no=1;
            while(true){
                long long no1=pow(i,no);
                if(no1 > maxi) break;
                if(mp.find(no1)==mp.end()) break;
                if(mp[no1]==1){
                    len++;
                    ans=max(ans,len);
                    break;
                }
                len+=2;
                no*=2;
                ans=max(ans,len);
            }
        }
        int len1=mp[1];
        if(!(len1&1)) len1--;
        ans=max(ans,len1);
        return ans&1?ans:ans-1;
    }
};