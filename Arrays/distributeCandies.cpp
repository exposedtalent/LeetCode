// https://leetcode.com/problems/distribute-candies/

#include<iostream>
#include<vector>
#include<unordered_set>

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> cset (candyType.begin(), candyType.end());
        return min(cset.size(), candyType.size()/2);
    }
};