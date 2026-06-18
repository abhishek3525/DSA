class Solution {
public:
    int getSum(int a, int b) {
      int sum=0;
      unsigned int no=1;
      bool carry=0;
      for(int i=0;i<32;i++){
        if(carry){
            if(a&1 and b&1){
                sum=sum|no;
            }
            else if(!(a&1) and !(b&1)){
                sum=sum|no;
                carry=0;
            }
        }
        else{
            if(a&1 and b&1){
                carry=1;
            }
            else if(a&1 or b&1){
                sum=sum|no;
            }
            
        }
        if(i<31)no=no<<1;
        a=a>>1;
        b=b>>1;
      }
      return sum;
    }
};