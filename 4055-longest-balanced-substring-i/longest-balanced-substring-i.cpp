class Solution {
public:
    bool check(vector<int>&s)
    {
        
        int no=0;
        for(int i=0;i<26;i++){
            if(s[i] and !no) no=s[i];
            else if(s[i] and s[i]!=no) return false;
        }
        return true;
    }
    int longestBalanced(string s)
    {
        int len=0;
        int n=s.length();
        vector<int>t(26,0);
        for(int i=0; i<n; i++)
            {
                t[s[i]-'a']++;
                int j=0;
                for(;j<=i;j++)
                    {
                        
                        if(check(t)) {
                            len=max(len,i-j+1);
                            break;
                        }
                        t[s[j]-'a']--;
                    }
                while(--j>=0){
                    t[s[j]-'a']++;
                    
                }
            }
        return len;
    }
};