// https://leetcode.com/problems/sort-colors/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Brute Force
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};
// Optimal
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0;
        int size = nums.size() -1;
        int high = size;

        while(mid <= high) {
            switch (nums[mid])
            {
            case 0:
                swap(nums[mid++], nums[low++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(nums[mid], nums[high--]);
                break;
            default:
                break;
            }
        }

        
    }
};