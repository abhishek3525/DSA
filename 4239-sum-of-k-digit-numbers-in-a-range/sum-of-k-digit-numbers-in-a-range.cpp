class Solution {
public:
    long long N=1e9+7;
    long long power(long long base,long long exp) {
        long long result=1;
        base%=N;
        while(exp>0) {
            if(exp&1)result=(result*base)%N;
            base=(base*base)%N;
            exp>>=1;
        }
        return result;
    }

    int sumOfNumbers(int l, int r, long long k) {
        long long no=r-l+1;
        long long sum1=0;
        for(int i=l;i<=r;i++)sum1+=i;
        sum1%=N;
        long long no1=(sum1*power(no,k-1))%N;
        long long tenPow=(power(10,k)-1+N)%N;
        long long inv9 =power(9, N - 2);
        tenPow=(tenPow*inv9)%N;
        long long res=(no1*tenPow)%N;
        return res;
    }
};