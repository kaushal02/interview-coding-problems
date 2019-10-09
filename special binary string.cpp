/*

CITRIX IIT Guwahti 2019

Special binary strings are binary strings with the following two properties:

The number of 0's is equal to the number of 1's.
Every prefix of the binary string has at least as many 1's as 0's.
Given a special string S, a move consists of choosing two consecutive, non-empty, special substrings of S, and swapping them. (Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.)

At the end of any number of moves, what is the lexicographically largest resulting string possible?

Solution :

Since S is special, it must start with 1. If S is a string of 1s followed by 0s, we already have the lexicographically largest string possible.
consider the prefixes of S in increasing length. First few prefixes will be all 1s.
Now we will start having 1s followed by 0s. Call it type X.
As we move further, now we have 1s followed by 0s followed by 1s. Call it type Y.

algo : We will take smallest length prefix of type Y. Understand that it is simply a type X prefix followed by a 1. Our move will be to break the last 1 and attach at the beginning.
Keep doing this and eventually you'll end up with type X string with length equal to that of S.
*/

string makeLargestSpecial(string s) {
    int n = s.size();
    string t = "";
    for (int i = 0; i < n / 2; i++) t += '1';
    for (int i = 0; i < n / 2; i++) t += '0';
    return t;
}
