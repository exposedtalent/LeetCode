// https://leetcode.com/problems/missing-number/

#include<iostream>
#include<vector>

//  Brute force TC : O(nlogn) SC : O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // Ensure that n is at the last index
        if (nums[nums.size()-1] != nums.size()) {
            return nums.size();
        }
        // Ensure that 0 is at the first index
        else if (nums[0] != 0) {
            return 0;
        }
        for(int i =1; i< nums.size(); i++){
            int expected = nums[i -1] +1;
            if(expected != nums[i]){
                return expected;
            }
        }
        
        return -1;
    }
};
// Optimal 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int mis = nums.size();
        
        for(int i  =0; i < nums.size(); i++){
            mis ^= i ^ nums[i];
        }
        
        return mis;
    }
};