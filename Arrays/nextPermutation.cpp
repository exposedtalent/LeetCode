// https://leetcode.com/problems/next-permutation/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
    Intuition -> 
        Lets take an example of array of 1 3 5 4 2 and its next premutation is 1 4 2 3 5
        the intuition relies on the dictionary order of the elements
                5
            3       4
        1               2
        all the elements right of the 5 are increasing to 5 and all the elements to left are decreasing
        As the more premutation occur the number is going to increase example : 123 -> 132 -> 213 and so on we can see that the number
        is increasing every permutation so we need to find a element that is going to be greater than the number. we need to swap the elements where a[i] <= a[i+1]
        after we swap the elements we will have the array as  1 4 5 3 2. Now since we have the next prefix of the permutation ( 1 4 ) right we need to have the rest 
        of the array elements such that they are the lowest. To do that we can simply reverse the array after the index 1 to get the final answer as 1 4 2 3 5
    Algorithm -> 
        1. we first traves the array backwards and find an element such that it is smaller than the element after it.
        2. The next step is to find an element such that it is greater than the prev element we found. We are going to traverse the array backwards again.
        3. The third Step is to swap the smaller element with the larger 
        4. we revese the array from the i'th +  1 element

    TC : O(n) , SC: O(1)
*/


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size(), i , j;
        for(i  = size - 2; i >= 0; i--){
            if(nums[i] < nums[i +1]){
                break;
            }
        }
        if(i < 0){
            reverse(nums.begin(), nums.end());
        }
        else{
            for(j = size - 1; j >= 0 ;j--){
                if(nums[j] > nums[i]){
                    break;
                }
            }
            swap(nums[j], nums[i]);
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};