// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Brute Force TC: O(n^3) SC: O(min(n,m))
class Solution {
public:
    bool checkRep(string &s, int start, int end){
        
        vector<char> ch(128);
        
        for(int i  = start; i <= end; i++){
            char c = s[i];
            ch[c]++;
            
            if(ch[c] > 1){
                return false;
            }
        }
        return true;
    }
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        int ans = 0;
        for(int i = 0; i < n; i ++){
            for(int j = i; j < n; j ++){
                if(checkRep(s, i , j)){
                    ans = max(ans, j - i +1);
                }
                
            }
        }
        
        return ans;
    }
    
    
};