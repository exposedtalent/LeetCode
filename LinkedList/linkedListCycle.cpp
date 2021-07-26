// https://leetcode.com/problems/linked-list-cycle-ii/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


//     THIS IS DONE WITH THE FLOYD'S ALGORITHM
class Solution {
public:
    ListNode* getIntersection(ListNode* head){
        ListNode* slow = head, *fast = head;
        
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                return fast;
            }
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL){
            return NULL;
        }
        
        ListNode* inter = getIntersection (head); 
        if(inter == NULL){
            return NULL;
        }
        ListNode *fast = head;
        while(fast != inter){
            inter = inter->next;
            fast = fast->next;
            
        }
        return inter;
        
    }
};