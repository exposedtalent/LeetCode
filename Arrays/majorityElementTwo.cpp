// https://leetcode.com/problems/majority-element/

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<climits>
using namespace std;
// Optimal TC : O(n), SC: O(1) can be achieved using the Boyer - Moore's voting algorithm
/*
    Boyer - Moore's voting algorithm : 
        
*/
// Brute force would be two loops where we check for every elements and if it exists add to an array and return the array 
//Using hash map TC : O(n) SC: O(n)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        vector<int> ans;
        int major = nums.size()/3;
        for(int i =0; i < nums.size(); i++){
           map[nums[i]]++;
        }
        for(auto i : map){
            if(i.second > major){
                ans.push_back(i.first); 
            }
        }
        return ans;
    }
};

// Optimal TC : O(n) , SC: O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int major = nums.size()/3;
        int c1 = 0, c2 = 0,el1 = INT_MIN, el2 = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == el1){
                
                c1++;
            }
            else if(nums[i] == el2){
                c2++;
            }
            else if(c1 == 0){
                el1 = nums[i];
                c1 = 1;
            }
            else if(c2 == 0){
                el2 = nums[i];
                c2 = 1;
            }
            
            else{
                c1--;
                c2--;
            }
        }
        
        c1 = 0; 
        c2 = 0;
        for(int i  = 0 ; i < nums.size(); i++){
            if( nums[i] == el1){
                c1++;
            }
            if(nums[i] == el2){
                c2++;
            }
        }
        int n = nums.size();
        if(c1 > n/3){
            ans.push_back(el1);
        }
        if(c2 > n/3){
            ans.push_back(el2);
        }
        return ans;
    }
};

