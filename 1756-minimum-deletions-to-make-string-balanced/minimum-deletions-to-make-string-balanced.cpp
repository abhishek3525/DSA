class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.length();
        vector<int>v1;
        v1.push_back(0);
        int count1=0;
        for(int i=0;i<n;i++){
            if(s[i]=='b') count1++;
            v1.push_back(count1);
        }
        int count2=0;
        vector<int>v2;

        for(int i=n-1;i>=0;i--){
            if(s[i]=='a') count2++;
            v2.push_back(count2);
        }
        reverse(v2.begin(),v2.end());
        v2.push_back(0);
        int ans=INT_MAX;
        for(int i=0;i<=n;i++){
            ans=min(ans,v1[i]+v2[i]);
        }
        return ans==INT_MAX?0:ans;
    }
};