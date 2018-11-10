/*
IITR Flipkart 2018

Given a string s, return a string t satisfying the following:
1. s contains t
2. t is a palindrome
3. t is largest possible
If multiple t exists, return the lexicographically smallest t.

1 <= |s| <= 100000

O(|s| + 26)
*/
string smallestRestrictedPalindrome(string s) {
	int c[26] = {};
	for (char ch : s) c[ch - 'a']++;
	string t = "";
	for (int i = 0; i < 26; i++) {
		for (int j = c[i] >> 1; j--; ) {
			t += (char)('a' + i);
		}
	}
	int fl = 0;
	for (int i = 0; not fl and i < 26; i++) {
		if (c[i] & 1) {
			t += (char)('a' + i);
			fl = 1;
		}
	}
	int n = t.size() - fl;
	for (int i = n; i--; ) {
		t += t[i];
	}
	return t;
}
