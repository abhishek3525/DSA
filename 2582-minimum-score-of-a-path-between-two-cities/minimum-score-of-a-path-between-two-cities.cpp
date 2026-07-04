class Solution {
public:
    void dfs(int u, vector<pair<int,int>>adj[], vector<bool>& vis, int &mn) {
        vis[u] = true;
        for (auto &it : adj[u]) {
            int v = it.first;
            int wt = it.second;

            mn = min(mn, wt);

            if (!vis[v]) {
                dfs(v, adj, vis, mn);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<bool> vis(n + 1, false);
        int mn = INT_MAX;

        dfs(1, adj, vis, mn); 

        return mn;
    }
};