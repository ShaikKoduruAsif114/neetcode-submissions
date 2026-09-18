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


    bool isequal(TreeNode* p,TreeNode* q){
        if(q==NULL && p==NULL) return true;
        if(q==NULL || p==NULL) return false;
        bool left = isequal(p->left,q->left);
        bool right = isequal(p->right,q->right);
        return ((p->val==q->val) && (left&&right));
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==NULL) return true;
        if(root==NULL && subRoot!=NULL) return false;
        if(subRoot==NULL) return true;
        bool place = isequal(root,subRoot);
        bool left = isequal(root->left,subRoot);
        bool right = isequal(root->right,subRoot);
        return ((left||right)||place);
    }
};
