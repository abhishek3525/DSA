class Solution {
public:
    int binaryGap(int n) {
      int zero=0;
      int one=0;
      int res=0;
      while(n){
        if(n&1) {
            one++;
            if(one>1){
                res=max(res,zero+1);
            }
            zero=0;
        }
        else zero++;
        n=n>>1;
      }  
      return res;
    }
};