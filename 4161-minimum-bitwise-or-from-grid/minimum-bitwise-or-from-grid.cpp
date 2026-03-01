class Solution {
public:
    bool fn(vector<vector<int>>& grid,int no){
        int n=grid.size();
        int m=grid[0].size();
        bool flag=1;
        for(int i=0;i<n;i++){
            bool check1=0;
            for(int j=0;j<m;j++){
                if((grid[i][j] | no)==no) check1=1;
            }
            flag=flag and check1;
        }
        return flag;
    }
    int minimumOR(vector<vector<int>>& grid) {
        int no=(1<<17)-1;
        
        for(int i=16;i>=0;i--){
            int cand = no & ~(1 << i);
            if(fn(grid,cand)){
                no=cand;
            }
        }
        return no;   
    }
};