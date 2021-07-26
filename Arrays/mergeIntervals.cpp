// https://leetcode.com/problems/merge-intervals/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    
public:
    static bool comparator( vector<int>& a, vector<int>& b )
    {
        return a[0] < b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        
        if(intervals.empty()){
            return res;
        }
        if(intervals.size() == 1){
            res.push_back(intervals[0]);
            return res;
        }
        sort( intervals.begin(), intervals.end(), comparator);
        res.push_back( intervals[0] );
        int i =0;
        while (i < intervals.size()){
            vector<int>& last = res.back();
            
            if(last[1] < intervals[i][0]){
                res.push_back(intervals[i]);
            }
            else{
                last[1] = max(last[1], intervals[i][1]);
            }
            i++;
        }
        return res;
        
    }
};


// Optimal
class Solution {
    
public:
   
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        
        if(intervals.empty()){
            return res;
        }
        if(intervals.size() == 1){
            res.push_back(intervals[0]);
            return res;
        }
        sort( intervals.begin(), intervals.end());
        
        vector<int> in = intervals[0];
        
        for(auto it: intervals){
            if(it[0] <= in[1]){
                in[1]= max(it[1], in[1]);
            }
            else{
                res.push_back(in);
                in = it;
            }
        }
        res.push_back(in);
        return res;
        
    }
};