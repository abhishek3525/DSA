class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n, vector<int>(n, 1e9));

        for(int i = 0; i < n; i++)
            adj[i][i] = 0;

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u][v] = min(adj[u][v], wt);
            adj[v][u] = min(adj[v][u], wt);
        }

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(adj[i][k] != 1e9 && adj[k][j] != 1e9)
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }

        int city = -1;
        int minCnt = 1e9;

        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(i != j && adj[i][j] <= distanceThreshold)
                    cnt++;
            }
            if(cnt <= minCnt){
                minCnt = cnt;
                city = i;
            }
        }

        return city;
    }
};
