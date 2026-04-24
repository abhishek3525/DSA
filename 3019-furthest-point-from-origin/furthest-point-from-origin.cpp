class Solution {
public:
    int furthestDistanceFromOrigin(string s) {
        int n=s.size();
        int countl=0;
        int countr=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='L') countl++;
            else if(s[i]=='R') countr++;
            else count++;
        }
        return max(countl,countr)+count-min(countl,countr);
    }
};