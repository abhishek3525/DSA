class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>pre(n,1);
        int no=1;
        for(int i=1;i<n;i++){
           
            if((nums[i]-nums[i-1])<=maxDiff) pre[i]=pre[i-1];
            else pre[i]=++no;
        }
        vector<bool>ans;
        for(int k=0;k<queries.size();k++){
            int i=queries[k][0];
            int j=queries[k][1];
            if(pre[i]==pre[j]) ans.push_back(1);
            else ans.push_back(0);
        }
        return ans;
    }
};