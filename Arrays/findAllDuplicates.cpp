// https://leetcode.com/problems/find-all-duplicates-in-an-array/

// Better than brute force. TC : O(n) , SC: O(n)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> s;
        if(nums.size() == 1){
            return ans;
        }
        
        for(int i =0; i< nums.size(); i++){
            if(s.count(nums[i]) > 0){
                ans.push_back(nums[i]);
            }
            else
                s.insert(nums[i]);
        }
        return ans;
    }
};

// Optimal TC : O(n) , SC: O(1) well not couting the ans vector 

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        if(nums.size() == 1){
            return ans;
        }
        
        for(int i =0; i< nums.size(); i++){
            if(nums[abs(nums[i]) -1] < 0){
                ans.push_back(abs(nums[i]));
            }
             nums[abs(nums[i]) - 1] *= -1;
        }
        return ans;
    }
};