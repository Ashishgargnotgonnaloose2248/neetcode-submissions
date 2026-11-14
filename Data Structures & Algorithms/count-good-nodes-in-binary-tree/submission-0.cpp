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
    int solve(TreeNode* root, int maxval){
        if(root == NULL){
            return 0;
        }

        int count = 0;

        if(root->val>=maxval){
            count = 1;
        }

        maxval = max(root->val, maxval);

        count += solve(root->left, maxval);
        count += solve(root->right, maxval);

        return count;
    }
    int goodNodes(TreeNode* root) {
        return solve(root, INT_MIN);
    }
};
