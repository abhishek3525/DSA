class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u].push_back({v,w});
        }
        vector<int>dist(n+1,1e9);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty()){
            int node=pq.top().second;
            int wt=pq.top().first;
            pq.pop();
            for( auto ele:adj[node]){
                if(dist[ele.first]>wt+ele.second){
                    dist[ele.first]=wt+ele.second;
                    pq.push({wt+ele.second,ele.first});
                }
            }
        }
        int minDist=INT_MIN;
        for(int i=1;i<=n;i++){
            
            if(dist[i]==1e9) return -1;
            minDist=max(minDist,dist[i]);
        }
        return minDist;
    }
};