// https://leetcode.com/problems/reverse-linked-list

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

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

// Optimal TC : O(n) , SC: O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur, *prev = NULL;
        
        while(head != NULL){
            cur = head->next;
            head->next = prev;
            prev = head;
            head = cur;
        }
        return prev;
    }
    
    
};