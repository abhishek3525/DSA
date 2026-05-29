/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "";

        string ans = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (current == nullptr) {
                ans += "__,";
                continue;
            }

            ans += to_string(current->val) + ",";

            q.push(current->left);
            q.push(current->right);
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return NULL;

        stringstream ss(data);
        vector<string> word;
        string temp;

        while (getline(ss, temp, ',')) {
            if (temp.size() == 0) continue;
            word.push_back(temp);
        }

        TreeNode* root = new TreeNode(stoi(word[0]));

        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while (!q.empty() && i < word.size()) {
            TreeNode* current = q.front();
            q.pop();

            // left child
            if (word[i] != "__") {
                current->left = new TreeNode(stoi(word[i]));
                q.push(current->left);
            }
            i++;

            // right child
            if (i < word.size() && word[i] != "__") {
                current->right = new TreeNode(stoi(word[i]));
                q.push(current->right);
            }
            i++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));