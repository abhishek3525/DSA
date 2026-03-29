class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        swap(s1[1],s1[2]);
        swap(s2[1],s2[2]);
        sort(s1.begin(),s1.begin()+2);
        sort(s1.begin()+2,s1.end());
        sort(s2.begin(),s2.begin()+2);
        sort(s2.begin()+2,s2.end());
        return s1==s2;
    }
};