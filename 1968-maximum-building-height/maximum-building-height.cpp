class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        long long ans = 0;

        restrictions.push_back({1, 0});
        int sz = restrictions.size();

        sort(restrictions.begin(), restrictions.end());

        if (restrictions[sz - 1][0] != n) {
            restrictions.push_back({n, n - 1});
            sz++;
        }
        long long idx1 = 1;
        long long val1 = 0;
        for (int i = 1; i < sz; i++) {
            long long idx2 = restrictions[i][0];
            long long val2 = restrictions[i][1];

            val2 = min(val2, idx2 - idx1 + val1);
            restrictions[i][1] = val2;
            idx1 = idx2;
            val1 = val2;
        }
        idx1 = n;
        val1 = restrictions[sz - 1][1];
        for (int i = sz - 2; i >= 0; i--) {
            long long idx2 = restrictions[i][0];
            long long val2 = restrictions[i][1];

            val2 = min(val2, idx1 - idx2 + val1);
            restrictions[i][1] = val2;
            idx1 = idx2;
            val1 = val2;
        }
        for (int i = 1; i < sz; i++) {

            long long idx1 = restrictions[i - 1][0];
            long long val1 = restrictions[i - 1][1];

            long long idx2 = restrictions[i][0];
            long long val2 = restrictions[i][1];

            long long low = max(val1, val2);
            long long high = max(val1, val2) + (idx2 - idx1);

            while (low <= high) {

                long long mid = low + (high - low) / 2;

                if ((mid - val1) + (mid - val2) <= (idx2 - idx1)) {
                    ans = max(ans, mid);
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return ans;
    }
};