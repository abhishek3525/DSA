class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length() < k) return false;
        set<int>st;
        int no=0;
        for(int i=0;i<k;i++){
            int bit=s[k-i-1]-'0';
           if(bit) no=no+(1<<i);
        }
        for(int i=k;i<s.length();i++){
            st.insert(no);
            no=no&(~(1<<(k-1)));
            no=no<<1;
            no=no+(s[i]-'0');
        }
        st.insert(no);
        return st.size() == (1 << k);
    }
};