// https://leetcode.com/problems/longest-consecutive-sequence/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Brute Force TC : O(n log n) SC: O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.empty()){
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        
        int longest = 1 , current = 1;
        
        for(int i = 1 ; i < nums.size(); i ++){
            if(nums[i] != nums[i-1]){
                if(nums[i] == nums[i-1]+1)
                    current++;
                else{
                    longest = max(longest, current);
                    current = 1;
                }
            }
            
        }
        return max(current, longest);
        
    }
};
// Optimal TC : O(n) SC: O(n) or O(1)
class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        vector<int> map(256,-1);
        
        int right = 0, left = 0;
        int n = s.length();
        int ans = 0 ;
        while(right < n){
            // if the character at the right exists or not
            if(map[s[right]] != -1){
                // only update when the elements is not left of left pointer
                left = max(map[s[right]]+1 , left);
            }
            
            map[s[right]] = right;
            ans = max(right - left +1, ans);
            right++;
        }
        
        return ans;
    }
        
    
    
};