/*
 * Given the root of a binary tree, return the leftmost value in the last row of the tree.
 *
 * Example 1:
 * Input: root = [2,1,3]
 * Output: 1
 *
 * Example 2:
 * Input: root = [1,2,3,4,null,5,6,null,null,7]
 * Output: 7
 *
 * Constraints:
 * The number of nodes in the tree is in the range [1, 104].
 * -231 <= Node.val <= 231 - 1
 */

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node  = root;
        while(!q.empty()){
                node = q.front();
                q.pop();
                if(node->right)
                    q.push(node->right);
                if(node->left)
                    q.push(node->left);
            
        }
            return node->val;
    }
};
