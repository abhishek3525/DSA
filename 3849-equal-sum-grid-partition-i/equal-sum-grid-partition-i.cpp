class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<long long> rowPrefix(n, 0);
        for (int i = 0; i < n; i++) {
            long long sum = 0;
            for (int j = 0; j < m; j++) {
                sum += grid[i][j];
            }
            rowPrefix[i] = sum + (i ? rowPrefix[i-1] : 0);
        }

        long long total = rowPrefix[n-1];
        for (int i = 0; i < n; i++) {
            if (2 * rowPrefix[i] == total) return true;
        }

        vector<long long> colPrefix(m, 0);
        for (int j = 0; j < m; j++) {
            long long sum = 0;
            for (int i = 0; i < n; i++) {
                sum += grid[i][j];
            }
            colPrefix[j] = sum + (j ? colPrefix[j-1] : 0);
        }

        for (int j = 0; j < m; j++) {
            if (2 * colPrefix[j] == total) return true;
        }

        return false;
    }
};