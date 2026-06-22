class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>v(26,0);
        for(int i=0;i<text.size();i++){
            v[text[i]-'a']++;
        }
        int ans=INT_MAX;
        ans=min(ans,v[0]);
        ans=min(ans,v[1]);
        ans=min(ans,v['n'-'a']);
        int temp1=v['l'-'a'];
        temp1=min(temp1,v['o'-'a']);;
        temp1/=2;
        ans=min(ans,temp1);
        return ans;
    }
};