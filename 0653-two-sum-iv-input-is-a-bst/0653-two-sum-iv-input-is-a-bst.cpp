
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> s1, s2;

        pushLeft(root, s1);
        pushRight(root, s2);

        TreeNode* leftNode = nextSmallest(s1);
        TreeNode* rightNode = nextLargest(s2);

        while (leftNode != rightNode) {
            int sum = leftNode->val + rightNode->val;

            if (sum == k) {
                return true;
            }
            else if (sum < k) {
                leftNode = nextSmallest(s1);
            }
            else {
                rightNode = nextLargest(s2);
            }
        }

        return false;
    }

private:
    void pushLeft(TreeNode* node, stack<TreeNode*>& st) {
        while (node != NULL) {
            st.push(node);
            node = node->left;
        }
    }

    void pushRight(TreeNode* node, stack<TreeNode*>& st) {
        while (node != NULL) {
            st.push(node);
            node = node->right;
        }
    }

    TreeNode* nextSmallest(stack<TreeNode*>& st) {
        if (st.empty()) return NULL;

        TreeNode* node = st.top();
        st.pop();

        pushLeft(node->right, st);
        return node;
    }

    TreeNode* nextLargest(stack<TreeNode*>& st) {
        if (st.empty()) return NULL;

        TreeNode* node = st.top();
        st.pop();

        pushRight(node->left, st);
        return node;
    }
};
