// https://leetcode.com/problems/palindrome-linked-list/

#include<iostream>
#include<vector>
#include<unordered_map>
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
class Solution {
public:
    
    ListNode* findMid(ListNode* head){
        ListNode* slow, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next;
            if(fast) fast=fast->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode *prev = NULL, *next = NULL,  *cur = head;

        while(cur){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    bool compare(ListNode* h, ListNode* right){
        while(right && h){
            if(h->val !=  right->val ){
                return false;
            }
            else{
                right = right->next;
                h = h->next;
            }
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        ListNode * h = head;
        ListNode * mid = findMid(h);
        ListNode * rev = reverse(mid);
        return compare(head, rev);
    }
};