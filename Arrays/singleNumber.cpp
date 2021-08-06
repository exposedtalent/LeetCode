// https://leetcode.com/problems/single-number/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;



class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> map;
        
        for(int i =0; i < nums.size(); i++){
            map[nums[i]]++;
        }
        
        for(auto a : map){
            if(a.second ==1){
                return a.first;
            }
        }
        return -1;
    }
};