/*

CITRIX IIT Guwahti 2019

Special binary strings are binary strings with the following two properties:

The number of 0's is equal to the number of 1's.
Every prefix of the binary string has at least as many 1's as 0's.
Given a special string S, a move consists of choosing two consecutive, non-empty, 
special substrings of S, and swapping them. (Two strings are consecutive if the last character 
of the first string is exactly one index before the first character of the second string.)

At the end of any number of moves, what is the lexicographically largest resulting string possible?

Solution:
Recursively try to find the lexicographically largest strings and sort them using a comparator function.

*/

    string makeLargestSpecial(string S) {
        int i=0, count=0;
        vector<string> res;
        for(int j=0;j<S.length();j++){
            if(S[j]=='1')
                count++;
            else
                count--;
            if(count==0){
                res.push_back('1' + makeLargestSpecial(S.substr(i+1,j-i-1)) +'0');
                i = j+1;
            }
            
        }
        sort(res.begin(),res.end(),greater<string>());
        
        string r = "";
        for(auto s:res){
            r+=s;
        }
        return r;
    }
