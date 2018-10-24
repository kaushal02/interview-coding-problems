/*
Flipkart IIT Kanpur 2018

Given two vectors of length n representing the x and y 
coordinates of cartesian points, find the minimum possible area 
of a rectangle which can be formed using four distinct points.
If non rectangle can be formed, return -1.

1 <= n <= 1000
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1E15;
int getMinArea(vector<int> x, vector<int> y) {
	map<pair<int,int>, set<int>> m;
	int n = x.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (x[i] == x[j]) {
				m[{min(y[i], y[j]), max(y[i], y[j])}].insert(x[i]);
			}
		}
	}
	
	int ans = INF;
	for (auto &p : m) {
		int a = p.first.second - p.first.first;
		vector<int> xs(p.second.begin(), p.second.end());
		int sz = xs.size();
		for (int i = 1; i < sz; i++) {
			ans = min(ans, a * (xs[i] - xs[i - 1]));
		}
	}
	return (ans < INF ? ans : -1);
}

signed main() {
	cout << getMinArea(
		{1,1,2,2,3,3,4,4},
		{1,3,1,8,1,8,1,3}
	) << '\n';
	return 0;
}