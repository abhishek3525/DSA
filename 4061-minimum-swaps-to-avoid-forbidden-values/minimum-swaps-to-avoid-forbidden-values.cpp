class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        int n = nums.size();
        unordered_map<int, int> nums_counts;
        unordered_map<int, int> forbidden_counts;
        unordered_map<int, int> bad_counts;
        int total_bad = 0;
        for (int i = 0; i < n; i++) {
            nums_counts[nums[i]]++;
            forbidden_counts[forbidden[i]]++;
            
            if (nums[i] == forbidden[i]) {
                bad_counts[nums[i]]++;
                total_bad++;
            }
        }
        for (auto& [val, count] : nums_counts) {
            int allowed_slots = n - forbidden_counts[val];
            if (count > allowed_slots) {
                return -1;
            }
        }
        int max_bad_freq = 0;
        for (auto& [val, count] : bad_counts) {
            max_bad_freq = max(max_bad_freq, count);
        }
        return max(max_bad_freq, (total_bad + 1) / 2);
    }
};