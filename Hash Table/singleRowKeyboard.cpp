// https://leetcode.com/problems/single-row-keyboard/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        
        unordered_map <char, int> map;
        for(int i = 0; i < keyboard.length(); i++){
            map[keyboard[i]] = i;
        }
        int time = map[word[0]];
        for(int i = 0, j = 1; j < word.length(); i++, j++ ){
            time += abs(map[word[i]] - map[word[j]]);
        }
        return time;
    }
};