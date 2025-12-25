class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(),happiness.rend());
        int n=happiness.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            if(happiness[i]<i or k--<=0) break;
            ans+=(happiness[i]-i);
           
        }
        return ans;
    }
};