// https://leetcode.com/problems/remove-linked-list-elements/

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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL){
            return head;
        }
        if(head->val == val){
            ListNode* temp = head;
            head = head->next;
            delete(temp);
        }
        
        ListNode* sen = new ListNode(0);
        sen->next = head;
        ListNode* cur = head, *prev = sen, *toDel = nullptr;
        while(cur != nullptr){
            if(cur->val == val){
                prev->next = cur->next;
                toDel = cur;
                
            }
            else{
                prev = cur;
            }
            cur = cur->next;
            
            if(toDel != nullptr){
                delete(toDel);
                toDel = nullptr;

            }
        }
        return sen->next;
        
    }
};