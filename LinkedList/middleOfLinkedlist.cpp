// https://leetcode.com/problems/middle-of-the-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Brute Force TC: O(n) + O(n/2) SC: O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, *fast = head;
        int n = 1;
        
        while(slow->next){
            slow = slow->next;
            n++;
        }
        
        n/=2;
        
        for(int i = 0; i < n;i++){
            fast = fast->next;
        }
       
        return fast;
    }
};

// Optimal TC : O(n) , SC: O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, *fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};