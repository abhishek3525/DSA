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
    void BSTIteratorLeft(TreeNode* root,stack<TreeNode*>&st) {
        TreeNode* temp=root;
        while(temp){
            st.push(temp);
            temp=temp->left;
        }
    }
    TreeNode* nextL(stack<TreeNode*>&st) {
        TreeNode* temp=st.top();
        TreeNode* temp1=st.top();
        st.pop();
        if(temp->right){
            st.push(temp->right);
            temp=temp->right;
            while(temp->left){
            st.push(temp->left);
            temp=temp->left;
            }
        }

        return temp1;
    }
    TreeNode* nextR(stack<TreeNode*>&st) {
        TreeNode* temp=st.top();
        TreeNode* temp1=st.top();
        st.pop();
        if(temp->left){
            st.push(temp->left);
            temp=temp->left;
            while(temp->right){
            st.push(temp->right);
            temp=temp->right;
            }
        }

        return temp1;
    }
    void BSTIteratorRight(TreeNode* root,stack<TreeNode*>&st) {
        TreeNode* temp=root;
        while(temp){
            st.push(temp);
            temp=temp->right;
        }
    }
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*>st1;
        BSTIteratorLeft(root,st1);
        stack<TreeNode*>st2;
        BSTIteratorRight(root,st2);
        while(!st1.empty() and !st2.empty()){
            TreeNode* root1 = st1.top();
            TreeNode* root2 = st2.top();
            if (root1 == root2) break;
            int data=root1->val+root2->val;
            if(data==k) return 1;
            if(data<k)nextL(st1);
            else nextR(st2);
        }
        return 0;
    }
};