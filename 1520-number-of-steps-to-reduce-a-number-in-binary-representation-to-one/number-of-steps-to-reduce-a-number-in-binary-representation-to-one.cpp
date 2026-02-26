class Solution {
public:
    int numSteps(string s) {
        int n=s.length();
        int count=0;
        int sum=0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='1') sum++;
        }
        while(sum!=0){
            count++;
            if(s[s.length()-1]=='0'){
                s.pop_back();
                if(s[s.length()-1]=='1') sum--;
            }
            else{
                int j=s.length()-1;
                while(j>=0 and s[j]=='1') {
                    sum--;
                    s[j]='0';
                    j--;
                }
                if(j<0){
                    s.push_back('0');
                    s[0]='1';
                    sum=1;
                }
                else{
                    s[j]='1';
                    sum+=2;
                }
            }
        }
        
        return count;
    }
};