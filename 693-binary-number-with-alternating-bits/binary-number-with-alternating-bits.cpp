class Solution {
public:
    bool hasAlternatingBits(int n) {
        int no=n&1;
        while(n){
            n>>=1;
            if(no==(n&1)) return 0;
            no=n&1;
        }
        return 1;
    }
};