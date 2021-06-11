#include <iostream>
#include<vector>
using namespace std;
struct TreeNode {
      int val;
    TreeNode *left;
     TreeNode *right;
     TreeNode(int data) {
         val = data;
         left = NULL;
         right = NULL ;
     }
     
 };
 bool search(TreeNode* root,TreeNode* p,vector<TreeNode*>& ans);
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return NULL;
        TreeNode* ans;
        vector<TreeNode*> vec1,vec2;
        search(root,p,vec1);
        //vec1 = v1;
        search(root,q,vec2);
        //vec2 = v1;
        int n = min(vec1.size(),vec2.size());
        int i;
        for(i=0;i<vec1.size() && i<vec2.size();i++){
            if(vec1[i]->val == vec2[i]->val){
                ans = vec1[i];
            }
        }
        return ans;
    }
    bool search(TreeNode* root,TreeNode* p,vector<TreeNode*>& ans){
        if(!root){
            return false;
        }
        ans.push_back(root);
        if(root->val == p->val){
            return true;
        }
        if( search(root->left,p,ans)||search(root->right,p,ans)){
            return true;
        }
        ans.pop_back();
        return false;
    }
int main()
{
   TreeNode* root = new TreeNode(1);
   root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left =  new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right =  new TreeNode(6);
    TreeNode* p =  new TreeNode(7);
    root->right->left->left = p;
    vector<TreeNode*> ans;
    search(root,root->left->left,ans);
    for(auto i : ans){
        cout<<i->val<<endl;
    }
   
   return 0;
}
