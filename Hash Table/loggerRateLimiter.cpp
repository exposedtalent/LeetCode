
// https://leetcode.com/problems/logger-rate-limiter/
#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Logger {
public:
    unordered_map<string,int> hash;

    /** Initialize your data structure here. */
    Logger() {}
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {

        if (hash.find(message)!=hash.end()){
            if (timestamp<10+hash[message]) return false;
            else {
                hash[message] = timestamp;
                return true;
            }
        }
        else {
            hash[message] = timestamp;
            return true;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */