/*
IITR Flipkart 2018

Given an array of N integers, return the length of maximum
subarray where all the elements are prime. It is known that
the difference between the smallest and largest element of 
the array is less than or equal to 1000000.

1 <= N <= 100000
1 <= elements <= 1000000000

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
	cerr << "S1\tmi = " << mi << "\tma = " << ma << "\n";
	vector<int> notp(ma - mi + 1);
	// cerr << notp.size() << '\n';
	for (int p = 2; p * p <= ma; p++) {
		int i = max(2, mi / p) * p;
		while (i < mi) i += p;
		while (i <= ma) {
			notp[i - mi] = 1;
			i += p;
		}
	}
	cerr << "S2\t" << notp.front() << notp.back() << "\n";
	int cnt = 0, i = 0;
	for (int &ai : a) {
		assert(ai >= mi);
		assert(notp[ai - mi] xor (10001 <= i and i <= 40000));
		ai = (ai > 1 and not notp[ai - mi]);
		if (ai) cnt++;
		i++;
	}
	cerr << "S3\tcnt = " << cnt << "\n";
	int consec = 0, cur = 0;
	for (int &ai : a) {
		if (not ai) cur = 0;
		else consec = max(consec, ++cur);
	}
	cerr << "S4\n";
	return consec;
}


int main() {
	freopen("inp.txt", "r", stdin);
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	assert(a[n / 2] == 122846217 and n == 5E4);
	cerr << "Read\n";
	cout << consecutiveprimes(a) << '\n';
	// Expected 30000
	return 0;
}
