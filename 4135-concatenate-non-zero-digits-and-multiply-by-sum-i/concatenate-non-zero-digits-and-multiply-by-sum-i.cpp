class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ten=1;
        long long sum=0;
        long long nsum=0;
        while(n){
            int last=n%10;
            n/=10;
            if(last==0) continue;
            sum+=1LL*last*ten;
            nsum+=last;
            ten=1LL*ten*10;
        }
        return 1LL*sum*nsum;
    }
};