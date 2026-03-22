class Solution {
public:
    vector<unordered_map<int,int>> dp;

    int fn(int i, int x, vector<int>& nums, int target) {
        if (i == nums.size()) {
            if (x == target) return 0;
            return INT_MIN;
        }

        if (dp[i].count(x)) return dp[i][x];

        int take = fn(i + 1, x ^ nums[i], nums, target);
        if (take != INT_MIN) take += 1;

        int notTake = fn(i + 1, x, nums, target);

        return dp[i][x] = max(take, notTake);
    }

    int minRemovals(vector<int>& nums, int target) {
        dp.assign(nums.size(), unordered_map<int,int>());

        int ans = fn(0, 0, nums, target);
        if (ans == INT_MIN) return -1;
        return nums.size() - ans;
    }
};