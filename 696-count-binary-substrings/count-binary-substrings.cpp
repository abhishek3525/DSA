class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.length();
        int ans=0;
        int i=0;
        int prev=0;
        while(i<n){
            int j=i;
            while(j<n and s[j]=='0')j++;
            int k=i;
            while(k<n and s[k]=='1')k++;
            if(!prev){
                prev=max(j-i,k-i);
                i=max(j,k);
                continue;
            }
            if(j-i) {
                ans+=min(prev,j-i);
                prev=j-i;
                i=j;
            }
            else{
                ans+=min(prev,k-i);
                prev=k-i;
                i=k;
            }

        }
        return ans;
    }
};