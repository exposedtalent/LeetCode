// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Brute force would be 2 loops where one is i and another check all the  other possibilities that can happen if you buy that and comapare the max TC : (n^2) SC: (1)

/*
    Intuition -> 
    Algorithm -> 
    TC : O(n) , SC: O(1)
*/
// Optimal
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit =0;
        for(int i = 0; i < prices.size();i++){
            if(prices[i] < minPrice){
                minPrice = prices[i];
            }
            else if(prices[i] - minPrice > maxProfit){
                maxProfit = prices[i] - minPrice;
            }
        }
        return maxProfit;
    }
};

/*
    Intuition -> 
    Algorithm -> 
    TC : O(n) , SC: O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit =0;
        for(int i =0; i < prices.size(); i++){
            minPrice = min(prices[i], minPrice);
            maxProfit = max(maxProfit, prices[i] - minPrice  );
        }
        return maxProfit;
    }
            
};