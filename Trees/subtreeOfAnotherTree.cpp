// https://leetcode.com/problems/subtree-of-another-tree/

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
    bool helper(TreeNode* r, TreeNode* s){
        if(!r || !s ) {
            return r==nullptr && s==nullptr;
        }
        else if(r->val == s->val){
            return helper(r->left, s->left) && helper(r->right, s->right);
        }
        else{
            return false;
        }
    }
    
    bool isSubtree(TreeNode* r, TreeNode* s) {
       if(r == nullptr  ){
           return false;
       }
        if(helper(r, s)){
            return true;
        }
        else{
            return isSubtree(r->left, s) || isSubtree(r->right, s);
        }

    }
};