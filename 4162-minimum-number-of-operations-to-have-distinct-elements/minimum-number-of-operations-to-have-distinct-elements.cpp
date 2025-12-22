class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int x : nums) {
            mp[x]++;
        }

        int idx = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(nums[i]) && mp[nums[i]] >= 2) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                idx = i;
            }
        }

        if (idx == -1) return 0;

        int cnt = idx + 1;
        return (cnt + 2) / 3;  
    }
};