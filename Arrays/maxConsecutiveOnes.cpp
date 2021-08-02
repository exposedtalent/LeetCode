// https://leetcode.com/problems/max-consecutive-ones/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Optimal TC : O(n) , SC: O(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, max = 0;

        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                count++;
                
            }
            else{
                count = 0;
            }
            if(count > max){
                max = count;
            }
        }
        return max;
    }
};