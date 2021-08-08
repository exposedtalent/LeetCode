// https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/

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
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        
        if(root->left == nullptr and root->right == nullptr){
            return 1;
        }
        
        int maxD = INT_MIN;
        if(root->left) {
            maxD = max(maxD, maxDepth(root->left));
        }
        if(root->right) {
            maxD = max(maxD, maxDepth(root->right));
        }
        return maxD+1;
        
    }
};

// Iteration Solution
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int maxD = 0;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            maxD++;
            int n = q.size();
            
            for(int i =0; i < n; i ++){
                TreeNode* curr = q.front(); q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        
        return maxD;
        
    }
};