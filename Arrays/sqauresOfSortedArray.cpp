// https://leetcode.com/problems/squares-of-a-sorted-array/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int left = 0;
        int right = nums.size()-1;
        
        for(int i = nums.size()-1; i >= 0; i--){
            
            int square;
            if(abs(nums[left]) < abs(nums[right])){
                square = nums[right];
                right--;
            }
            else{
                square = nums[left];
                left++;
            }
            ans[i] = (square*square);
        }
        return ans;
    }
};