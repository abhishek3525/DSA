class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        // Step 1: Create the difference array
        vector<int> D(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            D[i] = nums[i + 1] - nums[i];
        }

        int m = D.size();
        // L[i] stores the length of identical differences ending at i
        // R[i] stores the length of identical differences starting at i
        vector<int> L(m, 1), R(m, 1);
        
        for (int i = 1; i < m; ++i) {
            if (D[i] == D[i - 1]) L[i] = L[i - 1] + 1;
        }
        for (int i = m - 2; i >= 0; --i) {
            if (D[i] == D[i + 1]) R[i] = R[i + 1] + 1;
        }

        int max_len = 0;

        // Base Case: We can always extend a continuous segment by modifying 1 adjacent element
        for (int i = 0; i < m; ++i) {
            int current_len = L[i];
            if (current_len < m) {
                current_len++; // Extend by 1
            }
            max_len = max(max_len, current_len);
        }

        // Gap Case: Modifying nums[i] changes D[i-1] and D[i]
        // We look at every adjacent pair in D (a "gap") and see if it can bridge sequences
        for (int j = 0; j < m - 1; ++j) {
            // Use long long to prevent overflow when adding two differences
            long long sum = (long long)D[j] + D[j + 1]; 
            
            // 1. Merge the gap with the left segment only
            if (j > 0 && sum == 2LL * D[j - 1]) {
                max_len = max(max_len, L[j - 1] + 2);
            }
            
            // 2. Merge the gap with the right segment only
            if (j + 2 < m && sum == 2LL * D[j + 2]) {
                max_len = max(max_len, R[j + 2] + 2);
            }
            
            // 3. Merge both the left AND right segments together across the gap
            if (j > 0 && j + 2 < m && D[j - 1] == D[j + 2] && sum == 2LL * D[j - 1]) {
                max_len = max(max_len, L[j - 1] + 2 + R[j + 2]);
            }
        }

        // The max length in nums is the max length of differences + 1
        return max_len + 1;
    }
};