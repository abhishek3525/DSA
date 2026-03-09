class Solution {
    const int N = 1e9 + 7;
public:
    int dp[201][201][3];

    int fn(int zero,int one,int prev,int &limit){
        if(zero==0 && one==0) return 1;

        int &res = dp[zero][one][prev+1];
        if(res != -1) return res;

        long long zeroStart = 0;
        long long oneStart = 0;

        if(prev==1 || prev==-1){
            for(int i=1;i<=min(zero,limit);i++){
                zeroStart = (zeroStart + fn(zero-i,one,0,limit)) % N;
            }
        }

        if(prev==0 || prev==-1){
            for(int i=1;i<=min(one,limit);i++){
                oneStart = (oneStart + fn(zero,one-i,1,limit)) % N;
            }
        }

        return res = (zeroStart + oneStart) % N;
    }
    
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        return fn(zero,one,-1,limit);
    }
};