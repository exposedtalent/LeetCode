

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Brute Force TC : O(m X n) SC: O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headA != NULL){
            ListNode* pB = headB;
            while(pB != NULL){
                if(headA == pB){
                    return headA;
                }
                pB = pB->next;
            }
            headA = headA->next;
        }
        
        return NULL;
    }
};

// Hashing solution TC: O(N + M) SC : O(M)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode *> map;

        while(headB != NULL){
            map.insert(headB);
            headB = headB->next;
        }

        while(headA != NULL){
            if(map.find(headA) != map.end()){
                return headA;
            }
            headA = headA->next;
        }

        return NULL;
    }
};

// Optimal TC : O(N + M) , SC: O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* d1 = headA;
        ListNode* d2 = headB;
        
        while(d1 != d2){
            d1 = d1 == NULL ? headB : d1->next;
            d2 = d2 == NULL ? headA : d2->next;
            
        }
        return d1;
        
    }
};