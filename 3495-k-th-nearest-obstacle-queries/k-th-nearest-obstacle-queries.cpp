class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int>ans(queries.size(),-1);
        priority_queue<int>dist;
        for(int i=0;i<queries.size();i++){
            int curr=abs(queries[i][0])+abs(queries[i][1]);
            dist.push(curr);
            if(dist.size()>k){
                dist.pop();
            }
           if(dist.size()==k){
            ans[i]=dist.top();
           }
        }
            return ans;
        }
};