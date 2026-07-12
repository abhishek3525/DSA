class Solution {
public:
    double poW(double x,long long n){
        if(n==0) return 1.0;
        double no=poW(x,n/2);
        if(n&1) return no*no*x;
        return no*no;
    }
    double myPow(double x, int n) {
        if(x==1.0) return 1.0;
        double res=poW(x,abs(1LL*n));
        if(n<0) return 1/res;
        return res;
    }
};