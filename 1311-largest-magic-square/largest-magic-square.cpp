class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> rowSum(m, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowSum[i][j + 1] = rowSum[i][j] + grid[i][j];
            }
        }

        vector<vector<int>> colSum(m + 1, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                colSum[i + 1][j] = colSum[i][j] + grid[i][j];
            }
        }

        int maxi = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 1; i - k >= 0 && j - k >= 0; k++) {
                    int x1 = i - k, y1 = j - k;
                    int size = k + 1;

                    int target = rowSum[x1][j + 1] - rowSum[x1][y1];
                    bool ok = true;
                    for (int r = x1; r <= i; r++) {
                        if (rowSum[r][j + 1] - rowSum[r][y1] != target) {
                            ok = false;
                            break;
                        }
                    }
                    for (int c = y1; c <= j && ok; c++) {
                        if (colSum[i + 1][c] - colSum[x1][c] != target) {
                            ok = false;
                            break;
                        }
                    }
                    int d1 = 0, d2 = 0;
                    for (int t = 0; t < size; t++) {
                        d1 += grid[x1 + t][y1 + t];
                        d2 += grid[x1 + t][j - t];
                    }

                    if (ok && d1 == target && d2 == target) {
                        maxi = max(maxi, size);
                    }
                }
            }
        }

        return maxi;
    }
};
