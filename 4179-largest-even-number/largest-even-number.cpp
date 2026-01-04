class Solution {
public:
    string largestEven(string s) {
        int n=s.length();
        while(n>0 and (s[n-1]-'0')&1){
            s.pop_back();
            n--;
        }
        return s;
    }
};