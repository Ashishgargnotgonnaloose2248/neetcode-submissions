
class Solution {
public:
    int depth = 0;
    int height(TreeNode* root) {
       if(root == NULL){
        return 0;
       } 

       int leftdepth = height(root->left);
       int rightdepth = height(root->right);

       depth = max(depth, leftdepth+rightdepth);
       return max(leftdepth,rightdepth)+1;
    }

    int diameterOfBinaryTree(TreeNode* root){
        height(root);
        return depth;
    }
};
