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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,int>mp1;
        unordered_map<int,pair<int,int>>mp2;
        for(int i=0;i<descriptions.size();i++){
            int u=descriptions[i][0];
            int v=descriptions[i][1];
            int isLeft=descriptions[i][2];
            mp1[v]++;
            if(mp2.find(u)!=mp2.end()){
                if(isLeft) mp2[u].first=v;
                else mp2[u].second=v;
            }
            else{
                if(isLeft) mp2[u]={v,-1};
                else mp2[u]={-1,v};
            }
        }
        int rootVal=-1;
        for(auto ele:mp2){
            if(mp1.find(ele.first)==mp1.end()) {
                rootVal=ele.first;
                break;
            }
        }
        TreeNode * root=new TreeNode(rootVal);
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode * curr= q.front();
            q.pop();
            int currVal = curr->val;
            if (mp2.find(currVal) != mp2.end()) {
                int leftVal = mp2[currVal].first;
                int rightVal = mp2[currVal].second;
                if (leftVal != -1) {
                    curr->left = new TreeNode(leftVal);
                    q.push(curr->left);
                }
                if (rightVal != -1) {
                    curr->right = new TreeNode(rightVal);
                    q.push(curr->right);
                }
            }
        }
        return root;
    }
};