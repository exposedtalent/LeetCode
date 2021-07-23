// https://leetcode.com/problems/jewels-and-stones/

#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Solution {
public:
    
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> map(jewels.begin(), jewels.end());
        unordered_map<char, int> map2;
        int count = 0;
        for(char c: stones){
            if(map.find(c) != map.end()){
                count++;
            }
        }
        return count;
        
        
    }
};