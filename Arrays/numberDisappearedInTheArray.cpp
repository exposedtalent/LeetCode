// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        
        for(int i = 0; i< nums.size(); i++){
            int ind = abs(nums[i]) -1;
            
            if(nums[ind] > 0){
                nums[ind] *= -1;
            }
        }
     
        for(int i = 1; i<= nums.size(); i++){
            
            if(nums[i -1] > 0){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};