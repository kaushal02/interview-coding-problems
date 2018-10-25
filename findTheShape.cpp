/*
Nutanix IITD 2018

We are given the inorder and postorder traversal of a Binary tree. The data in 
the nodes are alphanumeric characters. Had to classify the tree shape into one 
of the following types:

/ (forward slash) if the shape of tree is like a forward slash
\ (Backward slash) if the shape is like a backward slash
< (less than) if the tree shape is like
> (greater than)
^ (exponent symbol) if the shape of tree is like
# (hash) if none of the above

Below figures are for further clarity (a, b, c represent nodes) :

         a         a               a         a
        /           \             /           \            a
(/)    b      (\)    b      (<)  b      (>)    b    (^)   / \    (#) all other
      /               \           \           /          b   c
     c                 c           c         c
*/
#include <iostream>
#include <algorithm>
using namespace std;

bool check(string s, string t) { // O(n^2)
    // >T .. <T
    for (int i = s.size(); --i; ) {
        string tir(t.substr(0, i));
        reverse(tir.begin(), tir.end());
        if (s.substr(0, i) == tir and s.substr(i) == t.substr(i)) {
            return true;
        }
    }
    return false;
}

string solve() {
    string s, t; cin >> s >> t;
    string sr(s); reverse(sr.begin(), sr.end());
    string tr(t); reverse(tr.begin(), tr.end());
    if (s == t) return "/"; // T .. T
    if (s == tr) return "\\"; // > .. <
    if (check(s, t)) return "<"; // >T .. <T
    if (check(sr, t)) return ">"; // >T .. T<
    if (check(sr, tr)) return "^"; // T> .. T<
    return "#"; // else
}

int main() {
    // your code goes here
    int t; cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}