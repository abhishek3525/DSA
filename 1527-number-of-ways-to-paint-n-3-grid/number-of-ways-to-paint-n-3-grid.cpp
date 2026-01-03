class Solution {
public:
    int N=1e9+7;
    int numOfWays(int n) {
        vector<vector<long long>>dp(n,vector<long long>(2,0));
        dp[0][0]=6;
        dp[0][1]=6;
        for(int i=1;i<n;i++){
            dp[i][0]=((dp[i-1][0]%N)*2)%N+((dp[i-1][1]%N)*2)%N;
            dp[i][1]=((dp[i-1][0]%N)*2)%N+((dp[i-1][1]%N)*3)%N;
        }
        return ((dp[n-1][0]%N)+(dp[n-1][1]%N))%N;
    }
};