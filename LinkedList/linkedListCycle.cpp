// https://leetcode.com/problems/linked-list-cycle/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Solution using Hashing TC : O(n) , SC: O(n)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> map;
        while(head != NULL){
            if(map.find(head) != map.end()){
                return true;
            }
            map.insert(head);
            head = head->next;
        }
        return false;
    }
};

// FLOYD ALGORITHM TC: O(n), SC O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};