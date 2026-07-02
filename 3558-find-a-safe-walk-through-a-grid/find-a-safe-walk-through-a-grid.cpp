class Solution {
public:
    int row[4]={0,-1,0,1};
    int col[4]={-1,0,1,0};
    bool isValid(int r,int c,int n,int m){
        return r>=0 and r<n and c>=0 and c<m;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        priority_queue<tuple<int,int,int>>pq;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,0));
        pq.push({(health-grid[0][0]),0,0});
        while(!pq.empty()){
            auto [wt,i,j]=pq.top();
            pq.pop();
            
            if(i==n-1 and j==m-1 and wt>0) return 1;
            if(visited[i][j]) continue;
            visited[i][j]=1;
            for(int k=0;k<4;k++){
                int r1=i+row[k];
                int c1=j+col[k];
                if(isValid(r1,c1,n,m) and !visited[r1][c1]){
                    pq.push({(wt-grid[r1][c1]),r1,c1});
                }
            }
            
        }
        return 0;
    }
};