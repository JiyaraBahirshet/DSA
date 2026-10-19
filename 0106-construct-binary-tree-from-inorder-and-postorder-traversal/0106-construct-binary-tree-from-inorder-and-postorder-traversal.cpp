
class Solution {
public:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int inStart, int inEnd,
                    int postStart, int postEnd,
                    unordered_map<int, int>& mpp) {

        if (inStart > inEnd || postStart > postEnd) {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = mpp[root->val];
        int numsRight = inEnd - inRoot;

        root->right = build(inorder, postorder,
                            inRoot + 1, inEnd,
                            postEnd - numsRight, postEnd - 1,
                            mpp);

        root->left = build(inorder, postorder,
                           inStart, inRoot - 1,
                           postStart, postEnd - numsRight - 1,
                           mpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mpp;

        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }

        int n = inorder.size();

        return build(inorder, postorder,
                     0, n - 1, 0, n - 1, mpp);
    }
};
