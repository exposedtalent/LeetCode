// https://leetcode.com/problems/counting-bits/

#include<iostream>
#include<vector>

// Kinda Brute force 
class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> ans(n);
        ans.push_back(0);
        if(n == 0){
            return ans;
        }
        
        for(int i =1; i <= n; i++){
            
            if(i % 2 == 0){
                ans[i] = ans[i/2];
            }
            else{
                ans[i] = ans[i-1]+1;
            }
        }
        return ans;
    }
};

// Optimal DP solution TC : O(n) , SC: O(n)
class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0){
            return {0};
        }
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++){
            if(i % 2 == 0)
                dp[i] = dp[i/2];
            else
                dp[i] = dp[i-1] +1;
         }
        return dp;
    }
};

