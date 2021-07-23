
// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;

// Brute Force 
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        
        for(int i =0; i < nums.size(); i++){
            int count = 0;
            for(int j = 0; j < nums.size(); j++ ){
                if(nums[j] < nums[i] && nums[j] != nums[i]){
                    count++;
                }
            }
            ans.push_back(count);
        }
        
        return ans;
    }
};

// using unordered_map 
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map <int , int> map;
        vector<int> ans = nums;
        sort(ans.begin(), ans.end());
        
        for(int i =0; i < ans.size(); i++){
            if(map.find(ans[i]) == map.end()){
                map[ans[i]] = i;
            }
        }
        
        for(int i =0; i < nums.size(); i++){
            nums[i] = map[nums[i]];
        }
        return nums;
    }
};