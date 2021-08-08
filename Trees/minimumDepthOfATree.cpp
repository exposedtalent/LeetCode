// https://leetcode.com/problems/minimum-depth-of-binary-tree/

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

// Approach one recursion  TC : O(n) , SC: O(n)
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        if(root->left == NULL && root->right == NULL){
            return 1;
        }
        int mini = INT_MAX;
        if(root->left != NULL){
            mini =  min(minDepth(root->left), mini);
        }
        if(root->right != NULL){
            mini =  min(minDepth(root->right), mini);
        }
        
        return mini +1;
    }
};

// Iteration Solution

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;
        while(q.size()){
            int size = q.size();
            for(int i =0;i < size; i++){
                TreeNode* temp = q.front(); q.pop();
                if(temp->left == NULL and temp->right == NULL){
                    return depth;
                }
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            depth += 1;
        }        
        return -1;
        
        
        
    }
};