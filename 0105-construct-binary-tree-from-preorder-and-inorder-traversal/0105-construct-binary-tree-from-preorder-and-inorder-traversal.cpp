
class Solution {
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    int preStart, int preEnd,
                    int inStart, int inEnd,
                    unordered_map<int, int>& mpp) {

        if (preStart > preEnd || inStart > inEnd) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = mpp[root->val];
        int numsLeft = inRoot - inStart;

        root->left = build(preorder, inorder,
                           preStart + 1, preStart + numsLeft,
                           inStart, inRoot - 1, mpp);

        root->right = build(preorder, inorder,
                            preStart + numsLeft + 1, preEnd,
                            inRoot + 1, inEnd, mpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mpp;

        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, preorder.size() - 1,
                     0, inorder.size() - 1, mpp);
    }
};
