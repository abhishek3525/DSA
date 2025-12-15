class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long res=0;
        int n=prices.size();
        int i=0;
        while(i<n){
            int j=i+1;
            while(j<n and prices[j]==prices[j-1]-1) j++;
            res+=1LL*(j-i)*(j-i+1)/2;
            i=j;
        }
        return res;
    }
};