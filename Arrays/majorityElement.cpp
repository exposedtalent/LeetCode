// https://leetcode.com/problems/majority-element/

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
// Optimal TC : O(n), SC: O(1) can be achieved using the Moore's voting algorithm
/*
    Moore's voting algorithm : 
        The intuition behind is that as we know that theere will be more than n/2 elements in the array of same element we can
        traveser throught and end up have a positive number of count as more than half of the array is one element 

*/
// Using hashMaps TC: O(n) , SC: O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums.size()/2;
        int ans = 0;
        map <int,int> m;
        for(int i  =0 ; i < nums.size(); i++){
            m[nums[i]]++;
        }
        for(auto i : m){
            if(i.second > major){
                ans = i.first;
            }
        }
        return ans;
    }
};

// Optimal TC : O(n) , SC: O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(count == 0){
                element = nums[i];
            }
            if(element  == nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        return element;
    }
};