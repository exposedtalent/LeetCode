// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

// Naive Approach

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(int i =0; i < nums.size(); i ++){
            if(nums[i] == target){
                return true;
            }
        }
        return false;
    }
};
// Optimal TC : O(log n) in the best case worst case O(n) , SC: O(1)
// FOUR CASES : 
// 1 target == nums[mid], then we find it;
// 2 nums[left] < nums[mid], then the left part must be sorted;
// 3 nums[left] > nums[mid], then the right part must be sorted;
// 4 nums[left] == nums[mid], we can not make sure which part is sorted, 
//   the only thing we can do is scale in the problem size. Since target != nums[mid] == nums[left], we just offset right by left++.
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() -1;
        
        while(l <= h){
            // Check the mid is the target
            int mid = l + (h-l)/2;
            if(nums[mid] == target){
                return true;
            }
            // This is the only change needed comparted to the prev solution of th part 1 of this problem
            if( (nums[l] == nums[mid]) && (nums[h] == nums[mid]) ) {++l; --h;}
            // Check where the bigger numbers are left or right size of array
            
            // This checks if they are at the left 
            else if(nums[mid] >= nums[l]){
                // if the larger element are to the left of mid then is the target in the range of the l to mid if it is then move the h pointer to mid -1
                if(target >= nums[l] && target < nums[mid]){
                    h = mid -1;
                }
                // If the target is greater than the mid then the number is to the right of the mid move the l pointer to mid +1
                else{
                    l = mid +1;
                }
            }
            // This checks if the larger number are at the right side of array
            else{
                // if the larger element are to the right of mid then is the target in the range of the h to mid if it is then move the l pointer to mid  + 1
                if(target <= nums[h] && target > nums[mid]){
                    l = mid+1;
                }
                // If the target is not in the range then it is to the left of mid so move the h pointer to the mid -1
                else{
                    h  = mid -1;                    
                }
            }
        }
        // if the mid is not returned then return -1 
        return false;
    }
};
