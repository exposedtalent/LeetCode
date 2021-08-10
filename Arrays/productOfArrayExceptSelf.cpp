// https://leetcode.com/problems/product-of-array-except-self/

// Brute Force 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n  = nums.size();
        vector<int> left(n), right(n), ans(n);
        
        left[0] = 1;
        for(int i = 1; i < nums.size(); i++){
            left[i] = left[i-1] * nums[i-1];
        }
        right[n-1] = 1;
        for(int i = n -2; i >= 0; i--){
            right[i] = right[i+1] * nums[i+1];
        }
        
        for(int i =0; i < n; i ++){
            ans[i] = left[i] * right[i];
         }
        return ans;

    }
};
// Optimal TC : O(n), SC: O(1) technically still using an array so O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n  = nums.size();
        vector<int>  ans(n);
        
        ans[0] = 1;
        for(int i = 1; i < nums.size(); i++){
            ans[i] = ans[i-1] * nums[i-1];
        }
        int right = 1;
        for(int i = n -1; i >= 0; i--){
            ans[i] = right * ans[i];
            right *= nums[i];
        }
        return ans;

    }
};