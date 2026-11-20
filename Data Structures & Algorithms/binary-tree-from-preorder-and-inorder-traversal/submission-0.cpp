class Solution {
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    int& index, int start, int end) {

        if (start > end) {
            return NULL;
        }

        int rootval = preorder[index];
        index++;

        TreeNode* root = new TreeNode(rootval);

        int position = start;

        while (inorder[position] != rootval) {
            position++;
        }

        root->left = build(preorder, inorder, index, start, position - 1);
        root->right = build(preorder, inorder, index, position + 1, end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;

        return build(preorder, inorder, index, 0, inorder.size() - 1);
    }
};