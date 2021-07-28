// https://leetcode.com/problems/reverse-pairs/

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<climits>

// Brute force but this will only work with smaller sets of problem 
// TC : O(n^2) SC: O(1)
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int count = 0;
        for(int i  = 0; i < nums.size(); i++){
            for(int j = i +1; j < nums.size(); j++){
                if(nums[i] > 2 * nums[j]){
                    count++;
                }
            }
        }
        return count;
    }
};
// Optimal Merge sort function
//  TC : O(n log n) SC: O(n)