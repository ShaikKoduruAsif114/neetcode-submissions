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

    TreeNode* formtree(vector<int>&preorder,vector<int>&inorder,map<int,int>&mpp,int prestart,int instart,int inend){
        if(instart > inend) return NULL;
        TreeNode* root = new TreeNode(preorder[prestart]);
        int idx = mpp[preorder[prestart]];
        int leftsz = idx-instart;
        TreeNode* left = formtree(preorder,inorder,mpp,prestart+1,instart,idx-1);
        TreeNode* right = formtree(preorder,inorder,mpp,prestart+leftsz+1,idx+1,inend);
        root->left = left;
        root->right = right;
        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0) return NULL;
        map<int,int>mpp;
        for(int i = 0;i<inorder.size();i++){
            mpp[inorder[i]] = i;
        }
        return formtree(preorder,inorder,mpp,0,0,inorder.size()-1);
    }
};
