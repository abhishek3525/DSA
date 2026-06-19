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
class BSTIterator {
public:
    
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        TreeNode* temp=root;
        while(temp){
            st.push(temp);
            temp=temp->left;
        }
    }
    
    int next() {
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

        return temp1->val;
    }
    
    bool hasNext() {
        return !(st.empty());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */