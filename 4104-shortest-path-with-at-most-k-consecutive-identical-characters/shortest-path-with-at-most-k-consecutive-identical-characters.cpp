class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }
        const long long INF = 1e18;
        vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));
        dist[0][1] = 0;
        priority_queue<tuple<long long, int, int, char>,
                       vector<tuple<long long, int, int, char>>,
                       greater<tuple<long long, int, int, char>>>
            pq;

        pq.push({0, 0, 1, labels[0]});
        while (!pq.empty()) {
            auto [wt, node, count, ch] = pq.top();
            pq.pop();
            if (node == n - 1)
                return (int)wt;
            if (wt > dist[node][count])
                continue;
            for (auto [v, w] : adj[node]) {
                
                int count1=count;
                char ch1=ch;
                if (labels[v] == ch1) 
                    count1++;
                else {
                    ch1 = labels[v];
                       count1 = 1;
                }
                if (count1 <= k && wt + w < dist[v][count1]) {
                    dist[v][count1] = wt + w;
                    pq.push({dist[v][count1], v, count1, ch1});
                }
                
            }
        }
        return -1;
    }
};