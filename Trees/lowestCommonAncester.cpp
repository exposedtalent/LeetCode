// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Recursive TC : O(n) , SC : O(n)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int parentVal = root->val;
        int pVal = p->val;
        int qVal = q->val;
        
        if(pVal > parentVal &&  qVal > parentVal){
            return lowestCommonAncestor(root->right,p,q);
        }
        else if(pVal < parentVal &&   qVal <  parentVal){
            return lowestCommonAncestor(root->left, p, q);

        }
        else{
            return root;
        }
    }
};

// Iteration Solution TC : O(n) , SC : O(1)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pVal = p->val;
        int qVal = q->val;
        TreeNode* node = root;
        while(node != nullptr){
            int parentVal = node->val;
            if(pVal > parentVal &&  qVal > parentVal){
                node = node->right;
            }
            else if(pVal < parentVal &&   qVal <  parentVal){
                node = node->left;
            }
            else{
                return node;
            }  
            
        }
        return nullptr;
        
    }
};