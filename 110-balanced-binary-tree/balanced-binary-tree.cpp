/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int fn(TreeNode* root,bool &check){
    if(!root) return 0;
    int left=fn(root->left,check);
    int right=fn(root->right,check);;
    if(abs(left-right)>1) check=1;
    return 1+max(left,right);
}
    bool isBalanced(TreeNode* root) {
        bool check=0;
        int res=fn(root,check);
        return !check;

    }
};