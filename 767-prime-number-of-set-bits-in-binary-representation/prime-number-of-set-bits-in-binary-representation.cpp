class Solution {
public:
    int N=1e6+7;
    int countPrimeSetBits(int left, int right) {
        vector<bool>isPrime(N,1);
        isPrime[0]=0,isPrime[1]=0;
        for(int i=2;i*i<N;i++){
            if(!isPrime[i]) continue;
            for(int j=i*i;j<N;j+=i){
                isPrime[j]=0;
            }
        }
        int count=0;
        for(int i=left;i<=right;i++){
            int setbits=__builtin_popcount(i);
            if(isPrime[setbits]) count++;
        }
        return count;
    }
};