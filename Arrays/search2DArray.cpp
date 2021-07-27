// https://leetcode.com/problems/rotate-image/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Brute Force
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n ; i ++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == target){
                    return true;
                }
            }
        }
        return false;
    }
};
// Better solution 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix[0].size();
        int n = matrix.size();
        
        int k = 0;
        int j = m - 1 ;
        while(k < n && j >= 0){
            if(matrix[k][j] == target){
                return true;
            }
            if(matrix[k][j] > target){
                j--;
            }
            else{
                k++;
            }
        }
        return false;
        
    }
};

// Optimal Using binary search TC : O(log(mn)) SC: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo = 0;
        if(!matrix.size()) return false;
        int hi = (matrix.size() * matrix[0].size()) - 1;
        
        while(lo <= hi) {
            int mid = (lo + (hi - lo) / 2);
            if(matrix[mid/matrix[0].size()][mid % matrix[0].size()] == target) {
                return true;
            }
            if(matrix[mid/matrix[0].size()][mid % matrix[0].size()] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return false;
    }
};