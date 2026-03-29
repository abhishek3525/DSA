class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(m, vector<bool>(1024, false)));
        dp[0][0][grid[0][0]]=1;
        int xor2=grid[0][0];
        for(int j=1;j<m;j++){
             xor2^=grid[0][j];
             dp[0][j][xor2]=1;
        }
        xor2=grid[0][0];
        for(int i=1;i<n;i++){
            xor2^=grid[i][0];
            dp[i][0][xor2]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                int no=grid[i][j];
                for(int k=0;k<1024;k++){
                    if(dp[i-1][j][k]){
                        int xor1=no^k;
                        dp[i][j][xor1]=1;
                    }
                    if(dp[i][j-1][k]){
                        int xor1=no^k;
                        dp[i][j][xor1]=1;
                    }
                }
                
            }
        }
        for(int k=0;k<1024;k++){
            if(dp[n-1][m-1][k])return k;
        }
        return -1;
    }
};