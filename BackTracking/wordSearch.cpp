// https://leetcode.com/problems/word-search/submissions/

#include<iostream>
#include<vector>

class Solution {
public:
    
    bool helper(vector<vector<char>>& board, int x , int y, string word, int ind){
        if(word.length() == ind) return true;
        
        if(x  < 0 || y < 0 || x >= board.size() || y>= board[0].size() || board[x][y] == '.' || board[x][y] != word[ind] ) {
            return false;
        }
        
        char c = board[x][y];
        board[x][y] = '.';
        bool result = helper(board, x+1, y, word, ind+1) ||
                      helper(board, x-1, y, word, ind+1) || 
                      helper(board, x, y+1, word, ind+1) ||
                      helper(board, x, y-1, word, ind+1);
        board[x][y] = c;
        return result;
        
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i =0; i < board.size(); i++){
            for(int j = 0; j< board[0].size(); j++){
                if(helper(board, i ,j , word, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};