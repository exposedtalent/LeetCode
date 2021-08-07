// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* cur = head,*toDel = nullptr;
        while(cur && cur->next){
            if(cur->val == cur->next->val){
                toDel = cur->next;
                cur->next = cur->next->next;
                
            }else{
                cur = cur->next;
            }
            
            if(toDel != nullptr){
                delete(toDel);
                toDel = nullptr;
            }
            
        }
        return head;
        
    }
};