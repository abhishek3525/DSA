class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        vector<int>v(3,0);
        int ans=0;
        int i=0;
        int j=0;
        while(j<n){
            if(!v[0] or !v[2] or !v[1]){
                v[s[j]-'a']++;
                j++;
            }
            while(abs(i-j)>2 and v[0] and v[1] and v[2]){
                ans+=(n-j+1);
                v[s[i]-'a']--;
                i++;
            }
        }
        return ans;
    }
};