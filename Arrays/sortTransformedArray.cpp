// https://leetcode.com/problems/sort-transformed-array/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> ans(n);
        
        for(int i = 0; i < n; i++){
            ans[i] = (a*(nums[i]*nums[i]) + b*nums[i] + c);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};