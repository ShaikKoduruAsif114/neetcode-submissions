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

    TreeNode* f(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==p) return p;
        if(root==q) return q;
        if(root==NULL) return NULL;
        TreeNode* left = f(root->left,p,q);
        TreeNode* right = f(root->right,p,q);
        if(left==NULL) return right;
        if(right ==NULL) return left;
        if(left!=NULL&& right!=NULL) return root;
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return f(root,p,q);
    }
};
