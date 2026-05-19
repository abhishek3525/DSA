class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<vector<int>>> rowMax(
            n, vector<vector<int>>(m)
        );

        // rowMax[i][r][l] = max(matrix[i][l..r])
        for (int i = 0; i < n; i++) {
            for (int r = 0; r < m; r++) {
                rowMax[i][r].resize(r + 1);

                rowMax[i][r][r] = matrix[i][r];

                for (int l = r - 1; l >= 0; l--) {
                    rowMax[i][r][l] =
                        max(matrix[i][l], rowMax[i][r][l + 1]);
                }
            }
        }

        int ans = 0;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {

                int x = matrix[r][c];
                if (x == 0) continue;

                int r1 = max(0, r - x);
                int r2 = min(n - 1, r + x);

                int c1 = max(0, c - x);
                int c2 = min(m - 1, c + x);

                bool ok = true;

                for (int row = r1; row <= r2 && ok; row++) {

                    int mx = rowMax[row][c2][c1];

                    if (mx <= x) continue;

                    bool foundGreater = false;

                    for (int col = c1; col <= c2; col++) {

                        if (abs(row - r) == x &&
                            abs(col - c) == x)
                            continue;

                        if (row == r && col == c)
                            continue;

                        if (matrix[row][col] > x) {
                            foundGreater = true;
                            break;
                        }
                    }

                    if (foundGreater) ok = false;
                }

                if (ok) ans++;
            }
        }

        return ans;
    }
};