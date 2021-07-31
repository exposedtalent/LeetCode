// https://leetcode.com/problems/combination-sum/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    vector<vector<int>> ans;
public:
                
    void backtrack(vector<int>candidates, vector<int>current, int target, int index){
        if(index > candidates.size() || target < 0){
            return;
        }
        if(!target){
            ans.push_back(current);
        }
        
        for(int i  = index; i < candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i -1]){
                continue;
            }
            
            current.push_back(candidates[i]);
            backtrack(candidates, current, target - candidates[i], i + 1);
            current.pop_back();
            
        }
        
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        if(n <= 0 ){
            return ans;
        }
        sort(candidates.begin(), candidates.end());
        vector<int> current;
        backtrack(candidates, current, target, 0);
        return ans;
    }
};