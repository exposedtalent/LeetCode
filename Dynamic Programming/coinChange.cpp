// https://leetcode.com/problems/coin-change/

// Recursion but this solution does not work fully 
class Solution {
public:
    
    int coinChange(vector<int>& coins, int a) {
        if(a == 0) return 0;
        if(a < 0) return -1;
        
        int minC = -1;
        
        for(int i =0; i <coins.size(); i++)
        {
            int coin = coinChange(coins,a-coins[i]);
            if(coin>=0) minC = minC < 0 ? coin : min(minC,coin);
        }
        int m  = -1;
        return minC < 0 ? -1 : 1 + minC;
    }
};

// Using DP
class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0]=0;
        for(int i=0;i<=amount;i++)
            for(int c:coins) 
                if(c<=i) dp[i] = min(dp[i],dp[i-c]+1);
        return dp[amount]>amount? -1 : dp[amount];    
    }
};

// 
