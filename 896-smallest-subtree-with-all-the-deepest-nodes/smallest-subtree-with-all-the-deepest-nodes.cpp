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
    int n;
    int depthfn(TreeNode *root){
        if(!root) return 0;
        int left=depthfn(root->left);
        int right=depthfn(root->right);
        return 1+max(left,right);
    }
    TreeNode* fn(TreeNode* root,int height){
        if(height==n) return root;
        if(!root) return NULL;
        TreeNode* left=fn(root->left,height+1);
        TreeNode* right=fn(root->right,height+1);
        if(left and right) return root;
        else if(!left) return right;
        else if(!right) return left;
        else return NULL;
    }
public:
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
         n=depthfn(root);
        return fn(root,1);
    }
};