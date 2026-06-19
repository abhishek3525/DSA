class Solution {
public:
    int trailingZeroes(int n) {
        int count=0;
        int no=5;
        while(no<=n){
            int temp=no;
            while(temp%5==0){
                count++;
                temp/=5;
            }
            no+=5;
        }
        return count;
    }
};