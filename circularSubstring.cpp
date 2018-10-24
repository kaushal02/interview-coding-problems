/*
Given a source string and a target string, find the minimum length of a circular
substring of the source string which contains the target string. If no such 
substring exists, return -1. Circular substring means any substring of the
rotated source string.

For e.g. if source string is "shit" then all circular strings will be
{"shit", "hits", "itsh", "tshi"}. String x contains string y if all characters 
appear at least the same number of times in x as it appears in y.

E.g. for source "kecrha" and target "ack", the best possible answer can be for
the circular string "hakecr" where the relevant substring is "akec" containing 
"ack". Hence the final answer is 4

1 <= length of strings <= 100000
O(N + 26) solution
*/

#include <iostream>
using namespace std;

int CircularSubstring(string source, string target) {
    int n = source.size();
    source += source;

    int a[26] = {}, nz = 0;
    for (char c : target) {
        if (not a[c - 'a']++) {
            nz++;
        }
    }

    int min_len = 2 * n;
    for (int i = 0, j = 0; i < 2 * n; i++) {
        if (not --a[source[i] - 'a']) {
            nz--;
        }
        while (a[source[j] - 'a'] < 0) {
            a[source[j++] - 'a']++;
        }
        if (not nz) {
            min_len = min(min_len, i - j + 1);
        }
    }
    return min_len > n ? -1 : min_len;
}

int main() {
    // your code goes here
    cout << CircularSubstring("kecrha", "ack") << '\n';
    return 0;
}