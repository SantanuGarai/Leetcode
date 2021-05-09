/*
 * Problems:
 * Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
 *
 * Example 1:
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * Output: [3,9,20,null,null,15,7]
 *
 * Example 2:
 * Input: preorder = [-1], inorder = [-1]
 * Output: [-1]
 *
 * Constraints:
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder and inorder consist of unique values.
 * Each value of inorder also appears in preorder.
 * preorder is guaranteed to be the preorder traversal of the tree.
 * inorder is guaranteed to be the inorder traversal of the tree.
 *
 * 
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 * 
 * 
 * Solutions:
 */

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return makeTree(preorder,inorder,0,inorder.size()-1,0);
    }
    TreeNode* makeTree(vector<int>& preorder, vector<int>& inorder,int start,int end,int preStart) {
        if(start>end)
            return NULL;
        int val = preorder[preStart];
        TreeNode* curr = new TreeNode(val);
        if(start==end)
           return curr;
        int pos = search(inorder,start,end,val);
        curr->left = makeTree(preorder,inorder,start,pos-1,preStart+1);
        curr->right = makeTree(preorder,inorder,pos+1,end,preStart+pos-start+1);
        return curr;
    }
    int search(vector<int>& inorder,int start,int end,int val){
        for(int i=start;i<=end;i++){
            if(inorder[i]==val){
                return i;
            }
        }
        return -1;
    }
};
