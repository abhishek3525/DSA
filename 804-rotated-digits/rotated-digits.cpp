class Solution {
public:
    int rotatedDigits(int n) {
        int count=0;
        for(int j=1;j<=n;j++){
            string s=to_string(j);
            bool flag1=0;
            bool flag2=0;
            for(int i=0;i<s.length();i++){
                if(s[i]=='3' or s[i]=='4' or s[i]=='7'){
                    flag1=1;
                    break;
                }
                if(s[i]=='2' or s[i]=='5' or s[i]=='6' or s[i]=='9'){
                    flag2=1;
                    
                }
            }
            if(!flag1 and flag2) count++;
        }
        return count;
    }
}; 