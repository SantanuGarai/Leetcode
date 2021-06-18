/*
Given a binary tree, return the sum of values of nodes with even-valued grandparent.  (A grandparent of a node is the parent of its parent, if it exists.)
If there are no nodes with an even-valued grandparent, return 0.

Example 1:
Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 18
Explanation: The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents.

Constraints:
The number of nodes in the tree is between 1 and 10^4.
The value of nodes is between 1 and 100.
*/

Solutions:
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL) 
		     return 0;
        int sum=0;
        if(root->val%2==0){
            if(root->left!=NULL && root->left->left!=NULL)
                sum+=root->left->left->val;
            if(root->left!=NULL && root->left->right!=NULL)
                sum+=root->left->right->val;
            if(root->right!=NULL && root->right->right!=NULL)
                sum+=root->right->right->val;
            if(root->right!=NULL && root->right->left!=NULL)
                sum+=root->right->left->val;
        }
        sum+=sumEvenGrandparent(root->left); 
        sum+=sumEvenGrandparent(root->right); 
		
        return sum;
    }
};

Another Solutions:

int sumEvenGrandparent(TreeNode* root, int p = 1, int gp = 1) {
        return root ? sumEvenGrandparent(root->left, root->val, p) + sumEvenGrandparent(root->right, root->val, p) + (gp % 2 ? 0 : root->val)  : 0;
    }
