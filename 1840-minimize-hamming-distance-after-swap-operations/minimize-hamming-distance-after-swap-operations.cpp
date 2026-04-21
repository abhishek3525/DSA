class Solution {
public:
    vector<int>rank,parent;
    int findUPar(int node){
        if(parent[node]==node) return node;
        return parent[node]=findUPar(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if (rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        for(int i=0;i<allowedSwaps.size();i++){
            unionByRank(allowedSwaps[i][0],allowedSwaps[i][1]);
        }
        unordered_map<int,vector<int>>mp1;
        for(int i=0;i<n;i++){
            int ulp_u=findUPar(i);
            mp1[ulp_u].push_back(i);
        }
        int count=0;
        for(auto [key,val]:mp1){
            map<int,int>mp;
            for(int i=0;i<val.size();i++){
                
                mp[source[val[i]]]++;
            }
            for(int i=0;i<val.size();i++){
                if(mp.find(target[val[i]])!=mp.end() and mp[target[val[i]]]>0) mp[target[val[i]]]--;
                else count++;
            }
            
        }
        return count;
    }
};