// https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
// Approach using recursion 
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> ans;
        q.push(root);
        
        while(q.size()){
            double len = q.size(), row = 0;
            for(int i =0; i < len; i++){
                TreeNode* temp = q.front(); q.pop();
                row += temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans.push_back(row / len);
        }
        return ans;
    }
};

// BSF Iteration approach 
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        else{
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
        }
        return -1;
    }
};