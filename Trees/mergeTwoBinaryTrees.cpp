// https://leetcode.com/problems/merge-two-binary-trees/

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

// Naive Solution sharing nodes between the old trees and the new tree can be a problem.  
//  If any of the old trees is deleted, it's going to also destruct the shared nodes in the new tree
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2) {
        if(r1 && r2){
            TreeNode* root = new TreeNode(r1->val + r2->val);
            root->left = mergeTrees(r1->left, r2->left);
            root->right =mergeTrees(r1->right, r2->right);
            return root;
        }
        else{
            return r1 ? r1 : r2;
        }
    }
};

// Optimal Solution 

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2) {
        if(!r1 && !r2) return nullptr;
        
        int val1 = r1 ? r1->val : 0;
        int val2 = r2 ? r2->val : 0;
        
        TreeNode* root = new TreeNode(val1 + val2);
        root->left = mergeTrees(r1 ? r1->left : nullptr, r2 ? r2->left : nullptr);
        root->right = mergeTrees(r1 ? r1->right : nullptr, r2 ? r2->right : nullptr);
        
        return root;
        
    }
};

// Iteratively Solution

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2) {
        
        stack<TreeNode*> stack;
        stack.push(r1);
        stack.push(r2);
        if(r1 == nullptr) return r2;
        
        // r1->val += r2->val;
        while(!stack.empty()){
            TreeNode* one = stack.top(); stack.pop();
            TreeNode* two = stack.top(); stack.pop();
        
            if(one != nullptr && two  != nullptr){
                one->val += two->val;
                if(one->left == nullptr){
                    one->left = two->left;
                }
                else{
                    stack.push(one->left);
                    stack.push(two->left);
                }
                
                if(one->right == nullptr){
                    one->right = two->right;
                }
                else{
                    stack.push(one->right);
                    stack.push(two->right);
                }
            }
            
        }
        return r1;
        
    }
};