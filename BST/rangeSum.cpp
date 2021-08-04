// https://leetcode.com/problems/range-sum-of-bst/

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
    int num = 0;
    void range(TreeNode* root, int s, int e){
        if(root == NULL){
            return;
        }
        range(root->left, s, e);
        if(root->val >= s and root->val <= e){
            num += root->val;
        }
        range(root->right, s, e);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        range(root, low, high);
        return num;
    }
};