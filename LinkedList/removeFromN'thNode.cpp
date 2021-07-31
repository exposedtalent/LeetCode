// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int num = 0;
        ListNode* temp = head;
        // traverse the linked list to find the length
        while(temp != NULL){
            temp = temp->next;
            num++;
        }
        // Edge Case where the list only has one element and wants to delete it
        if(num == 1){
            ListNode* t = head;
            head = NULL;
            delete(t);
            return head;
        }
        int k = num - n;
        // Edge Case where the number that needed to be deleted is the head
        if(k == 0){
            ListNode* t = head;
            head = head->next;
            delete(t);
            return head;
        }
        
        ListNode* newH = head;
        // traverse the linked list but stop at the element before the delete one
        for(int i = 1; i < k;i++){
            newH = newH->next;
        }
        // delete the element 
        ListNode* del = newH->next;
        newH->next = del->next;
        delete(del);
        
        return head;
    }
};