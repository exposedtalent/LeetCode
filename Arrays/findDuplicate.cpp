// https://leetcode.com/problems/find-the-duplicate-number/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Brute Force time : Big O(n log n ) space O(log n ) or O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i =1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1]){
                return nums[i];
            }
        }
        return NULL;
    }
};
// Using Set TC : O(n) , SC: O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> seen;
        for(auto num : nums){
            if(seen.count(num)){
                return num;
            }
            seen.insert(num);
        }
        return -1;
    }
};

// TC : O(n) , SC: O(1) still modifying the array
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            // get the index
            int index = abs(nums[i]) - 1;
            // multiply the number to make it negative
            nums[index] *= -1;
            // if positive then its a dup
            if(nums[index] > 0){
                return abs(nums[i]);
            }
        }
        return -1;
    }
};

// Optimal TC : O(n), SC: O(1) without changing the array
/*
    One pointer will be moving fast jumping two indexs and then the slower pointer will be moving slower moving 1 index at a time
    once they both reach at a point wherer they both are equal we are going to chnag the fast pointer to go back the nums[0] and then run bothg
    of them again but this time they both only increment by one everytime.
    THIS IS DONE WITH THE FLOYD'S ALGORITHM
    HOW THE FLOYD'S AGORIRTHM WORKS IN SIMPLE MATH
    Algorithm: Assume non-cyclic length N and cyclic length M with index [0,M-1]

    <-  N  ->          1. When slow enters the cycle at 0 (◎), fast is at N (■)
            s
    □-□-□-□-◎-□-□-□    2. Fast is M-N behind, so they will meet at M-N (※)
            |     |
            □  M  ■ f  3. Cycle entrance is now M-(M-N) = N away, so if we
            |     |       make one pointer start over and both at slow speed,
            □-□-※-□       they will guarantee to meet again at 0 (◎)meet

*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() > 1){
            int slow = nums[0];
            int fast = nums[0];

            do{
                fast = nums[nums[fast]];
                slow = nums[slow];
            }while(slow != fast);

            fast = nums[0];
            while(slow != fast){
                fast = nums[fast];
                slow = nums[slow];
            }
            return slow;
        }
        return -1;
    }
};