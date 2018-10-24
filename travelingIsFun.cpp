/*
Flipkart IIT Kanpur 2018

https://www.hackerrank.com/contests/hack-it-to-win-it-paypal/challenges/q4-traveling-is-fun
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

struct dsu {
	vector<int> par, sz;
	dsu(int n): par(n), sz(n, 1) {
		for (int i = 0; i < n; i++) {
			par[i] = i;
		}
	}
	int root(int a) {
		if (a == par[a]) return a;
		return par[a] = root(par[a]);
	}
	void merge(int a, int b) {
		a = root(a);
		b = root(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
		par[b] = a;
	}
};

vector<int> findReachable(int n, int g, vector<int> from, vector<int> to) {
	dsu d(n);
	for (int k = g + 1; k <= n; k++) {
		for (int x = 2 * k; x <= n; x += k) {
			d.merge(x - 1, x - k - 1);
		}
	}

	int m = from.size();
	vector<int> ans;
	for (int i = 0; i < m; i++) {
		ans.push_back(d.root(from[i] - 1) == d.root(to[i] - 1));
	}
	return ans;
}

signed main() {
	vector<int> from {10, 4, 3, 6};
	vector<int> to {3, 6, 2, 9};
	vector<int> reachable = findReachable(10, 1, from, to);
	for (int i = 0; i < 4; i++) {
		cout << "From " << from[i] << " to " << to[i] << ": ";
		cout << (reachable[i] ? "Possible" : "Not possible") << '\n';
	}
	return 0;
}