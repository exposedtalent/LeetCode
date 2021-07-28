// https://leetcode.com/problems/unique-paths/

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<climits>
// Brute Force Method using recursion TC : O(n^2) SC : O(n^2)
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1){
            return 1;
        }
        return uniquePaths(m -1 , n) + uniquePaths(m , n-1);
    }
};

// Using Dynamic Programming to solve TC: O(NXM) SC: O(NXM)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int ans[m][n];
        for(int i = 0 ; i < m ; i ++){
            for(int j = 0; j < n ; j ++){
                if( j == 0 || i == 0){
                    ans[i][j]  = 1;
                }
                
            }
        }
        for(int i = 1 ; i < m ; i ++){
            for(int j = 1; j < n ; j ++){
                ans[i][j] = ans[i -1][j] + ans[i][j-1];
            }
        }
        return ans[m-1][n-1];
    }
};

// Optimal using math TC : O(N - 1) or O(M -1 ) SC : O(1)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m + n -2;
        int r = m -1;
        double res = 1;
        for(int i = 1; i <= r; i++){
            res = res * ( N - r + i) / i;
        }
        return int(res);
    }
    
};


