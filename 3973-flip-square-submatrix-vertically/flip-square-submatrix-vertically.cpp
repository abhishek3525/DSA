class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int up=x;
        int down=x+k-1;
        while(up<down){
            for(int i=y;i<y+k;i++){
                swap(grid[up][i],grid[down][i]);
            }
            up++;
            down--;
        }
        return grid;
    }
};