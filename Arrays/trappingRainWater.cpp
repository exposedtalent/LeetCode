// https://leetcode.com/problems/trapping-rain-water/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// This is a better than brute force but not optimal space complexity
// Time Com : O(n)
// Spcce Com : O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()){
            return 0;
        }
        int ans =0;

        int size = height.size();
        vector <int> left(size), right(size);
        left[0] = height[0];
        for(int i =1; i < size; i++){
            left[i] = max(left[i -1], height[i]);
        }
        right[size -1 ] = height[size - 1];
        for(int i = size - 2; i>= 0;i--){
            right[i] = max(right[i+1], height[i]);
        }
        
        for(int i = 0; i < size ; i++){
            ans += min(right[i], left[i]) - height[i];
        }
        return ans;
        
    }
};
// optimal solution using two pointers 
// Time Com : O(n)
// Spcce Com : O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = 0, rightMax = 0;
        int left = 0, right = n -1;
        int ans = 0;
        
        while(left <= right){
            
            if(height[left] <= height[right]){
                
                if(height[left] >= leftMax){
                    leftMax = height[left];
                }
                else{
                    ans += leftMax - height[left];
                }
                left++;
            }
            else{
                
                if(height[right] >= rightMax){
                    rightMax = height[right];
                }
                else{
                    ans += rightMax - height[right];
                }
                right--;
            }
        }
        return ans;
    }
};