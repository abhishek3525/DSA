class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> ancestorTable;
    int rows;
    int cols;
    vector<int> parent;
    vector<int> depth;
    
    void dfs(int node, int par, vector<vector<int>>& adj, int depthValue) {
        parent[node] = par;
        depth[node] = depthValue;

        for (int child : adj[node]) {
            if (child == par) continue;
            dfs(child, node, adj, depthValue + 1);
        }
    }
    
    int LCA(int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        int diff = depth[u] - depth[v];

        for (int bit = 0; diff > 0; bit++) {
            if (diff & 1) {
                u = ancestorTable[u][bit]; 
            }
            diff >>= 1;
        }

        if (u == v) return u;

        for (int jump = cols - 1; jump >= 0; jump--) {
           
            if (ancestorTable[u][jump] != ancestorTable[v][jump]) {
                u = ancestorTable[u][jump];
                v = ancestorTable[v][jump];
            }
        }

        return ancestorTable[u][0]; 
    }

    int getPathLength(int u, int v) {
        int lca = LCA(u, v);
        return depth[u] + depth[v] - 2 * depth[lca];
    }
    
    long long power(long long base, long long exp) {
        if (exp <= 0) return 1;

        long long half = power(base, exp / 2);
        long long res = (half * half) % MOD;

        if (exp & 1)
            res = (res * base) % MOD;

        return res;
    }
    
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        int q = queries.size();
        vector<vector<int>> adj(n + 1);
        
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        parent.assign(n + 1, 0);
        depth.assign(n + 1, 0);
        dfs(1, 1, adj, 0); 
        
        rows = n + 1;
        cols = log2(n + 1) + 1;
        ancestorTable.assign(rows, vector<int>(cols, -1));
        
        for(int node = 1; node <= n; node++) { 
            ancestorTable[node][0] = parent[node];
        }
        
        for(int j = 1; j < cols; j++) { 
            for(int node = 1; node <= n; node++) {
                if(ancestorTable[node][j-1] != -1) {
                    ancestorTable[node][j] = ancestorTable[ ancestorTable[node][j-1] ][j-1];
                }
            }
        }
        
        vector<int> ans; 
        for(int i = 0; i < q; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int pathLen = getPathLength(l, r);
            int res = 0;
            if (pathLen > 0) {
                res = power(2LL, pathLen - 1);
            }
            
            ans.push_back(res);
        }
        
        return ans;
    }
};