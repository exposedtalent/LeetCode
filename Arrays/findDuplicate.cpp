// https://leetcode.com/problems/trapping-rain-water/

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