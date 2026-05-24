class Solution {
public:
    int fn(int i, vector<int>& arr, int d, vector<int>& memo) {
        if (memo[i] != -1) return memo[i];
        
        int step = 1;
        
        for (int j = 1; j <= d && (i + j) < arr.size(); j++) {
            if (arr[i + j] >= arr[i]) break; 
            step = max(step, 1 + fn(i + j, arr, d, memo));
        }
        
        for (int j = 1; j <= d && (i - j) >= 0; j++) {
            if (arr[i - j] >= arr[i]) break; 
            step = max(step, 1 + fn(i - j, arr, d, memo));
        }
        
        return memo[i] = step;
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> memo(n, -1);
        int max_jumps = 0;
        
        for(int i = 0; i < n; i++) {
            max_jumps = max(max_jumps, fn(i, arr, d, memo));
        }
        return max_jumps;
    }
};