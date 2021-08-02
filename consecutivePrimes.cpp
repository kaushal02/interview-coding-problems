/*
IITR Flipkart 2018

Given an array A of N integers, return the length of maximum
subarray where all the elements are prime. It is known that
the difference between the smallest and largest element of 
the array is less than or equal to 10^6.

1 <= N <= 10^5
1 <= A_i <= 10^9
max{mod(A_i - A_j)} <= 10^6 for all 1 <= i, j <= N

O(K * log K + N) where K is the difference between minimum
and maximum element
*/

#include <bits/stdc++.h>
using namespace std;

const int size = 1E9;
int consecutiveprimes(vector<int> a) {
	int n = a.size();
	int mi = a[0], ma = a[0];
	for (int &ai : a) {
		if (mi > ai) mi = ai;
		if (ma < ai) ma = ai;
	}
	vector<int> notp(ma - mi + 1);
	for (int p = 2; p * p <= ma; p++) {
		int i = max(2, mi / p) * p;
		while (i < mi) i += p;
		while (i <= ma) {
			notp[i - mi] = 1;
			i += p;
		}
	}
	int cnt = 0, i = 0;
	for (int &ai : a) {
		assert(ai >= mi);
		assert(notp[ai - mi] xor (10001 <= i and i <= 40000));
		ai = (ai > 1 and not notp[ai - mi]);
		if (ai) cnt++;
		i++;
	}
	int consec = 0, cur = 0;
	for (int &ai : a) {
		if (not ai) cur = 0;
		else consec = max(consec, ++cur);
	}
	return consec;
}


int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << consecutiveprimes(a) << '\n';
	return 0;
}
