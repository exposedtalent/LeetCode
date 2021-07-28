// https://leetcode.com/problems/4sum/

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<climits>


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // T = O(n^3) & S = O(1)
        vector<vector<int>> res; // creating a result vector
        if(nums.empty()) { // If no element in given vector then empty vector iss returned
            return res;
        }
        int n = nums.size();  // size of given vector
        sort(nums.begin(), nums.end());  // sort the array in O(nlog(n)) for optimizing solution
        
        for(int i = 0; i < n; i++) {    // i pointer from 0 to n
            for(int j = i+1; j < n; j++) {  // j pointer from i+1 to n
                int rem = target - nums[i] - nums[j]; // remaining value to find
                int front = j+1;   // left pointer  just after j
                int back = n-1;    // right pointer at last index
                
                while(front < back) { // loop till front and back pointer donot cross over
                    int two_sum = nums[front] + nums[back]; // now come to two sum problem where we need to check for rem
                    if(two_sum < rem) front++;  // if(rem > two_sum) then logically we have to move front pointer ahead to increase value close to rem
                               
                    else if(two_sum > rem) back--; // if(rem < two_sum) then logically move back pointer to back to minimise value to come closer to rem value 
                    
                    else {           // if (rem == two_sum) then we got the quadruplet (i, j, front, back indexed values)
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[front];
                        quadruplet[3] = nums[back];
                        res.push_back(quadruplet);
                        
                        // processing the duplicates of number 3
                        while(front < back && nums[front] == quadruplet[2]) ++front;
                        
                        // processing the duplicates of number 4
                        while(front < back && nums[back] == quadruplet[3]) --back;
                    }
                }
                // processing the duplicates of number 2
                while(j + 1 < n && nums[j + 1] == nums[j]) ++j;
            }
             // processing the duplicates of number 1
                while(i + 1 < n && nums[i + 1] == nums[i]) ++i;
        }
        return res;
    }
};