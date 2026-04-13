class Solution {
public:
    int dp[301][27][27];

    int fn(int idx, int p1, int p2, string &s) {
        if (idx == s.size()) return 0;

        if (dp[idx][p1][p2] != -1) return dp[idx][p1][p2];

        int pos = s[idx] - 'A';
        int x = pos / 6;
        int y = pos % 6;

        int one = INT_MAX, two = INT_MAX;

        // case 1: use finger 1
        if (p1 == 26) {
            one = fn(idx + 1, pos, p2, s);
        } else {
            int x1 = p1 / 6, y1 = p1 % 6;
            one = abs(x - x1) + abs(y - y1) + fn(idx + 1, pos, p2, s);
        }

        // case 2: use finger 2
        if (p2 == 26) {
            two = fn(idx + 1, p1, pos, s);
        } else {
            int x2 = p2 / 6, y2 = p2 % 6;
            two = abs(x - x2) + abs(y - y2) + fn(idx + 1, p1, pos, s);
        }

        return dp[idx][p1][p2] = min(one, two);
    }

    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return fn(0, 26, 26, word);
    }
};