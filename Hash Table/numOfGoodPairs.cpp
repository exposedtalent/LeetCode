// https://leetcode.com/problems/number-of-good-pairs/

#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> map;
        int ans=0;
        for(int i =0; i < nums.size(); i++){
            if(map.find(nums[i]) != map.end()){
                ans += map[nums[i]];
            }
            map[nums[i]]++;
        }
        return ans;
    }
};