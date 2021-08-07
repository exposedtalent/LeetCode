// https://leetcode.com/problems/climbing-stairs/

#include<iostream>
#include<vector>
using namespace std;

// Recursive solution
class Solution {
public:
    int climb(int i, int n){
        if(i > n){
            return 0;
        }
        
        if(i == n){
            return 1;
        }
    
        return climb(i+1,n) + climb(i+2,n);
    }
    int climbStairs(int n) {
        return climb(0, n);
    }
};

