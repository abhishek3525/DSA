class Solution {
public:
    int reverseBits(int n) {
        string ans="";
        for(int i=0;i<32;i++){
            if(n&(1<<i)) ans.push_back('1');
            else ans.push_back('0');
        }
        reverse(ans.begin(),ans.end());
        int result=0;
        for(int i=0;i<ans.length();i++){
            if(ans[i]=='1'){
                result+=(1<<i);
            }
        }
        return result;

    }
};