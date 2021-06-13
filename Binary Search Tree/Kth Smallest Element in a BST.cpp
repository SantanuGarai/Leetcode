/*
Given the root of a binary search tree, and an integer k, return the kth (1-indexed) smallest element in the tree.
Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 1

Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3

Constraints:
The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
*/

Solution:
class Solution {
public:
    
    int kthSmallest(TreeNode* root, int k) {
        int count = 1;
        return inorder(root,k,count);
    }
    int inorder(TreeNode* root,int k,int& count){
        if(root==NULL)
             return -1;
        int left = inorder(root->left,k,count);
        if(left!=-1)
            return left;
        if(count==k)
            return root->val;
        count++;
        return inorder(root->right,k,count);
    }
};
