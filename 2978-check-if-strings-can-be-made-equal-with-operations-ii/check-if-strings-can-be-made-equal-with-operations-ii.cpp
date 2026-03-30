class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n1=s1.length();
        int n2=s2.length();
        int j=2;
        for(int i=1;i<n1;i++){
            if(j>=n1)break;
            swap(s1[i],s1[j]);
            j+=2;
        }
        j=2;
        for(int i=1;i<n2;i++){
            if(j>=n2)break;
            swap(s2[i],s2[j]);
            j+=2;
        }
        int k1=(n1+1)/2;
        int k2=(n2+1)/2;
        sort(s1.begin(),s1.begin()+k1);
        sort(s1.begin()+k1,s1.end());
        sort(s2.begin(),s2.begin()+k2);
        sort(s2.begin()+k2,s2.end());
        return s1==s2;
    }
};