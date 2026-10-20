
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

class Codec {
public:

    // Serialize: Tree -> String
    string serialize(TreeNode* root) {
        if (root == nullptr) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr) {
                s += "N ";
                continue;
            }

            s += to_string(node->val) + " ";

            q.push(node->left);
            q.push(node->right);
        }

        return s;
    }

    // Deserialize: String -> Tree
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        string str;

        ss >> str;
        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Left child
            if (!(ss >> str)) break;

            if (str != "N") {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }

            // Right child
            if (!(ss >> str)) break;

            if (str != "N") {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }

        return root;
    }
};
