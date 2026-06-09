class Solution {
public:
    struct NodeInfo {
        bool isBST;
        int mini;
        int maxi;
        int sum;
    };

    NodeInfo dfs(TreeNode* root, int &ans) {
        if (!root) {
            return {true, INT_MAX, INT_MIN, 0};
        }

        auto left = dfs(root->left, ans);
        auto right = dfs(root->right, ans);

        if (left.isBST && right.isBST &&
            root->val > left.maxi &&
            root->val < right.mini) {

            int currSum = left.sum + right.sum + root->val;

            ans = max(ans, currSum);

            return {
                true,
                min(root->val, left.mini),
                max(root->val, right.maxi),
                currSum
            };
        }

        return {false, INT_MIN, INT_MAX, 0};
    }

    int maxSumBST(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};