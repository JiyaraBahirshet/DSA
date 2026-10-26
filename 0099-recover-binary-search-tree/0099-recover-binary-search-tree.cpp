
class Solution {
private:
    TreeNode* first;
    TreeNode* last;
    TreeNode* prev;
    TreeNode* middle;

    void inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        inorder(root->left);

        if (prev != NULL && root->val < prev->val) {
            if (first == NULL) {
                first = prev;
                middle = root;
            }
            else {
                last = root;
            }
        }

        prev = root;

        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = middle = last = prev = NULL;

        inorder(root);

        if (first != NULL && last != NULL) {
            swap(first->val, last->val);
        }
        else if (first != NULL && middle != NULL) {
            swap(first->val, middle->val);
        }
    }
};
