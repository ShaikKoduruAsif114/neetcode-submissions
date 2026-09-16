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
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        
        if(root==NULL) return 0;
        int cnt = 1;
        q.push({root,root->val});
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node.first->left){
                q.push({node.first->left,max(node.second,node.first->left->val)});
                if(node.first->left->val >= node.second){
                    cnt++;
                }
            }
            if(node.first->right){
                q.push({node.first->right,max(node.second,node.first->right->val)});
                if(node.first->right->val >= node.second){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
