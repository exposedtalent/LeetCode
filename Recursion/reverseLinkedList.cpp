// https://leetcode.com/problems/reverse-linked-list/

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


#include<iostream>
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return helper(head, NULL);
    }
    
    ListNode* helper(ListNode* cur, ListNode* newHead) {
        if (cur == NULL) {
            return newHead;
        }
        ListNode* next = cur->next;
        cur->next = newHead;
        return helper(next, cur);
    }
};