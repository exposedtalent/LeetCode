// https://leetcode.com/problems/reverse-nodes-in-k-group/

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
// TC : O(n) , SC: O(1)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy, *cur = dummy, *nxt = dummy;
        int count = 0;
        
        ListNode* p1 = dummy;
        while(p1->next != NULL){
            p1 = p1->next;
            count++;
        }
        
        while(count >= k){
            cur = prev->next;
            nxt = cur->next;
            for(int i =1; i < k; i++){
                cur->next = nxt->next;
                nxt->next = prev->next;
                prev->next = nxt;
                nxt = cur->next;
                
            }
            prev = cur;
            count -= k;
        }
        return dummy->next;
    }
};