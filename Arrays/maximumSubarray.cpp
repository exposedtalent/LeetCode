// https://leetcode.com/problems/maximum-subarray/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Brute Force
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum = INT_MIN;
        for(int i =0; i < nums.size(); i++){
            int sum = 0;
            for(int j = i; j < nums.size(); j++){
                sum += nums[j];
                maximum = max(sum , maximum);
            }
        }
        return maximum;
    }
};

// Optimal Solution using Kadane's algorithm TC : O(n) , SC: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum = INT_MIN;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            maximum = max( sum, maximum);
            
            if(sum < 0){
                sum = 0;
            }
 
        }
        return maximum;
    }
};