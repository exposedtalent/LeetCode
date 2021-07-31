// https://leetcode.com/problems/combination-sum/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    vector<vector<int>> ans;
    vector<int> current;
    int sum;
public:
    
    void backTrack(vector<int> candidates, int index, int target){
        if(sum > target){
            return;
        }
        if(sum == target){
            ans.push_back(current);
        }
        
        for(int i = index; i < candidates.size(); i++){
            sum += candidates[i];
            current.push_back(candidates[i]);
            backTrack( candidates,  i,  target);
            sum -= candidates[i];
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sum = 0; 
        backTrack(candidates, 0, target);
        return ans;
    }
};