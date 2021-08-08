// https://leetcode.com/problems/same-tree/

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

// Using recursion  TC : O(n) , SC : O(n)
class Solution {
public:
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }
        if(p == NULL || q == NULL){
            return false;
        }
        
        if(p->val != q->val){
            return false;
        }
        return isSameTree(p->left, q->left) 
            && isSameTree(p->right, q->right);
    }
};

// Using iteration  TC: O(n) , SC : O(n)

class Solution {
public:
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que;
        que.push(p);
        que.push(q);
        
        while(que.size() != 0){
            TreeNode* pTemp = que.front(); que.pop();
            TreeNode* qTemp = que.front(); que.pop();
            
            if(pTemp == nullptr && qTemp == nullptr) continue;
            if(pTemp == nullptr or qTemp == nullptr) return false;
            if(pTemp->val != qTemp->val) return false;

            que.push(pTemp->left);
            que.push(qTemp->left);
            que.push(pTemp->right);
            que.push(qTemp->right);
            
        }
        
        return true;
    }
};