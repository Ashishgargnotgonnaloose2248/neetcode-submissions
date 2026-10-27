
class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int leftheight = height(root->left);
        if(leftheight == -1){
            return -1;
        }

        int rightheight = height(root->right);
        if(rightheight == -1){
            return -1;
        }
        
        if (abs(leftheight - rightheight) > 1) {
            return -1;
        }
        
        return 1+max(leftheight,rightheight);
    }
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
