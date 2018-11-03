/*
BNY Mellon IITK 2018

Given an encoded string and the Huffman codes for each character, print the
decoded string. Huffman codes are provided as an array of strings where the key-
value pair are separated by a tab and appear as an array element. It is ensured
that the key will be a character and value will be a binary string.

average O(n) space and time
Replacing unordered_map with map gives O(n log n) time and O(n) space
*/
#include <vector>
#include <cassert>
#include <iostream>
#include <unordered_map>
using namespace std;

string huffmanDecode(vector<string> codes, string encoded) {
    int n = codes.size();
    unordered_map<string,char> ids;
    for (int i = 0; i < n; i++) {
        char key = codes[i][0];
        string val = codes[i].substr(2);
        ids[val] = key;
    }
    string decoded = "", cur = "";
    for (char c : encoded) {
        cur += c;
        if (ids.find(cur) != ids.end()) {
            decoded += ids[cur];
            cur = "";
        }
    }
    if (cur != "") {
        decoded += ids[cur];
    }
    return decoded;
}

int main() {
    // Driver Program to test above function
    assert(huffmanDecode(
        {"a\t01", "b\t110", "c\t101", "d\t0010", "\n\t1111"},
        "1100010110111101") == "bdb\na");
    return 0;
}