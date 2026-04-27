class Solution {
public:
    vector<int>fn(int i,int j,int val){
        if(val==1){
            return {i,j-1,i,j+1};
        }
        if(val==2){
            return {i-1,j,i+1,j};
        }
        if(val==3){
            return {i,j-1,i+1,j};
        }
        if(val==4){
            return {i,j+1,i+1,j};
        }
        if(val==5){
            return {i,j-1,i-1,j};
        }
        if(val==6){
            return {i,j+1,i-1,j};
        }
        return {};
    }
    bool isValid(int i,int j,int n,int m){
        return i>=0 and i<n and j>=0 and j<m;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        queue<pair<int,int>>q;
        q.push({0,0});
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                if(i==n-1 and j==m-1) return 1;
                if(vis[i][j]) continue;
                vis[i][j]=1;
                int val=grid[i][j];
                vector<int>dir=fn(i,j,val);
                int i1=dir[0];
                int j1=dir[1];
                int i2=dir[2];
                int j2=dir[3];
                if(isValid(i1,j1,n,m) and !vis[i1][j1]){
                    vector<int>dir1=fn(i1,j1,grid[i1][j1]);
                    if((dir1[0]==i and dir1[1]==j) or (dir1[2]==i and dir1[3]==j)) q.push({i1,j1});
                } 
                if(isValid(i2,j2,n,m) and !vis[i2][j2]) {
                     vector<int>dir1=fn(i2,j2,grid[i2][j2]);
                    if((dir1[0]==i and dir1[1]==j) or (dir1[2]==i and dir1[3]==j)) q.push({i2,j2});
                }
            }
        }
        return false;
    }
};