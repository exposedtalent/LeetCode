// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <iostream>
#include <vector>
//Optimal TC : O(log n), SC: O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        // loop throught the nums
        while(low < high){
            // if the low number is less that the high meaning that there is no rotation so we can return the low number
            if(nums[low] < nums[high]){
                return nums[low];
            }
            // Else we need to calculate the mid point 
            int mid = low + ( high - low) /2;
            // Then check the mid point num is bigger than the high one and if it is then we know that all the number left of
            //  mid are bugger numbers so we need to search in the right half of the array.
            if(nums[mid] >= nums[high] ){
                low = mid +1;
            }
            // Else we know the min num will be at the left part of the array
            else{
                high = mid; 
            }
        }
        return nums[low];
    }
};