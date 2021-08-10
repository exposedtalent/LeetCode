// https://leetcode.com/problems/range-sum-query-immutable/

#include<iostream>
#include<vector>

// Brute Force
class NumArray {
    vector<int> data;
public:
    
    NumArray(vector<int>& nums) {
        data = nums;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        for(int i = left; i <= right; i++){
            sum += data[i];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

// Optimal
class NumArray {
public:
    vector<int> sums;
    NumArray(vector<int> &nums) {
        sums.push_back(0);
        for (auto x: nums)
            sums.push_back(sums.back() + x);
    }
    int sumRange(int i, int j) {
         return sums[j + 1] - sums[i];
    }
};
