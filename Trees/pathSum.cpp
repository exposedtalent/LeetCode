// https://leetcode.com/problems/path-sum/

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
// Recursive TC : O(n) , SC: O(n)
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        targetSum -= root->val;
        if(root->left == NULL && root->right == NULL){
            return targetSum == 0;
        }
        return hasPathSum(root->left, targetSum) ||
            hasPathSum(root->right, targetSum);
    }
};
// Iteration solution
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return false;
        }
        stack<TreeNode*> node;
        stack<int> sum;
        node.push(root);
        sum.push(targetSum - root->val);
        
        TreeNode* n;
        int curSum;
        while(!node.empty()){
            n = node.top(); node.pop();
            curSum = sum.top(); sum.pop();
            
            if(n->right == nullptr && n->left == nullptr && curSum == 0){
                return true;
            }
            
            if(n->right){
                node.push(n->right);
                sum.push(curSum - n->right->val);
            }
            if(n->left){
                node.push(n->left);
                sum.push(curSum - n->left->val);
            }
            
        }
        return false;
        
    }
};