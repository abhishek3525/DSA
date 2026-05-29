class Solution {
public:
void dfs(int node ,vector<bool>&visited,vector<vector<int>>&adj){
    visited[node]=1;
    for(int j=0;j<adj[node].size();j++){
        if(!visited[adj[node][j]]) dfs(adj[node][j],visited,adj);
    }
    return;
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool>visited(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i,visited,adj);
            }
        }
        return count;
    }
};