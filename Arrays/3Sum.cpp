// https://leetcode.com/problems/3sum/

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<climits>

// optimal solution TC: O(n^2) SC: 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        // Edge case
        if(nums.size() == 0 || nums.size() == 1){
            return ans;
        }
        sort(nums.begin(), nums.end());
        // Using a two pointer approach we put a at nums[i]
        for(int i = 0; i < nums.size() - 2; i++){
            // if to get of the A pointer duplicates
            if( i == 0 || (i > 0 && nums[i] != nums[i-1])){
                int lo = i+1, hi = nums.size() - 1, sum = 0 - nums[i];
            
                // When they cross that is the end point 
                while(lo < hi){
                    if(nums[lo] + nums[hi] == sum){
                        // We found a set that nums at lo, hi, and i equal to 0
                        // Push them in a vector and then to the ans vector
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[lo]);
                        temp.push_back(nums[hi]);
                        ans.push_back(temp);
                        // Used to get skip the duplicates 
                        while(lo < hi && nums[lo]== nums[lo+1]) lo++;
                        while(lo < hi && nums[hi]== nums[hi-1]) hi--;
                        // Get to the unique elements
                        lo++;
                        hi--;
                        
                    }
                    // logic so that if the sum is greater than the two combined then need to move the lo pointer higher as the vector is sorted 
                    else if(nums[lo] + nums[hi] < sum){
                        lo++;
                    }
                    else{
                        hi--;
                    }
                }
            }
            
        }
        return ans;
    }
};