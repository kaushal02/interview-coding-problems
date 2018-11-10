/*
IITR Razorpay 2018

Consider a prison gate having N horizontal rods and M vertical rods.
You are also provided with two vectors hor and ver containing the 
row number of missing horizontal rods and vertical rods respectively.
Return the area of biggest hole in the prison gate.

1 <= N, M <= 1000000
1 <= hor[i] <= N
1 <= ver[i] <= M
All the elements of a vector are distinct

O(N + M)

SKIPPING... O(AlogA + BlogB) where A = hor.size() and B = ver.size()
*/
#include<bits/stdc++.h>
using namespace std;

long int prison(int n, int m, vector<int> hor, vector<int> ver) {
	vector<bool> xs(n + 1), ys(m + 1);
	for (int h : hor) xs[h] = true;
	for (int v : ver) ys[v] = true;
	int xm = 0, ym = 0;
	for (int i = 1, j = 0; i <= n; i++) {
		if (not xs[i]) j = 0;
		else xm = max(xm, ++j);
	}
	for (int i = 1, j = 0; i <= m; i++) {
		if (not ys[i]) j = 0;
		else ym = max(ym, ++j);
	}
	return (long int)(xm + 1) * (ym + 1);
}

int main() {
	cout << prison(10, 10, {}, {});
	return 0;
}
