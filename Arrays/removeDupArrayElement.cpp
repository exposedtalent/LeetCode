// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Optimal TC : O(n) , SC: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() ==  0){
            return 0;
        }
        
        int i = 0;
        
        for(int j = 1; j < nums.size();j++){
            if(nums[i] != nums[j]){
                nums[++i] = nums[j];
            }
        }
        
        return i+1;
    }
};