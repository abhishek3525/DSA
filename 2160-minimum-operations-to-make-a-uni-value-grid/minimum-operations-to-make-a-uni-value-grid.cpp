class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int k) {
        vector<int> v;
        
        int n = grid.size();
        int m = grid[0].size();
        
        // Flatten
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                v.push_back(grid[i][j]);
            }
        }
        
        // Check feasibility
        int rem = v[0] % k;
        for(int x : v){
            if(x % k != rem) return -1;
        }
        
        // Sort
        sort(v.begin(), v.end());
        
        // Take median
        int median = v[v.size() / 2];
        
        // Count operations
        int ops = 0;
        for(int x : v){
            ops += abs(x - median) / k;
        }
        
        return ops;
    }
};