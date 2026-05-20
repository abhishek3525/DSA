class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<A.size();i++){
            mp[A[i]]++;
            mp[B[i]]++;
            int count=0;
            for(auto [ke,val]:mp){
                if (val==2) count++;
            }
            ans.push_back(count);
            
        }
        return ans;
    }
};