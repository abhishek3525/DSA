class Solution {
public:
    int N = 1e9 + 7;
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<pair<long long, long long>>> dp(n, vector<pair<long long, long long>>(m, {0, 0}));

        dp[0][0].first = 1LL*grid[0][0];
        dp[0][0].second = 1LL*grid[0][0];
        for (int j = 1; j < m; j++) {
            dp[0][j].first = 1LL*grid[0][j] * dp[0][j - 1].first;
            dp[0][j].second = 1LL*grid[0][j] * dp[0][j - 1].second;
        }
        for (int i = 1; i < n; i++) {
            dp[i][0].first = 1LL*grid[i][0] * dp[i - 1][0].first;
            dp[i][0].second = 1LL*grid[i][0] * dp[i - 1][0].second;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                vector<long long> v;
                v.push_back(1LL*grid[i][j] * dp[i - 1][j].first);
                v.push_back(1LL*grid[i][j] * dp[i - 1][j].second);
                v.push_back(1LL*grid[i][j] * dp[i][j - 1].first);
                v.push_back(1LL*grid[i][j] * dp[i][j - 1].second);
                sort(v.begin(), v.end());
                dp[i][j].first = v[0];
                dp[i][j].second = v[3];
            }
        }
        long long no = (dp[n - 1][m - 1].second);
        if (no < 0)
            return -1;
        return no%N;
    }
};