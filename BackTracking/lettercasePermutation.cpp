// https://leetcode.com/problems/letter-case-permutation/

/*
    ■ There are two main cases which needs to be solved recursively:

        ■ The element at the given index is a digit : 

            ■ Append the digit to the end of curr and go to next index(i+1).

                curr.push_back(s[i]);
                solve(curr,s,i+1);
            ■ The element at the given index is an alphabet, this case has two sub cases:

                ■ Append tolower(s[i]) to curr and go to next index (i+1).

                    //sub case 1, considering lower case
                    string c1=curr;
                    c1.push_back(tolower(s[i]));
                    solve(c1,s,i+1);

                ■ Append toupper(s[i]) to curr and go to next index (i+1).

                    //sub case 2, considering upper case
                    string c2=curr;
                    c2.push_back(toupper(s[i]));
                    solve(c2,s,i+1);

            ■ If at any function call, the index = S.length(), then curr string has one of our output, so save it in ans vector,

                // if end of the string is reached
                if(i==s.length()){
                    ans.push_back(curr); // push the current "curr" string to ans
                    return;
                }
    ■ At the end of the recursion return ans.

*/

class Solution {
public:
    vector<string> str;
    void helper(string cur, string s, int i){
        // Base Case 
        if(s.length() == i) {
            str.push_back(cur);
            return;
        }
        // Case when the char at i is a digit
        if(isdigit(s[i])){
            cur.push_back(s[i]);
            helper(cur, s, i+1);
        }
        // Case when the char is a character
        else{
            // Lower case 
            string c1 = cur;
            c1.push_back(tolower(s[i]));
            helper(c1, s, i+1);
            // Upper Case
            string c2 = cur;
            c2.push_back(toupper(s[i]));
            helper(c2, s, i+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        helper("",s, 0);
        return str;
    }
};