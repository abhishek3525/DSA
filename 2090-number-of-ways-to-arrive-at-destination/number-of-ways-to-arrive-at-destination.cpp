class Solution {
public:
    // revise it one more time
    int N = 1e9+7;

    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,long long>>> adj(n);
        for(auto &r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while(!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if(d > dist[node]) continue;

            for(auto &ele : adj[node]) {
                long long nd = d + ele.second;

                if(nd < dist[ele.first]) {
                    dist[ele.first] = nd;
                    ways[ele.first] = ways[node];
                    pq.push({nd, ele.first});
                }
                else if(nd == dist[ele.first]) {
                    ways[ele.first] = (ways[ele.first] + ways[node]) % N;
                }
            }
        }

        return ways[n-1] % N;
    }
};
