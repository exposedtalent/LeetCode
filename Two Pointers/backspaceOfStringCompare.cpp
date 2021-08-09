// https://leetcode.com/problems/backspace-string-compare/

// Using stack TC: O(n), SC : O(n)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1, t1;
        string str, tstr;
        
        for(int i =0; i < s.length(); i++){
            if(s[i] == '#' && !s1.empty()){
                s1.pop();
            }
            else if(s[i] != '#'){
                s1.push(s[i]);
            }
        }
        
        for(int i =0; i < t.length(); i++){
            if(t[i] == '#' && !t1.empty()){
                t1.pop();
            }
            else if(t[i] != '#'){
                t1.push(t[i]);
            }
        }
        
        while(!s1.empty()){
            str.push_back(s1.top()); s1.pop();
        }
        while(!t1.empty()){
            tstr.push_back(t1.top()); t1.pop();
        }
        
        return str == tstr;
    }
};

// Two Pointer approach TC : O(n) , SC : O(1)
// 1. Suppose 2 pointer i & k
// 2 .Start traversing the by first pointer(i) if it is # then decrease the 2nd pointer(k )(k>=0) .And if it is not # then increase the pointer(k) and store the element at k th position.
// S[k]=S[i]
// 3. Same will be done to 2nd string And suppose its 2nd pointer is p
// 4. If k and p are not equal means the string have different length. If same, then compare every element.

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int k = 0, p = 0 ;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '#'){
                k--;
                k = max(0,k);
            }
            else{
                s[k] = s[i];
                k++;
            }
        }
        for(int i = 0; i < t.length(); i++){
            if(t[i] == '#'){
                p--;
                p = max(0,p);
            }
            else{
                t[p] = t[i];
                p++;
            }
        }
        if(k != p){
            return false;
        }
        else{
            for(int i  = 0; i < k; i++){
                if(s[i] != t[i]){
                    return false;
                }
            }
            return true;
        }
        
    }
};