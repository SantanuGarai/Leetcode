class Solution {
public:
    int minDepth(TreeNode* root) {
         if(root == NULL)
            return 0;
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        return (l==0 || r==0)? l+r+1 : min(l,r) + 1 ;
    }
};
