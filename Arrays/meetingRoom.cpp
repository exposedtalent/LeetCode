// https://leetcode.com/problems/meeting-rooms/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.empty()){
            return true;
        }
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < intervals.size() -1; i++){
            if(intervals[i][1] > intervals[i+1][0]){
                return false;
            }
        }
        return true;
    }
};