/*
 * Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
 *
 * Example 1:
 * Input: root = [1,2,3,null,5,null,4]
 * Output: [1,3,4]
 *
 * Example 2:
 * Input: root = [1,null,3]
 * Output: [1,3]
 *
 * Example 3:
 * Input: root = []
 * Output: []
 */

Iterative solution:

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root==NULL)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(i==size-1){
                    result.push_back(node->val);
                }
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        return result;
    }
};


Recursive solution:

public class Solution {
    public:
        vector<int> rightSideView(TreeNode* root) {
             vector<int> result;
             rightView(root, result, 0);
             return result;
          }
    
    public void rightView(TreeNode* curr, vector<int> result, int currDepth){
        if(curr == NULL){
            return;
        }
        if(currDepth == result.size()){
            result.push_back(curr->val);
        }
        
        rightView(curr->right, result, currDepth + 1);
        rightView(curr->left, result, currDepth + 1);
        
    }
}
