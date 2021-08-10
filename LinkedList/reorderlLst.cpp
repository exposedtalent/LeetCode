// https://leetcode.com/problems/reorder-list/

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
class Solution {
public:
    
    void reorderList(ListNode* head) {
        
        // FIND THE MIDDLE
        ListNode* slow= head, *fast= head;
        while(fast && fast->next){
            slow= slow->next;
            fast =fast->next->next;
        }
        // REVERSE THE MIDDLE 
        ListNode* prev =NULL, *cur = slow, *tmp;
        while(cur){
            tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        // MERGE THE MIDDLE THE TWO LISTS
        ListNode* f = head, *s = prev;
        while(s->next){
            tmp = f->next;
            f->next = s;
            f = tmp;
            
            tmp = s->next;
            s->next = f;
            s = tmp;
        }
        

        
    }
};