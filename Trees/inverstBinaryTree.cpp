// https://leetcode.com/problems/invert-binary-tree/

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
// Recursive TC : O(n) , SC : O(n)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }
        
        TreeNode* left = invertTree(root->right);
        TreeNode* right = invertTree(root->left);
        TreeNode* newRoot = root;
        newRoot->left = left;
        newRoot->right = right;
        return newRoot;
        
    }
};
// Iteration TC : O(n) , SC : O(n)
// Since we are making a queue of pointer thats how the root is being changed by the newRoot in the while loop
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* newRoot = q.front(); q.pop();
            TreeNode* temp = newRoot->left;
            newRoot->left = newRoot->right;
            newRoot->right = temp;
            if(newRoot->left){
                q.push(newRoot->left);
            }
            if(newRoot->right){
                q.push(newRoot->right);
            }
            
        }
        return root;
    }
};

