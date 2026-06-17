class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int ans = INT_MIN;
        int sum = 0;
        while (j < n) {
            sum += nums[j];
            ans = max(ans, sum);

            while (i <= j && sum < 0) {
                sum -= nums[i];
                i++;
            }

            if (i > j) {
                j = i;
                continue;
            }

            ans = max(ans, sum);
            j++;
        }
        vector<int> pre(n);
        vector<int> post(n);
        sum = 0;
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            maxi = max(maxi, sum);  
            pre[i] = maxi;
        }
        sum = 0;
        maxi = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            sum += nums[i];
            maxi = max(maxi, sum);   
            post[i] = maxi;
        }
        for (int i = n - 1; i > 0; i--) {
            ans = max(ans, post[i] + pre[i - 1]);
        }
        return ans;
    }
};